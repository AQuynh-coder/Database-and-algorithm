#include <iostream>   // Thư viện để nhập/xuất dữ liệu (cin, cout)
#include <algorithm>  // Thư viện cung cấp các thuật toán như max
#include <string>     // Thư viện cung cấp các hàm xử lý chuỗi
#include <vector>     // Thư viện cung cấp cấu trúc dữ liệu vector, sử dụng cho vẽ cây

using namespace std; // Sử dụng không gian tên chuẩn

// Cấu trúc Node
struct Node {
    int data; // Dữ liệu của nút
    Node *left = nullptr; // Nhánh trái
    Node *right = nullptr; // Nhánh phải

    Node(int val) : data(val) {} // Nhận giá trị cho thành viên data trong Node khi khởi tạo, rút gọn cú pháp
};

// Hàm chèn nút vào cây
Node *insert(Node *node, int val) { // *node: con trỏ trỏ đến nút hiện tại, val: giá trị cần chèn
    // Tạo một nút mới nếu cây rỗng với data = val
    if (!node) // Nếu node = nullptr
        return new Node(val);  // data = val
    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại, chèn vào nhánh trái
    if (val < node->data)
        node->left = insert(node->left, val);
    // Ngược lại, chèn vào nhánh phải
    else
        node->right = insert(node->right, val);
    return node;
}

// Hàm tính chiều cao của cây
int height(Node *node) {
    if (!node)
        return 0;
    // Chiều cao của cây bằng 1 cộng với chiều cao lớn nhất giữa nhánh trái và nhánh phải (là số nút từ gốc đến lá dài nhất)
    return 1 + max(height(node->left), height(node->right));
}

// ******************   Hai hàm chính để vẽ cây   ******************
// Hàm vẽ từng nút và liên kết
void drawNode(vector<string> &output, vector<string> &linkAbove, Node *node, int level, int p, char linkChar) {
    if (!node)
        return;

    p = max(p, 0);

    // Vẽ nhánh trái
    if (node->left) {
        drawNode(output, linkAbove, node->left, level + 1, p - to_string(node->left->data).size() - 2, '/');
        p = max(p, (int)output[level + 1].size());
    }

    // Vẽ nút hiện tại
    int space = p - output[level].size();
    if (space > 0)
        output[level] += string(space, ' ');
    output[level] += ' ' + to_string(node->data) + ' ';

    if (linkChar == '/')
        p = output[level].size() - 1;
    space = p - linkAbove[level].size();
    if (space > 0)
        linkAbove[level] += string(space, ' ');
    linkAbove[level] += linkChar;

    // Vẽ nhánh phải
    p = output[level].size();
    drawNode(output, linkAbove, node->right, level + 1, p, '\\');
}

// Hàm vẽ cây
void draw(Node *root) {
    int h = height(root);
    vector<string> output(h), linkAbove(h);
    drawNode(output, linkAbove, root, 0, 0, ' ');

    for (int i = 0; i < h; i++) {
        if (i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
}
// ******************   Hai hàm chính để vẽ cây   ******************

int main() {
    Node *root = nullptr;

/*  Test chương trình
    // Mảng vector giá trị cần chèn vào cây
    vector<int> values = {5, 7, 3, 9, 1, 2, 8};

    // Chèn lần lượt các giá trị vào cây bằng vòng lặp phạm vi của mảng vector values
    for (int val : values) {
        root = insert(root, val);
    } */

    // Vẽ cây
    draw(root);

    return 0;
}