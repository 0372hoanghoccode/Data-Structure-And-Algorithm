#include <iostream>
using namespace std;

// Cấu trúc khách hàng
struct Customer {
    string name;       // Tên khách hàng
    int seatNumber;    // Số ghế của khách hàng
    Customer *pNext;   // Con trỏ tới khách hàng tiếp theo trong danh sách
};

// Cấu trúc danh sách khách hàng
struct ListCustomer {
    Customer *pHead;   // Con trỏ tới khách hàng đầu tiên trong danh sách
    Customer *pTail;   // Con trỏ tới khách hàng cuối cùng trong danh sách
};

// Cấu trúc ghế
struct Seat {
    int number;       // Số ghế
    Seat *pNext;      // Con trỏ tới ghế tiếp theo trong danh sách
};

// Cấu trúc danh sách ghế
struct ListSeat {
    int quantity;     // Số lượng ghế
    Seat *pHead;      // Con trỏ tới ghế đầu tiên trong danh sách
    Seat *pTail;      // Con trỏ tới ghế cuối cùng trong danh sách
};

// Cấu trúc số thứ tự (STT)
struct SoThuTu {
    int stt;           // Số thứ tự
    SoThuTu *pNext;    // Con trỏ tới STT tiếp theo trong danh sách
};

// Cấu trúc danh sách số thứ tự
struct List {
    SoThuTu *pHead;    // Con trỏ tới STT đầu tiên trong danh sách
    SoThuTu *pTail;    // Con trỏ tới STT cuối cùng trong danh sách
};

// Các hàm xử lý

int luaChonMenu();

// A. Danh sách ghế
void addSeat(ListSeat &listSeat, Seat *seat);
void init(ListSeat &listSeat);
Seat *CreateSeat(int x);
void output(ListSeat listSeat);
int demSoPT(ListSeat listSeat);
void deleteSeat(ListSeat &listSeat);
bool deleteX(ListSeat &listSeat, int x);
bool deleteAfter(ListSeat &listSeat, Seat *seat);
bool isEmpty(ListSeat listSeat);

// B. Hàng đợi chứa số thứ tự của khách
void init(List &queue);
SoThuTu *CreateSoThuTu(int x);
void EnQueue(List &queue);
int DeQueue(List &queue);
void output(List queue);
bool isEmpty(List queue);

// C. Danh sách chứa thông tin khách đã mua vé
void init(ListCustomer &listCustomer);
Customer *CreateCustomer();
void addCustomer(ListCustomer &listCustomer, Customer *cust);
void output(ListCustomer listCustomer);
void deleteCustomer(ListCustomer &listCustomer);
bool deleteX(ListCustomer &listCustomer, int x);
bool deleteAfter(ListCustomer &listCustomer, Customer *cust);

int main() {
    // Khởi tạo danh sách ghế, hàng đợi và danh sách khách hàng
    ListSeat listSeat;
    List queue;
    ListCustomer listCustomer;
    init(queue);
    init(listSeat);
    init(listCustomer);

    int lua_chon;
    bool flag = true;
    while (flag) {
        lua_chon = luaChonMenu();
        switch (lua_chon) {
            case 1: {
                // Lấy số xếp hàng
                EnQueue(queue);
                output(queue);
                cout << "\n";
                break;
            }
            case 2: {
                // Mua vé
                if (!isEmpty(queue)) {
                    if (!isEmpty(listSeat)) {
                        DeQueue(queue);
                        cout << "Danh sach ghe con trong: ";
                        output(listSeat);
                        Customer *cust = CreateCustomer();
                        addCustomer(listCustomer, cust);
                        deleteX(listSeat, cust->seatNumber);
                    } else {
                        cout << "\nKhong co ghe nao trong";
                    }
                } else {
					cout << "\nKhong co khach hang nao xep hang!";
				}
				break;
			}
			case 3:	{
				int seatToCancel;
				cout << "\nNhap so ghe khach hang muon huy: ";
				cin >> seatToCancel;

				// Xóa khách hàng có số ghế là seatToCancel
				if (deleteX(listCustomer, seatToCancel)) {
					// Nếu hủy thành công, cập nhật lại danh sách ghế
					deleteX(listSeat, seatToCancel);
					cout << "Huy ve thanh cong!\n";
				} else {
					cout << "Khong tim thay khach hang can huy ve!\n";
				}
				break;
			}
			case 4: {
                // Hiển thị thông tin những vé đã bán
                cout << "Danh sach khach hang da dat ve:\n";
                output(listCustomer);
                break;
            }
            case 0: {
                // Thoát chương trình
                flag = false;
                break;
            }
            default: {
                cout << "Lua chon nhap khong dung! Vui long nhap lai: ";
                cin >> lua_chon;
                break;
            }
        }
    }
    return 0;
}

// Hàm hiển thị menu và trả về lựa chọn của người dùng
int luaChonMenu() {
    int lua_chon;
    cout << "\n \n ================================ \n";
    cout << "\n Vui long chon chuc nang tuong ung.";
    cout << "\n 1. Lay so xep hang.";
    cout << "\n 2. Mua ve.";
    cout << "\n 3. Huy ve.";
    cout << "\n 4. Hien thi thong tin nhung ve da ban.";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon;
    return lua_chon;
}

// A. Các hàm xử lý danh sách ghế

// Khởi tạo danh sách ghế
void init(ListSeat &listSeat) {
    listSeat.pHead = listSeat.pTail = NULL;
    cout << "Nhap so ghe: ";
    cin >> listSeat.quantity;
    for (int i = 0; i < listSeat.quantity; i++) {
        Seat *seat = CreateSeat(i + 1);
        addSeat(listSeat, seat);
    }
}

// Tạo một ghế mới
Seat *CreateSeat(int x) {
    Seat *seat = new Seat;
    if (seat == NULL) {
        return NULL;
    }
    seat->number = x;
    seat->pNext = NULL;
    return seat;
}

// Thêm một ghế vào danh sách ghế
void addSeat(ListSeat &listSeat, Seat *seat) {
    if (listSeat.pHead == NULL) {
        listSeat.pHead = listSeat.pTail = seat;
    } else {
        listSeat.pTail->pNext = seat;
        listSeat.pTail = seat;
    }
}

// Xóa ghế đầu tiên trong danh sách ghế
void deleteSeat(ListSeat &listSeat) {
    if (listSeat.pHead == NULL) {
        return;
    }
    Seat *p = listSeat.pHead;
    listSeat.pHead = p->pNext;
    if (listSeat.pHead == NULL) {
        listSeat.pTail = NULL;
    }
    delete p;
}

// Đếm số phần tử trong danh sách ghế
int demSoPT(ListSeat listSeat) {
    int dem = 0;
    Seat *p = listSeat.pHead;
    while (p != NULL) {
        dem++;
        p = p->pNext;
    }
    return dem;
}

// Hiển thị danh sách ghế
void output(ListSeat listSeat) {
    Seat *p = listSeat.pHead;
    while (p != NULL) {
        cout << p->number << " ";
        p = p->pNext;
    }
}

// Xóa ghế có số x trong danh sách ghế
bool deleteX(ListSeat &listSeat, int x) {
    Seat *p = listSeat.pHead;
    Seat *prev = NULL;
    while (p != NULL) {
        if (p->number == x) {
            if (prev == NULL) {
                listSeat.pHead = p->pNext; // Cập nhật pHead
                if (listSeat.pHead == NULL) {
                    listSeat.pTail = NULL; // Nếu pHead là NULL thì cập nhật pTail
                }
            } else {
                prev->pNext = p->pNext; // Xóa p
                if (p == listSeat.pTail) {
                    listSeat.pTail = prev; // Cập nhật pTail nếu xóa pTail
                }
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->pNext;
    }
    cout << "Khong co thanh phan du lieu can xoa trong danh sach\n";
    return false;
}

// Xóa phần tử sau một phần tử nhất định trong danh sách ghế
bool deleteAfter(ListSeat &listSeat, Seat *seat) {
    if (seat != NULL) {
        Seat *p = seat->pNext;
        if (p != NULL) {
            seat->pNext = p->pNext;
            if (p == listSeat.pTail) {
                listSeat.pTail = seat;
            }
            delete p;
            return true;
        }
    }
    return false;
}

// Kiểm tra danh sách ghế có rỗng không
bool isEmpty(ListSeat listSeat) {
    return (listSeat.pHead == NULL);
}

// B. Các hàm xử lý hàng đợi số thứ tự

// Khởi tạo hàng đợi
void init(List &queue) {
    queue.pHead = queue.pTail = NULL;
}

// Tạo một số thứ tự mới
SoThuTu *CreateSoThuTu(int x) {
    SoThuTu *soThuTu = new SoThuTu;
    if (soThuTu == NULL) {
        return NULL;
    }
    soThuTu->stt = x;
    soThuTu->pNext = NULL;
    return soThuTu;
}

// Thêm một số thứ tự vào hàng đợi
void EnQueue(List &queue) {
    if (isEmpty(queue)) {
        SoThuTu *soThuTu = CreateSoThuTu(1);
        queue.pHead = queue.pTail = soThuTu;
    } else {
        int x = queue.pTail->stt;
        SoThuTu *soThuTu = CreateSoThuTu(x + 1);
        queue.pTail->pNext = soThuTu;
        queue.pTail = soThuTu;
    }
}

// Lấy số thứ tự đầu tiên ra khỏi hàng đợi
int DeQueue(List &queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int stt = queue.pHead->stt;
    SoThuTu *p = queue.pHead;
    queue.pHead = p->pNext;
    if (queue.pHead == NULL) {
        queue.pTail = NULL;
    }
    delete p;
    return stt;
}

// Hiển thị hàng đợi
void output(List queue) {
    SoThuTu *p = queue.pHead;
    while (p != NULL) {
        cout << p->stt << " ";
        p = p->pNext;
    }
}

// Kiểm tra hàng đợi có rỗng không
bool isEmpty(List queue) {
    return (queue.pHead == NULL);
}

// C. Các hàm xử lý danh sách khách hàng đã mua vé

// Khởi tạo danh sách khách hàng
void init(ListCustomer &listCustomer) {
    listCustomer.pHead = listCustomer.pTail = NULL;
}

// Tạo một khách hàng mới
Customer *CreateCustomer() {
    Customer *cust = new Customer;
    if (cust == NULL) {
        return NULL;
    }
    cout << "\nNhap so ghe: ";
    cin >> cust->seatNumber;
    cout << "\nNhap ten: ";
    cin.ignore();  // Xóa bộ đệm
    getline(cin, cust->name);
    cust->pNext = NULL;
    return cust;
}

// Thêm một khách hàng vào danh sách khách hàng
void addCustomer(ListCustomer &listCustomer, Customer *cust) {
    if (listCustomer.pHead == NULL) {
        listCustomer.pHead = listCustomer.pTail = cust;
    } else {
        listCustomer.pTail->pNext = cust;
        listCustomer.pTail = cust;
    }
}

// Hiển thị danh sách khách hàng
void output(ListCustomer listCustomer) {
    Customer *p = listCustomer.pHead;
    while (p != NULL) {
        cout << p->seatNumber << " - " << p->name << "\n";
        p = p->pNext;
    }
}

// Xóa khách hàng đầu tiên trong danh sách khách hàng
void deleteCustomer(ListCustomer &listCustomer) {
    if (listCustomer.pHead == NULL) {
        return;
    }
    Customer *p = listCustomer.pHead;
    listCustomer.pHead = p->pNext;
    if (listCustomer.pHead == NULL) {
        listCustomer.pTail = NULL;
    }
    delete p;
}

// Xóa khách hàng có số ghế là x trong danh sách khách hàng
bool deleteX(ListCustomer &listCustomer, int x) {
    Customer *p = listCustomer.pHead;
    Customer *prev = NULL;
    while (p != NULL) {
        if (p->seatNumber == x) {
            if (prev == NULL) {
                listCustomer.pHead = p->pNext; // Cập nhật pHead
                if (listCustomer.pHead == NULL) {
                    listCustomer.pTail = NULL; // Nếu pHead là NULL thì cập nhật pTail
                }
            } else {
                prev->pNext = p->pNext; // Xóa p
                if (p == listCustomer.pTail) {
                    listCustomer.pTail = prev; // Cập nhật pTail nếu xóa pTail
                }
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->pNext;
    }
    cout << "Khong co thanh phan du lieu can xoa trong danh sach\n";
    return false;
}

// Xóa phần tử sau một phần tử nhất định trong danh sách khách hàng
bool deleteAfter(ListCustomer &listCustomer, Customer *cust) {
    if (cust != NULL) {
        Customer *p = cust->pNext;
        if (p != NULL) {
            cust->pNext = p->pNext;
            if (p == listCustomer.pTail) {
                listCustomer.pTail = cust;
            }
            delete p;
            return true;
        }
    }
    return false;
}