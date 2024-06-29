#include <iostream>
#include <vector>
using namespace std;

// Lớp cơ sở hashTable chứa các phương thức và thuộc tính cơ bản của bảng băm
class hashTable {
public:
    int tableSize;  // Kích thước bảng băm
    int* table;     // Mảng lưu trữ giá trị trong bảng băm

    // Constructor để khởi tạo bảng băm
    hashTable();

    // Các phương thức ảo để ghi đè trong các lớp dẫn xuất
    virtual int valueOf(int);
    virtual void addValue(int);
    virtual int getValue(int);

    // Phương thức thêm nhiều giá trị vào bảng băm
    void add_manyValue();
    // Phương thức in bảng băm ra màn hình
    virtual void printTable();
};

// Lớp hashLinear kế thừa từ hashTable và sử dụng thuật toán thăm dò tuyến tính
class hashLinear : public hashTable {
public:
    int valueOf(int);
    void addValue(int);
    int getValue(int);
};

// Lớp hashSquare kế thừa từ hashTable và sử dụng thuật toán thăm dò bình phương
class hashSquare : public hashTable {
public:
    int valueOf(int);
    void addValue(int);
    int getValue(int);
};

// Lớp hashChain kế thừa từ hashTable và sử dụng phương pháp dây chuyền
class hashChain : public hashTable {
    vector<int> chain[11]; // Mảng vector để lưu các danh sách liên kết
public:
    virtual int valueOf(int x);
    void addValue(int element);
    int getValue(int element);
    void printTable();
};

// Lớp hashChain_f1 kế thừa từ hashChain và sử dụng công thức hàm băm f1
class hashChain_f1 : public hashChain {
    int valueOf(int x);
};

// Lớp hashChain_f2 kế thừa từ hashChain và sử dụng công thức hàm băm f2
class hashChain_f2 : public hashChain {
    int valueOf(int x);
};

// Các hàm menu và choose để điều hướng người dùng
void menu();
void choose(hashTable*&);

void menu_hashChain();
void choose_hashChain(hashTable*&);

int main() {
    hashTable *table = nullptr; // Con trỏ tới đối tượng bảng băm
    choose(table);
    delete table;  // Giải phóng bộ nhớ sau khi sử dụng
}

// Constructor để khởi tạo bảng băm rỗng
hashTable::hashTable() {
    tableSize = 11; // Đặt kích thước bảng băm là 11
    table = new int[tableSize]; // Cấp phát bộ nhớ cho bảng băm
    for (int i = 0; i < tableSize; i++)
        table[i] = -1; // Khởi tạo các vị trí trong bảng băm là -1 (rỗng)
}

int hashTable::valueOf(int) {
    return 0; // Hàm ảo, sẽ được ghi đè trong các lớp dẫn xuất
}

void hashTable::addValue(int) {
    cout << "Nothing here"; // Hàm ảo, sẽ được ghi đè trong các lớp dẫn xuất
}

int hashTable::getValue(int) {
    return 0; // Hàm ảo, sẽ được ghi đè trong các lớp dẫn xuất
}

// Phương thức thêm nhiều giá trị vào bảng băm
void hashTable::add_manyValue() {
    addValue(32);
    addValue(15);
    addValue(25);
    addValue(44);
    addValue(36);
    addValue(21);
}

// Phương thức in bảng băm ra màn hình
void hashTable::printTable() {
    cout << "    KEY     VALUE" << endl;
    cout << "   ----     -----" << endl;
    for (int i = 0; i < tableSize; i++)
        if (table[i] != -1)
            cout << "    " << table[i] << "        " << getValue(table[i]) << endl;
}

// Lớp hashLinear sử dụng thuật toán thăm dò tuyến tính
int hashLinear::valueOf(int x) {
    return x % tableSize; // Hàm băm chia lấy dư
}

// Thêm giá trị vào bảng băm với thăm dò tuyến tính
void hashLinear::addValue(int element) {
    int index = valueOf(element);
    while (table[index] != -1) // Nếu vị trí đã bị chiếm, di chuyển đến vị trí tiếp theo
        index = valueOf(index + 1);
    table[index] = element; // Đặt giá trị vào bảng băm
}

// Lấy vị trí của giá trị trong bảng băm
int hashLinear::getValue(int element) {
    int index = valueOf(element);
    while (table[index] != -1 && table[index] != element) // Tìm kiếm tuyến tính
        index = valueOf(index + 1);
    if (table[index] == element)
        return index; // Trả về vị trí nếu tìm thấy
    else return -1; // Trả về -1 nếu không tìm thấy
}

// Lớp hashSquare sử dụng thuật toán thăm dò bình phương
int hashSquare::valueOf(int x) {
    return x % tableSize; // Hàm băm chia lấy dư
}

// Thêm giá trị vào bảng băm với thăm dò bình phương
void hashSquare::addValue(int element) {
    int index = valueOf(element);
    int k = 0;
    while (table[index] != -1) { // Nếu vị trí đã bị chiếm, di chuyển theo công thức bình phương
        k++;
        index = valueOf(valueOf(element) + k * k);
    }
    table[index] = element; // Đặt giá trị vào bảng băm
}

// Lấy vị trí của giá trị trong bảng băm
int hashSquare::getValue(int element) {
    int index = valueOf(element);
    int k = 0;
    while (table[index] != -1 && table[index] != element) { // Tìm kiếm theo công thức bình phương
        k++;
        index = valueOf(valueOf(element) + k * k);
    }
    if (table[index] == element)
        return index; // Trả về vị trí nếu tìm thấy
    else return -1; // Trả về -1 nếu không tìm thấy
}

// Lớp hashChain sử dụng phương pháp dây chuyền
int hashChain::valueOf(int x) {
    return x % tableSize; // Hàm băm chia lấy dư
}

// Thêm giá trị vào bảng băm với phương pháp dây chuyền
void hashChain::addValue(int element) {
    int index = valueOf(element);
    chain[index].push_back(element); // Thêm giá trị vào danh sách liên kết
}

// Lấy vị trí của giá trị trong bảng băm
int hashChain::getValue(int element) {
    int index = valueOf(element);
    // Duyệt qua danh sách liên kết tại chỉ mục index
    for (int value : chain[index])
        if (value == element)
            return index; // Trả về vị trí nếu tìm thấy
    return -1; // Trả về -1 nếu không tìm thấy
}

// In bảng băm ra màn hình với phương pháp dây chuyền
void hashChain::printTable() {
    cout << "    KEY     VALUE" << endl;
    cout << "   ----     -----" << endl;
    for (int i = 0; i < tableSize; i++) {
        if (!chain[i].empty()) { // Nếu danh sách liên kết tại chỉ mục không rỗng
            cout << "   ";
            for (size_t j = 0; j < chain[i].size(); j++) {
                cout << chain[i][j];
                if (j < chain[i].size() - 1) cout << " -> "; // In dấu mũi tên nếu không phải phần tử cuối
            }
            cout << "        " << i << endl;
        }
    }
}

// Hàm băm f1 cho hashChain_f1
int hashChain_f1::valueOf(int x) {
    return x % tableSize;
}

// Hàm băm f2 cho hashChain_f2
int hashChain_f2::valueOf(int x) {
    return (tableSize - 2) - (x % (tableSize - 2));
}

// Hiển thị menu chính
void menu() {
    cout << "=========================================================" << endl;
    cout << " Luu y: Bang bam da duoc them san cac gia tri 32, 15, 25, 44, 36 va 21" << endl;
    cout << "  (1) Tham do tuyen tinh" << endl;
    cout << "  (2) Tham do binh phuong" << endl;
    cout << "  (3) Tham do day chuyen" << endl;
    cout << "  (0) Thoat" << endl; // Thêm tùy chọn thoát
    cout << "=========================================================" << endl;
}

// Hàm điều hướng người dùng để chọn thuật toán băm
void choose(hashTable*& table) {
    int choice;
    while (true) { // Thêm vòng lặp để người dùng có thể tiếp tục chọn lựa
        menu();
        cout << "  Lua chon cua ban la: ";
        cin >> choice;
        if (choice == 0) {
            break; // Thoát vòng lặp nếu người dùng chọn thoát
        }
        switch (choice) {
        case 1:
            delete table; // Xóa đối tượng cũ nếu có
            table = new hashLinear; // Tạo bảng băm với thuật toán thăm dò tuyến tính
            table->add_manyValue();
            table->printTable();
            break;
        case 2:
            delete table; // Xóa đối tượng cũ nếu có
            table = new hashSquare; // Tạo bảng băm với thuật toán thăm dò bình phương
            table->add_manyValue();
            table->printTable();
            break;
        case 3:
            choose_hashChain(table); // Điều hướng đến menu chọn phương pháp dây chuyền
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    }
}

// Hiển thị menu chọn phương pháp dây chuyền
void menu_hashChain() {
    cout << "===============================================================================" << endl;
    cout << "  (1) Bam theo cong thuc F(key) = key % M'" << endl;
    cout << "  (2) Bam theo cong thuc F(key) = (tableSize - 2) - (x % (tableSize - 2))" << endl;
    cout << "  (0) Quay lai" << endl; // Thêm tùy chọn quay lại
    cout << "===============================================================================" << endl;
}

// Hàm điều hướng người dùng để chọn công thức hàm băm cho phương pháp dây chuyền
void choose_hashChain(hashTable*& table) {
    int choice;
    while (true) { // Thêm vòng lặp để người dùng có thể tiếp tục chọn lựa
        menu_hashChain();
        cout << "  Lua chon cua ban la: ";
        cin >> choice;
        if (choice == 0) {
            break; // Thoát vòng lặp nếu người dùng chọn quay lại
        }
        switch (choice) {
        case 1:
            delete table; // Xóa đối tượng cũ nếu có
            table = new hashChain_f1; // Tạo bảng băm với phương pháp dây chuyền sử dụng hàm băm f1
            table->add_manyValue();
            table->printTable();
            break;
        case 2:
            delete table; // Xóa đối tượng cũ nếu có
            table = new hashChain_f2; // Tạo bảng băm với phương pháp dây chuyền sử dụng hàm băm f2
            table->add_manyValue();
            table->printTable();
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    }
}
