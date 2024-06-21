#include <iostream>
using namespace std;

// Cấu trúc của một nút trong danh sách liên kết
struct Node {
    int infor;    // Giá trị của nút
    Node *pNext;  // Con trỏ trỏ tới nút tiếp theo
};

// Cấu trúc của danh sách liên kết
struct List {
    Node *pHead;  // Con trỏ trỏ tới nút đầu tiên
    Node *pTail;  // Con trỏ trỏ tới nút cuối cùng
};

// Khởi tạo một nút mới với giá trị x
Node *createNode(int x);
// Thêm một nút vào đầu danh sách
void push(List &list, Node *node);
// Lấy và xóa một nút từ đầu danh sách, trả về giá trị của nút
int pop(List &list, int &x);
// Khởi tạo danh sách rỗng
void init(List &l);
// Xuất danh sách ra màn hình
void Xuat(List list);
// Chuyển số thập phân n sang nhị phân và lưu vào danh sách
void ChuyenNhiPhan(int n, List &list);
// Kiểm tra xem danh sách có rỗng hay không
bool isEmpty(List list);

int main() {
    List list;
    init(list);  // Khởi tạo danh sách rỗng
    cout << "Nhap so can chuyen tu co so 10 sang co so 2: ";
    int n;
    cin >> n;  // Nhập số thập phân từ bàn phím
    ChuyenNhiPhan(n, list);  // Chuyển số thập phân sang nhị phân và lưu vào danh sách
    cout << endl;
    while (!isEmpty(list)) {  // Khi danh sách không rỗng
        int x;
        pop(list, x);  // Lấy giá trị từ đầu danh sách
        cout << x << " ";  // Xuất giá trị ra màn hình
    }
    return 0;
}

// Hàm tạo một nút mới với giá trị x
Node *createNode(int x) {
    Node *node = new Node;  // Cấp phát bộ nhớ cho nút mới
    if (node == NULL) {
        return NULL;  // Nếu không cấp phát được bộ nhớ, trả về NULL
    }
    node->infor = x;  // Gán giá trị cho nút
    node->pNext = NULL;  // Nút mới chưa liên kết với nút nào
    return node;
}

// Hàm thêm một nút vào đầu danh sách
void push(List &list, Node *node) {
    if (list.pHead == NULL) {  // Nếu danh sách rỗng
        list.pHead = list.pTail = node;  // Nút mới là cả đầu và cuối danh sách
        return;
    }
    node->pNext = list.pHead;  // Liên kết nút mới với đầu danh sách hiện tại
    list.pHead = node;  // Cập nhật đầu danh sách là nút mới
}

// Hàm lấy và xóa một nút từ đầu danh sách, trả về giá trị của nút
int pop(List &list, int &x) {
    if (list.pHead == NULL) {  // Nếu danh sách rỗng
        return 0;  // Trả về 0 (không thành công)
    }
    Node *p = list.pHead;  // Lấy nút đầu tiên
    x = p->infor;  // Lấy giá trị của nút đầu tiên
    list.pHead = p->pNext;  // Cập nhật đầu danh sách là nút tiếp theo
    if (list.pHead == NULL) {  // Nếu danh sách giờ đã rỗng
        list.pTail = NULL;  // Cập nhật cuối danh sách là NULL
    }
    delete p;  // Giải phóng bộ nhớ của nút đầu tiên
    return 1;  // Trả về 1 (thành công)
}

// Hàm khởi tạo danh sách rỗng
void init(List &l) {
    l.pHead = l.pTail = NULL;  // Cả đầu và cuối danh sách đều là NULL
}

// Hàm xuất danh sách ra màn hình
void Xuat(List list) {
    Node *p = list.pHead;  // Bắt đầu từ đầu danh sách
    while (p != NULL) {  // Duyệt qua toàn bộ danh sách
        cout << p->infor << " ";  // Xuất giá trị của nút ra màn hình
        p = p->pNext;  // Chuyển tới nút tiếp theo
    }
}

// Hàm chuyển số thập phân n sang nhị phân và lưu vào danh sách
void ChuyenNhiPhan(int n, List &list) {
    if (n == 0) {
        push(list, createNode(0));  // Nếu n là 0, thêm nút có giá trị 0 vào danh sách
    }
    while (n != 0) {
        Node *p = createNode(n % 2);  // Tạo nút mới với giá trị phần dư của n chia 2
        push(list, p);  // Thêm nút mới vào đầu danh sách
        n /= 2;  // Cập nhật n là thương của n chia 2
    }
}

// Hàm kiểm tra danh sách có rỗng hay không
bool isEmpty(List list) {
    return list.pHead == NULL;  // Nếu đầu danh sách là NULL thì danh sách rỗng
}
