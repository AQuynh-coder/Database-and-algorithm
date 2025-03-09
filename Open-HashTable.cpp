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

//Tạo cấu trúc Node Struct
struct Node {
    int Number; //Số nhập vào
    Node *next; //Con trỏ liên kết
};

//Hàm băm số nhập vào
int Hash_Function(int Number) {
    return Number % Hash_Size; //Key sau khi băm
}

//Hàm chèn số vào bảng băm
void Insert_Number(Node *Hash_Table[], int Number) {
    Node *Temp = new Node; //Tạo Node tạm thời
    Temp->Number = Number; 
    Temp->next = NULL; //Khởi tạo Node tạm thời
    int Key = Hash_Function(Number);
    if (Hash_Table[Key] == NULL) { //Nếu Key không va chạm thì gán trực tiếp vào bảng băm
        Hash_Table[Key] = Temp; 
    } else { //Nếu Key va chạm thì gán vào đầu danh sách liên kết (bảng băm)
        Temp->next = Hash_Table[Key]; //Trỏ vào Node phía sau
        Hash_Table[Key] = Temp; //Gán Node Temp vào bảng băm
    }
}

//Hàm tìm kiếm số trong bảng băm
bool Search(Node *Hash_Table[], int Number) {
    int Key = Hash_Function(Number); //Băm số cần tìm
    Node *Temp = Hash_Table[Key]; //Trỏ vào danh sách liên kết tại Key (bảng băm)
    while (Temp != NULL) { //Nếu tìm được Key thì thực hiện
        if (Temp->Number == Number) { //Tìm được đúng số thì trả về True
            return true;
        }
        Temp = Temp->next; //Không tìm được thì duyệt tiếp trong danh sách cho đến khi chạy đến cuối
    }
    return false; //Không tìm được thì trả về False
}

//Hàm xóa số trong bảng băm
void Delete(Node *Hash_Table[], int Number) {
    int Key = Hash_Function(Number); // Băm số cần xóa
    Node *Temp = Hash_Table[Key]; // Trỏ vào danh sách liên kết tại Key (bảng băm)
    Node *Prev = NULL; // Con trỏ để giữ Node trước đó đã duyệt qua
    while (Temp != NULL) { // Nếu tìm được Key thì thực hiện
        if (Temp->Number == Number) { // Tìm được đúng số thì xóa số đó
            if (Prev == NULL) { // Nếu số cần xóa là số đầu tiên xóa trong danh sách liên kết
                Hash_Table[Key] = Temp->next; // Kéo Node tiếp theo lên đầu danh sách liên kết
            } else { // Nếu số cần xóa không phải là số đầu tiên
                Prev->next = Temp->next; // Trỏ Node trước đó vào Node tiếp theo của Node cần xóa
            }
            Node *NodeToDelete = Temp; // Lưu Node cần xóa
            Temp = Temp->next; // Di chuyển Temp đến Node tiếp theo
            delete NodeToDelete; // Giải phóng bộ nhớ của Node đã xóa
        } else {
            // Cập nhật Prev để giữ lại Node vừa duyệt và Temp để tiến về sau
            Prev = Temp; // Cập nhật Prev để trỏ đến Node hiện tại
            Temp = Temp->next; // Di chuyển Temp đến Node tiếp theo
        }
    }
}

//Hàm nhập số
void Input(int &Number) {
    cout << "Nhap so: ";
    cin >> Number;
}

//Hàm xuất bảng băm
void Output(Node *Hash_Table[]) {
    for (int i = 0; i < Hash_Size; i++) {
        Node *Temp = Hash_Table[i];
        cout << "Key " << i << ": ";
        while (Temp != NULL) {
            cout << Temp->Number << " ";
            Temp = Temp->next;
        }
        cout << endl;
    }
}

int main(){
    Node *Hash_Table[Hash_Size] = {NULL}; //Khởi tạo bảng băm
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