#include <iostream>
#include <cmath> // Thêm thư viện cmath để sử dụng hàm sqrt
#include <ctime> 
using namespace std;

// Cấu trúc của một node trong cây nhị phân
struct node {
    int value; // Giá trị của node
    node* leftBranch; // Nhánh trái
    node* rightBranch; // Nhánh phải
    node(int value) {
        this->value = value;
        leftBranch = rightBranch = NULL; // Khởi tạo nhánh trái và phải bằng NULL
    }
};

// Khai báo các hàm
int random(int min, int max); // Hàm sinh số ngẫu nhiên trong khoảng min và max
void add(node*&, int); // Hàm thêm giá trị vào cây nhị phân
void importTree(node*&, int&); // Hàm nhập cây nhị phân

// Các hàm in cây nhị phân theo các thứ tự khác nhau
void print_RLN(node*);
void print_NLR(node*);
void print_NRL(node*);
void print_LRN(node*);
void print_LNR(node*);
void print_RNL(node*);
void printTree(node*);

// Các hàm xử lý số nguyên tố
bool isPrime(int x); // Hàm kiểm tra số nguyên tố
void printPrime(node* root); // Hàm in các số nguyên tố trong cây
int maxPrime(node* root); // Hàm tìm số nguyên tố lớn nhất trong cây

// Các hàm in node theo mức và kiểm tra mức
void printNodes_levelK(node* tree, int level); // Hàm in các node ở mức K
void checkNodes_levelK(node* root); // Hàm kiểm tra các node ở mức K

// Hàm tính tổng các số chẵn
int evenTotal(node* root); // Hàm tính tổng các số chẵn ở cây con trái

// Hàm tìm giá trị nhỏ nhất và lớn nhất
int minValue(node* root); // Hàm tìm giá trị nhỏ nhất ở cây con phải
int maxValue(node* root); // Hàm tìm giá trị lớn nhất ở cây con trái

// Các hàm đếm số node trong khoảng giá trị
int countNode_belowX(node* root, int x); // Hàm đếm số node có giá trị nhỏ hơn X
void print_nodeAmount(node* root); // Hàm in số lượng node có giá trị nhỏ hơn X
int countNode_inRange(node* root, int x, int y); // Hàm đếm số node có giá trị trong khoảng [X, Y]
void printNode_inRange(node* root); // Hàm in số lượng node có giá trị trong khoảng [X, Y]

// Hàm hiển thị menu và lựa chọn chức năng
void menu();
void choose(node*& tree, int& size);

// Hàm chính
int main() {
    node* tree = NULL; // Khởi tạo cây nhị phân rỗng
    int n;
    choose(tree, n); // Gọi hàm lựa chọn chức năng
    system("pause");
    return 0;
}

// Hàm sinh số ngẫu nhiên trong khoảng min và max
int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand((unsigned int)time(NULL)); // Khởi tạo bộ sinh số ngẫu nhiên
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

// Hàm thêm giá trị vào cây nhị phân
void add(node*& root, int value) {
    if (root == NULL)
        root = new node(value); // Nếu cây rỗng thì tạo node mới
    else if (value < root->value)
        add(root->leftBranch, value); // Nếu giá trị nhỏ hơn giá trị của node hiện tại thì thêm vào nhánh trái
    else if (root->value < value)
        add(root->rightBranch, value); // Nếu giá trị lớn hơn giá trị của node hiện tại thì thêm vào nhánh phải
}

// Hàm nhập cây nhị phân
void importTree(node*& TREE, int& size) {
    cout << "So phan tu muon them la: ";
    cin >> size;
    system("cls");
    for (int i = 0; i < size; i++)
        add(TREE, random(10, 99)); // Thêm các giá trị ngẫu nhiên vào cây
    cout << "Cay nhi phan sau khi them cac phan tu la:" << endl;
    printTree(TREE); // In cây nhị phân
    cout << endl;
}

// Các hàm in cây nhị phân theo các thứ tự khác nhau
void print_RLN(node* root) {
    if (root) {
        print_RLN(root->rightBranch); // In nhánh phải trước
        print_RLN(root->leftBranch); // In nhánh trái sau
        cout << root->value << " "; // In giá trị của node
    }
}

void print_NLR(node* root) {
    if (root) {
        cout << root->value << " "; // In giá trị của node trước
        print_NLR(root->leftBranch); // In nhánh trái
        print_NLR(root->rightBranch); // In nhánh phải
    }
}

void print_NRL(node* root) {
    if (root) {
        cout << root->value << " "; // In giá trị của node trước
        print_NRL(root->rightBranch); // In nhánh phải
        print_NRL(root->leftBranch); // In nhánh trái
    }
}

void print_LRN(node* root) {
    if (root) {
        print_LRN(root->leftBranch); // In nhánh trái trước
        print_LRN(root->rightBranch); // In nhánh phải sau
        cout << root->value << " "; // In giá trị của node
    }
}

void print_LNR(node* root) {
    if (root) {
        print_LNR(root->leftBranch); // In nhánh trái trước
        cout << root->value << " "; // In giá trị của node
        print_LNR(root->rightBranch); // In nhánh phải sau
    }
}

void print_RNL(node* root) {
    if (root) {
        print_RNL(root->rightBranch); // In nhánh phải trước
        cout << root->value << " "; // In giá trị của node
        print_RNL(root->leftBranch); // In nhánh trái sau
    }
}

// Hàm in toàn bộ cây nhị phân theo các thứ tự khác nhau
void printTree(node* root) {
    cout << "  RLN: ";
    print_RLN(root);
    cout << "\n  LRN: ";
    print_LRN(root);
    cout << "\n  NLR: ";
    print_NLR(root);
    cout << "\n  NRL: ";
    print_NRL(root);
    cout << "\n  RNL: ";
    print_RNL(root);
    cout << "\n  LNR: ";
    print_LNR(root);
    cout << endl;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

// Hàm in các số nguyên tố trong cây
void printPrime(node* root) {
    if (root == NULL)
        return;
    if (isPrime(root->value))
        cout << root->value << " ";
    printPrime(root->leftBranch);
    printPrime(root->rightBranch);
}

// Hàm tìm số nguyên tố lớn nhất trong cây
int maxPrime(node* root) {
    int result = 0;
    if (root == NULL)
        return result;
    result = max(maxPrime(root->leftBranch), maxPrime(root->rightBranch));
    if (isPrime(root->value))
        result = max(result, root->value);
    return result;
}

// Hàm in các node ở mức K
void printNodes_levelK(node* tree, int level) {
    if (tree == NULL)
        return;
    if (level == 1)
        cout << tree->value << " ";
    else {
        printNodes_levelK(tree->leftBranch, level - 1);
        printNodes_levelK(tree->rightBranch, level - 1);
    }
}

// Hàm kiểm tra các node ở mức K
void checkNodes_levelK(node* root) {
    int k;
    cout << "Muc can in la: ";
    cin >> k;
    system("cls");
    printNodes_levelK(root, k);
    cout << endl;
}

// Hàm tính tổng các số chẵn ở cây con trái
int evenTotal(node* root) {
    if (root == NULL)
        return 0;
    int total = evenTotal(root->leftBranch) + evenTotal(root->rightBranch);
    if (root->value % 2 == 0)
        total += root->value;
    return total;
}

// Hàm tìm giá trị nhỏ nhất ở cây con phải
int minValue(node* root) {
    if (root->leftBranch == NULL)
        return root->value;
    return minValue(root->leftBranch);
}

// Hàm tìm giá trị lớn nhất ở cây con trái
int maxValue(node* root) {
    if (root->rightBranch == NULL)
        return root->value;
    return maxValue(root->rightBranch);
}

// Hàm đếm số node có giá trị nhỏ hơn X
int countNode_belowX(node* root, int x) {
    int count = 0;
    if (root == NULL)
        return 0;
    count = countNode_belowX(root->leftBranch, x) + countNode_belowX(root->rightBranch, x);
    if (root->value < x)
        count++;
    return count;
}

// Hàm in số lượng node có giá trị nhỏ hơn X
void print_nodeAmount(node* root) {
    int x;
    cout << "Nhap vao so nguyen X: ";
    cin >> x;
    cout << "So luong cac nut co gia tri nho hon " << x << " la: " << countNode_belowX(root, x) << endl;
}

// Hàm đếm số node có giá trị trong khoảng [X, Y]
int countNode_inRange(node* root, int x, int y) {
    int count = 0;
    if (root == NULL)
        return 0;
    count = countNode_inRange(root->leftBranch, x, y) + countNode_inRange(root->rightBranch, x, y);
    if (root->value > x && root->value < y)
        count++;
    return count;
}

// Hàm in số lượng node có giá trị trong khoảng [X, Y]
void printNode_inRange(node* root) {
    int x, y;
    cout << "Nhap vao hai so nguyen X va Y: ";
    cin >> x >> y;
    cout << "So luong cac nut co gia tri trong khoang tu " << x << " den " << y << " la: " << countNode_inRange(root, x, y) << endl;
}

// Hàm hiển thị menu các chức năng
void menu() {
    cout << "================== LUA CHON ==================" << endl;
    cout << " (0)  Thoat chuong trinh" << endl;
    cout << " (1)  Tao cay nhi phan" << endl;
    cout << " (2)  In cac so nguyen to tren cay" << endl;
    cout << " (3)  In ra so nguyen to lon nhat tren cay" << endl;
    cout << " (4)  In ra cac nut o muc K" << endl;
    cout << " (5)  In ra tong cac so chan o cay con trai" << endl;
    cout << " (6)  In ra phan tu nho nhat o cay con phai" << endl;
    cout << " (7)  In ra phan tu lon nhat o cay con trai" << endl;
    cout << " (8)  Dem so nut co gia tri nho hon X" << endl;
    cout << " (9)  Dem so nut co gia tri lon hon X va nho hon Y" << endl;
    cout << "================================================" << endl;
}

// Hàm lựa chọn chức năng
void choose(node*& tree, int& size) {
    system("cls");
    int choice;
    menu();
    cout << " Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 0: // Thoát chương trình
        exit(0);
    case 1:
        system("cls");
        importTree(tree, size);
        break;
    case 2:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else if (maxPrime(tree) > 0) {
            cout << "Cac so nguyen to co tren cay la: ";
            printPrime(tree);
            cout << endl;
        }
        else cout << "Khong co so nguyen to tren cay" << endl;
        break;
    case 3:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (maxPrime(tree) > 0)
                cout << "So nguyen to lon nhat tren cay la " << maxPrime(tree) << endl;
            else cout << "Khong co so nguyen to tren cay" << endl;
        }
        break;
    case 4:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else checkNodes_levelK(tree);
        break;
    case 5:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else cout << "Tong cac so chan o cay con trai la " << evenTotal(tree->leftBranch) << endl;
        break;
    case 6:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (minValue(tree->rightBranch) > 0)
                cout << "Phan tu nho nhat o cay con phai la " << minValue(tree->rightBranch) << endl;
            else cout << "Cay con phai khong co phan tu" << endl;
        }
        break;
    case 7:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (maxValue(tree->leftBranch) > 0)
                cout << "Phan tu lon nhat o cay con trai la " << maxValue(tree->leftBranch) << endl;
            else cout << "Cay con trai khong co phan tu" << endl;
        }
        break;
    case 8:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else print_nodeAmount(tree);
        break;
    case 9:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else printNode_inRange(tree);
        break;
    default:
        choose(tree, size);
        break;
    }
    system("pause");
    choose(tree, size);
}
