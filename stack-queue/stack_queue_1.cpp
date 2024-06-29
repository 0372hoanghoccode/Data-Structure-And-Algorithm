#include <iostream>
#define MAX 10 // Định nghĩa kích thước tối đa của hàng đợi mảng
using namespace std;

// Cấu trúc Node để biểu diễn một nút trong danh sách liên kết
struct Node {
    int infor; // Giá trị lưu trữ trong nút
    Node *pNext; // Con trỏ tới nút tiếp theo
};

// Cấu trúc List để biểu diễn hàng đợi sử dụng danh sách liên kết
struct List {
    Node *pHead; // Con trỏ tới nút đầu của danh sách
    Node *pTail; // Con trỏ tới nút cuối của danh sách
};

// Cấu trúc QueueA để biểu diễn hàng đợi sử dụng mảng
struct QueueA {
    int a[MAX]; // Mảng lưu trữ các phần tử của hàng đợi
    int Front;  // Chỉ số đầu của hàng đợi
    int Rear;   // Chỉ số cuối của hàng đợi
};

// Khai báo các hàm
void CreateQueue(QueueA &queue);
void init(List &);
Node *CreateNode(int x);
void EnQueue(List &queue, int x);
int DeQueue(List &queue, int &x);
int DeQueue(QueueA &queue, int &x);
int EnQueue(QueueA &queue, int x);
void output(List queue);
void output(QueueA queue);
bool isEmpty(List &queue);
bool isEmpty(QueueA queue);
int demSoPT(QueueA queue);
int demSoPT(List queue);
void deleteQueue(List &queue);
void deleteQueue(QueueA &queue);
int luaChonMenu();
int ChooseAorL();
void QueueList(List &queue);
void QueueArr(QueueA &queue);

// Hàm chính của chương trình
int main() {
    List queueL; // Khởi tạo hàng đợi kiểu danh sách liên kết
    QueueA queueA; // Khởi tạo hàng đợi kiểu mảng
    bool flag = true; // Biến điều khiển vòng lặp
    int chosen; // Biến lưu trữ lựa chọn của người dùng

    while (flag != false) {
        chosen = ChooseAorL(); // Gọi hàm chọn loại hàng đợi
        switch (chosen) {
            case 1:
                QueueArr(queueA); // Làm việc với hàng đợi kiểu mảng
                break;
            case 2:
                QueueList(queueL); // Làm việc với hàng đợi kiểu danh sách liên kết
                break;
            case 0:
                cout << "BYE! \n"; // Thoát chương trình
                flag = false;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai: ";
                break;
        }
    }
    system("pause");
    return 0;
}

// Hàm làm việc với hàng đợi kiểu mảng
void QueueArr(QueueA &queue) {
    CreateQueue(queue); // Tạo hàng đợi mới
    cout << "BAN DANG LAM THAO TAC VOI QUEUE LA MANG";
    int lua_chon;
    bool flag = true;
    while (flag != false) {
        int x;
        lua_chon = luaChonMenu(); // Hiển thị menu lựa chọn
        switch (lua_chon) {
            case 1:
                cout << "Nhap gia tri can them vao queue: ";
                cin >> x;
                EnQueue(queue, x); // Thêm phần tử vào hàng đợi
                cout << "Cac phan tu cua Queue sau khi EnQueue: ";
                output(queue); // Hiển thị hàng đợi
                break;
            case 2:
                if (DeQueue(queue, x)) { // Lấy phần tử ra khỏi hàng đợi
                    cout << "Gia tri lay duoc khi dequeue la: " << x << endl;
                    cout << "Cac phan tu cua Queue sau khi DeQueue: ";
                    if (!isEmpty(queue)) {
                        output(queue); // Hiển thị hàng đợi sau khi lấy phần tử ra
                    }
                }
                break;
            case 3:
                if (isEmpty(queue)) {
                    cout << "Queue rong!\n"; // Kiểm tra hàng đợi có rỗng hay không
                } else {
                    cout << "Queue co phan tu!\n";
                }
                break;
            case 4:
                cout << "So luong phan tu trong queue: " << demSoPT(queue); // Đếm số phần tử trong hàng đợi
                break;
            case 5:
                deleteQueue(queue); // Xóa hàng đợi
                cout << "Queue is deleted!";
                break;
            case 0:
                flag = false; // Thoát vòng lặp
                break;
            default:
                cout << "Lua chon khong dung, vui long nhap lai.\n";
                cin >> lua_chon;
                break;
        }
    }
}

// Hàm làm việc với hàng đợi kiểu danh sách liên kết
void QueueList(List &queue) {
    cout << "BAN DANG LAM THAO TAC VOI QUEUE LA LIST";
    init(queue); // Khởi tạo hàng đợi kiểu danh sách liên kết
    int lua_chon;
    bool flag = true;
    while (flag != false) {
        int x;
        lua_chon = luaChonMenu(); // Hiển thị menu lựa chọn
        switch (lua_chon) {
            case 1:
                cout << "Nhap gia tri can them vao queue: ";
                cin >> x;
                EnQueue(queue, x); // Thêm phần tử vào hàng đợi
                cout << "Cac phan tu cua Queue sau khi EnQueue: ";
                output(queue); // Hiển thị hàng đợi
                break;
            case 2:
                if (DeQueue(queue, x)) { // Lấy phần tử ra khỏi hàng đợi
                    cout << "Gia tri lay duoc khi dequeue la: " << x << endl;
                    cout << "Cac phan tu cua Queue sau khi DeQueue: ";
                    if (!isEmpty(queue)) {
                        output(queue); // Hiển thị hàng đợi sau khi lấy phần tử ra
                    }
                }
                break;
            case 3:
                if (isEmpty(queue)) {
                    cout << "Queue rong!\n"; // Kiểm tra hàng đợi có rỗng hay không
                } else {
                    cout << "Queue co phan tu!\n";
                }
                break;
            case 4:
                cout << "So luong phan tu trong queue: " << demSoPT(queue); // Đếm số phần tử trong hàng đợi
                break;
            case 5:
                deleteQueue(queue); // Xóa hàng đợi
                cout << "Queue is deleted!";
                break;
            case 0:
                flag = false; // Thoát vòng lặp
                break;
            default:
                cout << "Lua chon khong dung, vui long nhap lai.\n";
                cin >> lua_chon;
                break;
        }
    }
}

// Hàm chọn loại hàng đợi
int ChooseAorL() {
    int chosen;
    cout << "\n \n ================================ \n";
    cout << "\n Ban muon lam viec voi MANG hay DSLK ? ";
    cout << "\n 1. MANG ";
    cout << "\n 2. DSLK ";
    cout << "\n 0. Thoat chuong trinh ";
    cout << "\nMoi ban nhap thao tac can thuc hien: ";
    cin >> chosen;
    return chosen;
}

// Hàm hiển thị menu lựa chọn
int luaChonMenu() {
    int lua_chon;
    cout << "\n \n ================================ \n";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n1. Enqueue ";
    cout << "\n2. Dequeue ";
    cout << "\n3. Kiem tra Queue co rong hay khong";
    cout << "\n4. Dem so phan tu trong Queue";
    cout << "\n5. Xoa cac phan tu trong Queue";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon;
    return lua_chon;
}

// Hàm tạo hàng đợi kiểu mảng
void CreateQueue(QueueA &queue) {
    queue.Front = -1;
    queue.Rear = -1;
}

// Hàm khởi tạo hàng đợi kiểu danh sách liên kết
void init(List &queue) {
    queue.pHead = queue.pTail = NULL;
}

// Hàm xóa hàng đợi kiểu danh sách liên kết
void deleteQueue(List &queue) {
    Node *p = queue.pHead;
    while (p != NULL) {
        Node *temp = p;
        p = p->pNext;
        delete temp;
        temp = NULL;
    }
    queue.pHead = queue.pTail = NULL;
}

// Hàm xóa hàng đợi kiểu mảng
void deleteQueue(QueueA &queue) {
    queue.Front = -1;
    queue.Rear = -1;
}

// Hàm tạo một nút mới trong danh sách liên kết
Node *CreateNode(int x) {
    Node *node = new Node;
    if (node == NULL) {
        return NULL;
    }
    node->infor = x;
    node->pNext = NULL;
    return node;
}

// Hàm thêm phần tử vào hàng đợi kiểu danh sách liên kết
void EnQueue(List &queue, int x) {
    Node *node = CreateNode(x);
    if (queue.pHead == NULL) {
        queue.pHead = queue.pTail = node;
    } else {
        queue.pTail->pNext = node;
        queue.pTail = node;
    }
}

// Hàm thêm phần tử vào hàng đợi kiểu mảng
int EnQueue(QueueA &queue, int x) {
    if (queue.Rear - queue.Front + 1 == MAX) {
        cout << "Queue is full!" << endl;
        return 0;
    } else {
        if (isEmpty(queue)) { // Nếu hàng đợi rỗng
            queue.Front = 0;
        }
        if (queue.Rear == MAX - 1) {
            int f = queue.Front;
            int r = queue.Rear;
            for (int i = f; i <= r; i++) {
                queue.a[i - f] = queue.a[i];
            }
            queue.Front = 0;
            queue.Rear = r - f;
        }
        queue.Rear++;
        queue.a[queue.Rear] = x;
    }
    return 1;
}

// Hàm kiểm tra hàng đợi kiểu danh sách liên kết có rỗng hay không
bool isEmpty(List &queue) {
    return queue.pHead == NULL;
}

// Hàm kiểm tra hàng đợi kiểu mảng có rỗng hay không
bool isEmpty(QueueA queue) {
    return queue.Front == -1;
}

// Hàm lấy phần tử ra khỏi hàng đợi kiểu mảng
int DeQueue(QueueA &queue, int &x) {
    if (!isEmpty(queue)) {
        x = queue.a[queue.Front];
        queue.Front++;
        if (queue.Front > queue.Rear) { // Trường hợp chỉ có một phần tử
            queue.Front = -1;
            queue.Rear = -1;
        }
        return 1;
    } else {
        cout << "QueueA rong";
        return 0;
    }
}

// Hàm lấy phần tử ra khỏi hàng đợi kiểu danh sách liên kết
int DeQueue(List &queue, int &x) {
    if (!isEmpty(queue)) {
        Node *p = queue.pHead;
        x = p->infor;
        queue.pHead = p->pNext;
        if (queue.pHead == NULL) {
            queue.pTail = NULL;
        }
        delete p;
        p = NULL;
        return 1;
    } else {
        cout << "Queue is empty!";
    }
    return 0;
}

// Hàm đếm số phần tử trong hàng đợi kiểu mảng
int demSoPT(QueueA queue) {
    if (queue.Front == -1) {
        return 0;
    }
    return queue.Rear - queue.Front + 1;
}

// Hàm đếm số phần tử trong hàng đợi kiểu danh sách liên kết
int demSoPT(List queue) {
    int dem = 0;
    Node *p = queue.pHead;
    while (p != NULL) {
        dem++;
        p = p->pNext;
    }
    return dem;
}

// Hàm hiển thị các phần tử trong hàng đợi kiểu mảng
void output(QueueA queue) {
    for (int i = queue.Front; i <= queue.Rear; i++) {
        cout << queue.a[i] << " ";
    }
    cout << endl;
}

// Hàm hiển thị các phần tử trong hàng đợi kiểu danh sách liên kết
void output(List queue) {
    Node *p = queue.pHead;
    while (p != NULL) {
        cout << p->infor << " ";
        p = p->pNext;
    }
    cout << endl;
}
