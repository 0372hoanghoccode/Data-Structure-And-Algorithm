#include <iostream>
#include <string>
using namespace std;

// Định nghĩa lớp student (sinh viên)
class student {
public:
    string name;      // Tên sinh viên
    string ID;        // Mã sinh viên
    int year_birth;   // Năm sinh
    double score;     // Điểm trung bình
public:
    double return_Score() {
        return score;
    }
    string return_Name() {
        return name;
    }
    int return_Year() {
        return year_birth;
    }
    void student_import();
    void student_export();
};

// Định nghĩa cấu trúc node (nút) trong danh sách liên kết
struct node {
    student sinhVien;     // Dữ liệu sinh viên
    node* link_toNext;    // Con trỏ trỏ đến nút kế tiếp
    double get_Score() {
        return sinhVien.return_Score();
    }
    int get_Year() {
        return sinhVien.return_Year();
    }
    void get_Newlink(node* x) {
        link_toNext = x;
    }
    node* import_node(student x);
};

// Định nghĩa lớp list (danh sách liên kết)
class list {
    node* head;  // Con trỏ trỏ đến nút đầu tiên
    node* tail;  // Con trỏ trỏ đến nút cuối cùng
public:
    node* get_Head() {
        return head;
    }
    node* get_Tail() {
        return tail;
    }
    void create() {
        head = NULL;
        tail = NULL;
    }
    void print();
    void import_fromHead(node* x);
    void import_fromTail(node* x);
    void del_Head();
    void del_Tail();
    void del_after(node* p);
};

void call_menu();
void choose();
void import_List_Head(list& l);
void import_List_Tail(list& l);
void score_belowFive(list l);
void delete_2000(list& l);
void reset_info(student& x, student& y);
void switch_info(student& x, student& y);
void re_arrange(list& l);
void delete_list(list& l);

int main() {
    call_menu();
    choose();
    system("pause");
    return 0;
}

// Nhập thông tin sinh viên từ bàn phím
void student::student_import() {
    cout << "  Ho va ten sinh vien: ";
    int temp = getchar();  // Xóa ký tự newline trước đó
    getline(cin, name);
    cout << "  Ma sinh vien: ";
    getline(cin, ID);
    cout << "  Nam sinh: ";
    cin >> year_birth;
    while (year_birth < 1) {
        cout << "Nam sinh khong hop le, hay nhap lai" << endl;
        cout << "  Nam sinh: ";
        cin >> year_birth;
    }
    cout << "  Diem trung binh: ";
    cin >> score;
    while (score < 0 || score > 10) {
        cout << "Diem khong hop le, hay nhap lai" << endl;
        cout << "  Diem trung binh: ";
        cin >> score;
    }
}

// Xuất thông tin sinh viên ra màn hình
void student::student_export() {
    cout << "  Ho va ten sinh vien: " << name << endl;
    cout << "  Ma sinh vien: " << ID << endl;
    cout << "  Nam sinh: " << year_birth << endl;
    cout << "  Diem trung binh: " << score << endl;
}

// Tạo một nút mới chứa thông tin sinh viên
node* node::import_node(student x) {
    node* p = new node;
    if (p == NULL)
        return NULL;
    p->sinhVien = x;
    p->link_toNext = NULL;
    return p;
}

// In danh sách sinh viên
void list::print() {
    cout << "Danh sach: " << endl;
    for (node* temp = head; temp != NULL; temp = temp->link_toNext)
        temp->sinhVien.student_export();
    cout << endl;
}

// Thêm một nút vào đầu danh sách
void list::import_fromHead(node* x) {
    if (head == NULL) {
        head = tail = x;
    }
    else {
        x->link_toNext = head;
        head = x;
    }
}

// Thêm một nút vào cuối danh sách
void list::import_fromTail(node* x) {
    if (head == NULL) {
        head = tail = x;
    }
    else {
        tail->get_Newlink(x);
        tail = x;
    }
}

// Xóa nút đầu danh sách
void list::del_Head() {
    if (head == NULL) {
        cout << "Danh sach khong co sinh vien de xoa" << endl;
    } else if (head == tail) {
        delete head;
        head = tail = NULL;
        cout << "Da xoa sinh vien dau danh sach" << endl;
    } else {
        node* temp = head;
        head = head->link_toNext;
        delete temp;
        cout << "Da xoa sinh vien dau danh sach" << endl;
    }
}

// Xóa nút cuối danh sách
void list::del_Tail() {
    if (head == NULL) {
        cout << "Danh sach rong, khong co sinh vien de xoa" << endl;
    } else if (head == tail) {
        delete head;
        head = tail = NULL;
        cout << "Da xoa sinh vien cuoi danh sach" << endl;
    } else {
        node* temp;
        for (temp = head; temp->link_toNext != tail; temp = temp->link_toNext);
        delete tail;
        tail = temp;
        tail->link_toNext = NULL;
        cout << "Da xoa sinh vien cuoi danh sach" << endl;
    }
}

// Xóa nút sau nút p
void list::del_after(node* p) {
    if (p != NULL && p->link_toNext != NULL) {
        node* temp = p->link_toNext;
        p->link_toNext = temp->link_toNext;
        delete temp;
    }
}

// Hiển thị menu
void call_menu() {
    cout << "_____________________________" << endl << endl;
    cout << "1. Nhap vao danh sach n sinh vien bang cach them vao dau danh sach va in ra danh sach vua nhap" << endl;
    cout << "2. Nhap vao danh sach n sinh vien bang cach them vao cuoi danh sach va in ra danh sach vua nhap" << endl;
    cout << "3. In ra danh sach cac sinh vien co diem trung binh nho hon 5" << endl;
    cout << "4. Xoa cac sinh vien co nam sinh truoc 2000" << endl;
    cout << "5. Sap xep danh sach theo thu tu tang dan diem trung binh" << endl;
    cout << "6. In ra danh sach roi xoa toan bo danh sach" << endl;
    cout << "_____________________________" << endl << endl;
}

// Xử lý lựa chọn từ người dùng
void choose() {
    cout << "Lua chon cua ban la: ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 6) {
        cout << "Lua chon khong hop le, vui long nhap lai" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> choice;
    }
    list l;
    l.create();
    while (choice > 0 && choice <= 6) {
        switch (choice) {
        case 1:
            import_List_Head(l);
            l.print();
            call_menu();
            break;
        case 2:
            import_List_Tail(l);
            l.print();
            call_menu();
            break;
        case 3:
            score_belowFive(l);
            cout << endl;
            call_menu();
            break;
        case 4:
            delete_2000(l);
            l.print();
            call_menu();
            break;
        case 5:
            re_arrange(l);
            l.print();
            call_menu();
            break;
        case 6:
            l.print();
            delete_list(l);
            call_menu();
            break;
        }
        cout << "Lua chon cua ban la: ";
        cin >> choice;
    }
}

// Nhập danh sách sinh viên từ đầu
void import_List_Head(list& l) {
    int size;
    cout << "Nhap so sinh vien can them vao: ";
    cin >> size;
    for (int i = 1; i <= size; ++i) {
        cout << "  Sinh vien thu " << i << ":" << endl;
        student x;
        x.student_import();
        node* temp = new node;
        temp = temp->import_node(x);
        l.import_fromHead(temp);
    }
    cout << endl;
}

// Nhập danh sách sinh viên từ cuối
void import_List_Tail(list& l) {
    int size;
    cout << "Nhap so sinh vien can them vao: ";
    cin >> size;
    for (int i = 1; i <= size; ++i) {
        cout << "  Sinh vien thu " << i << ":" << endl;
        student x;
        x.student_import();
        node* temp = new node;
        temp = temp->import_node(x);
        l.import_fromTail(temp);
    }
    cout << endl;
}

// In ra danh sách các sinh viên có điểm trung bình dưới 5
void score_belowFive(list l) {
    cout << "Danh sach cac sinh vien co diem trung binh duoi 5: " << endl;
    for (node* temp = l.get_Head(); temp != NULL; temp = temp->link_toNext)
        if (temp->get_Score() < 5) {
            temp->sinhVien.student_export();
        }
}

// Xóa các sinh viên có năm sinh trước 2000
void delete_2000(list& l) {
    while (l.get_Head() != NULL && l.get_Head()->get_Year() < 2000) {
        l.del_Head();
    }
    node* current = l.get_Head();
    while (current != NULL && current->link_toNext != NULL) {
        if (current->link_toNext->get_Year() < 2000) {
            l.del_after(current);
        } else {
            current = current->link_toNext;
        }
    }
}

// Đặt lại thông tin sinh viên
void reset_info(student& x, student& y) {
    x.name = y.name;
    x.ID = y.ID;
    x.year_birth = y.year_birth;
    x.score = y.score;
}

// Hoán đổi thông tin sinh viên
void switch_info(student& x, student& y) {
    student temp;
    reset_info(temp, x);
    reset_info(x, y);
    reset_info(y, temp);
}

// Sắp xếp danh sách theo thứ tự tăng dần điểm trung bình
void re_arrange(list& l) {
    if (l.get_Head() == NULL || l.get_Head()->link_toNext == NULL)
        return;

    for (node* p = l.get_Head(); p != NULL; p = p->link_toNext) {
        for (node* q = p->link_toNext; q != NULL; q = q->link_toNext) {
            if (p->sinhVien.return_Score() > q->sinhVien.return_Score()) {
                switch_info(p->sinhVien, q->sinhVien);
            }
        }
    }
}

// Xóa toàn bộ danh sách
void delete_list(list& l) {
    while (l.get_Head() != NULL) {
        l.del_Head();
    }
}
