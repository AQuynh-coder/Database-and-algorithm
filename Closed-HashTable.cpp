/*Creator: Nguyễn A Quỳnh ĐHCNTT24B-IT
- Mô tả chương trình: Băm số nhập vào và lưu vào bảng băm có giới hạn kích thước 10 Key.
- Nút chức năng: 
+ 1.Thêm số vào danh sách liên kết
+ 2.Tìm kiếm số đã lưu vào danh sách liên kết
+ 3.Xóa số đã lưu vào danh sách liên kết
+ 4.Kết thúc chương trình*/

#include<iostream>
using namespace std;
const int Hash_Size = 10; //Kích thước bảng băm

//Hàm băm số nhập vào
int Hash_Function(int Number) {
    return Number % Hash_Size; //Key sau khi băm
}

//Hàm chèn số vào bảng băm
void Insert_Number(int Hash_Table[], int Number) {
    int Key = Hash_Function(Number); //Key sau khi băm
    int originalKey = Key;
    while (Hash_Table[Key] != 0) {
        Key = (Key + 1) % Hash_Size;
        if (Key == originalKey) {
            cout << "Bang bam day. Khong the chen so " << Number << endl;
            return;
        }
    }
    Hash_Table[Key] = Number; //Key trống thì thêm trực tiếp vào
}

//Hàm tìm kiếm số trong bảng băm
bool Search(int Hash_Table[], int Number) {
    int Key = Hash_Function(Number); //Key sau khi băm
    int originalKey = Key;
    while (Hash_Table[Key] != 0) {
        if (Hash_Table[Key] == Number) {
            return true;
        }
        Key = (Key + 1) % Hash_Size;
        if (Key == originalKey) {
            break;
        }
    }
    return false;
}

//Hàm xóa số trong bảng băm
void Delete(int Hash_Table[], int Number) {
    int Key = Hash_Function(Number); //Key sau khi băm
    int originalKey = Key;
    while (Hash_Table[Key] != 0) {
        if (Hash_Table[Key] == Number) {
            Hash_Table[Key] = 0;
            return;
        }
        Key = (Key + 1) % Hash_Size; //Duyệt tiếp theo
        if (Key == originalKey) { //Kiểm tra đã duyệt hết bảng băm chưa
            break;
        }
    }
    cout << "Khong tim thay so " << Number << " de xoa" << endl;
}

//Hàm nhập số
void Input(int &Number) {
    cout << "Nhap so: ";
    cin >> Number;
    if (Number < 0) {
        cout << "So khong hop le. Vui long nhap lai." << endl;
        Input(Number);
    }
} 

//Hàm xuất bảng băm
void Output(int Hash_Table[]) {
    cout << "Bang bam: " << endl;
    for (int i = 0; i < Hash_Size; i++) {
        cout << "Key " << i << ": " << Hash_Table[i] << endl;
    }
}

int main(){
    int Hash_Table[Hash_Size] = {0}; //Khởi tạo bảng băm
    int Number;

    //Chỉnh sửa bảng băm (Thêm, xóa, tìm kiếm)
    int Choice;
    while (true) {
        cout << "Chon chuc nang: " << endl;
        cout << "1. Them so vao bang bam" << endl;
        cout << "2. Tim kiem so trong bang bam" << endl;
        cout << "3. Xoa so trong bang bam" << endl;
        cout << "4. Thoat" << endl;
        cin >> Choice;
        switch (Choice) {
            case 1:
                Input(Number);
                Insert_Number(Hash_Table, Number);
                Output(Hash_Table);
                break;
            case 2:
                Input(Number);
                if (Search(Hash_Table, Number)) {
                    cout << "Tim thay so " << Number << endl;
                } else {
                    cout << "Khong tim thay so " << Number << endl;
                }
                break;
            case 3:
                Input(Number);
                Delete(Hash_Table, Number);
                Output(Hash_Table);
                break;
            case 4:
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    }
    return 0;
}