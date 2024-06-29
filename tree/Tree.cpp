#include <iostream>
#include <queue>
#include <algorithm> 
using namespace std;

// Định nghĩa cấu trúc của một node
struct node {
    int value;
    node* leftBranch;
    node* rightBranch;
    node(int value) {
        this->value = value;
        leftBranch = rightBranch = NULL;
    }
};

// Khai báo các hàm sử dụng trong chương trình
void add(node*&, int);
void importTree(node*&, int&);

void print_RLN(node*);
void print_NLR(node*);
void print_NRL(node*);
void print_LRN(node*);
void print_LNR(node*);
void print_RNL(node*);
void printTree(node*);

bool isAvailable(node*, int);
void findX(node*);

node* minNode(node*);
void deleteNode(node*&, int);
void deleteX(node*&);

int countNode(node*);
int countNode_2branch(node*);
int countNode_1branch(node*);
int countNode_rightBranch(node*);
int countNode_noBranch(node*);

int height(node*);

void find_evenNode(node*);

int amount_greaterThanX(node*, int);
void find_greaterThanX(node*);

int maxValue(node*);

int maxValue_rightBranch(node*);

void printNode_level(node*);

node* Node(node*, int);
int heightX(node*, int);
void findPath_X(node*);

void menu();
void choose(node*&, int&);

int main() {
    node* tree = NULL;
    int n;
    choose(tree, n);
    system("pause");
}

// Hàm thêm một node mới vào cây
void add(node*& root, int value) {
    if (root == NULL)
        root = new node(value);
    else if (value < root->value)
        add(root->leftBranch, value);
    else if (root->value < value)
        add(root->rightBranch, value);
}

// Hàm nhập các giá trị vào cây
void importTree(node*& TREE, int& size) {
    cout << "So phan tu muon them la: ";
    cin >> size;
    int addValue;
    for (int i = 0; i < size; i++) {
        cout << "Nhap cac phan tu!" << endl;
        cout << "Phan tu them vao thu " << i + 1 << ": ";
        cin >> addValue;
        add(TREE, addValue);
    }
}

// Các hàm in cây theo thứ tự khác nhau
void print_RLN(node* root) {
    if (root) {
        print_RLN(root->rightBranch);
        print_RLN(root->leftBranch);
        cout << root->value << " ";
    }
}
void print_NLR(node* root) {
    if (root) {
        cout << root->value << " ";
        print_NLR(root->leftBranch);
        print_NLR(root->rightBranch);
    }
}
void print_NRL(node* root) {
    if (root) {
        cout << root->value << " ";
        print_NRL(root->rightBranch);
        print_NRL(root->leftBranch);
    }
}
void print_LRN(node* root) {
    if (root) {
        print_LRN(root->leftBranch);
        print_LRN(root->rightBranch);
        cout << root->value << " ";
    }
}
void print_LNR(node* root) {
    if (root) {
        print_LNR(root->leftBranch);
        cout << root->value << " ";
        print_LNR(root->rightBranch);
    }
}
void print_RNL(node* root) {
    if (root) {
        print_RNL(root->rightBranch);
        cout << root->value << " ";
        print_RNL(root->leftBranch);
    }
}

// Hàm in ra cây theo nhiều thứ tự khác nhau
void printTree(node* root) {
    cout << "RLN: ";
    print_RLN(root);
    cout << "\nLRN: ";
    print_LRN(root);
    cout << "\nNLR: ";
    print_NLR(root);
    cout << "\nNRL: ";
    print_NRL(root);
    cout << "\nRNL: ";
    print_RNL(root);
    cout << "\nLNR: ";
    print_LNR(root);
    cout << endl;
}

// Hàm kiểm tra giá trị có tồn tại trong cây hay không
bool isAvailable(node* root, int value) {
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return isAvailable(root->leftBranch, value);
    else if (root->value < value)
        return isAvailable(root->rightBranch, value);
    return false;
}

// Hàm tìm giá trị x trong cây
void findX(node* root) {
    int x;
    cout << "Gia tri can tim la: ";
    cin >> x;
    if (isAvailable(root, x))
        cout << "Gia tri " << x << " co ton tai trong cay" << endl;
    else cout << "Gia tri " << x << " khong ton tai trong cay" << endl;
}

// Hàm tìm node có giá trị nhỏ nhất trong cây
node* minNode(node* root) {
    while (root->leftBranch != NULL)
        root = root->leftBranch;
    return root;
}

// Hàm xóa node có giá trị value
void deleteNode(node*& root, int value) {
    if (root == NULL || isAvailable(root, value) == false) {
        cout << "Khong ton tai node can xoa" << endl;
        return;
    }
    if (value > root->value)
        deleteNode(root->rightBranch, value);
    else if (value < root->value)
        deleteNode(root->leftBranch, value);
    else {
        if (root->leftBranch == NULL && root->rightBranch == NULL) {
            delete root;
            root = NULL;
            cout << "Xoa thanh cong" << endl;
        }
        else if (root->leftBranch == NULL && root->rightBranch != NULL) {
            node* temp = root;
            root = root->rightBranch;
            delete temp;
            temp = NULL;
        }
        else if (root->rightBranch == NULL && root->leftBranch != NULL) {
            node* temp = root;
            root = root->leftBranch;
            delete temp;
            temp = NULL;
            cout << "Xoa thanh cong" << endl;
        }
        else {
            node* temp = minNode(root->rightBranch);
            swap(root->value, temp->value);
            deleteNode(root->rightBranch, value);
        }
    }
}

// Hàm xóa giá trị x trong cây
void deleteX(node*& root) {
    int x;
    cout << "Gia tri can xoa la: ";
    cin >> x;
    deleteNode(root, x);
}

// Hàm đếm số node trong cây
int countNode(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode(root->leftBranch);
    int b = countNode(root->rightBranch);
    return a + b + 1;
}

// Hàm đếm số node có hai nhánh trong cây
int countNode_2branch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_2branch(root->leftBranch);
    int b = countNode_2branch(root->rightBranch);
    if (root->leftBranch != NULL && root->rightBranch != NULL)
        return a + b + 1;
    return a + b;
}

// Hàm đếm số node có một nhánh trong cây
int countNode_1branch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_1branch(root->leftBranch);
    int b = countNode_1branch(root->rightBranch);
    if ((root->leftBranch != NULL && root->rightBranch == NULL) || (root->leftBranch == NULL && root->rightBranch != NULL))
        return a + b + 1;
    return a + b;
}

// Hàm đếm số node chỉ có nhánh phải trong cây
int countNode_rightBranch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_rightBranch(root->leftBranch);
    int b = countNode_rightBranch(root->rightBranch);
    if (root->leftBranch == NULL && root->rightBranch != NULL)
        return a + b + 1;
    return a + b;
}

// Hàm đếm số node không có nhánh trong cây
int countNode_noBranch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_noBranch(root->leftBranch);
    int b = countNode_noBranch(root->rightBranch);
    if (root->leftBranch == NULL && root->rightBranch == NULL)
        return a + b + 1;
    return a + b;
}

// Hàm tính chiều cao của cây
int height(node* root) {
    if (root == NULL)
        return 0;
    return max(height(root->leftBranch), height(root->rightBranch)) + 1;
}

// Hàm tìm các node có giá trị chẵn trong cây
void find_evenNode(node* root) {
    if (root != NULL) {
        find_evenNode(root->leftBranch);
        find_evenNode(root->rightBranch);
        if (root->value % 2 == 0)
            cout << root->value << " ";
    }
}

// Hàm đếm số node có giá trị lớn hơn x
int amount_greaterThanX(node* root, int x) {
    if (root == NULL)
        return 0;
    int a = amount_greaterThanX(root->leftBranch, x);
    int b = amount_greaterThanX(root->rightBranch, x);
    if (root->value > x)
        return a + b + 1;
    return a + b;
}

// Hàm tìm các giá trị lớn hơn x
void find_greaterThanX(node* root) {
    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    int amount = amount_greaterThanX(root, x);
    cout << "So luong cac gia tri lon hon " << x << " la: " << amount << endl;
}

// Hàm tìm giá trị lớn nhất trong cây
int maxValue(node* root) {
    if (root == NULL)
        return INT_MIN;
    int value = root->value;
    int left = maxValue(root->leftBranch);
    int right = maxValue(root->rightBranch);
    return max(value, max(left, right));
}

// Hàm tìm giá trị lớn nhất ở nhánh phải
int maxValue_rightBranch(node* root) {
    if (root == NULL)
        return INT_MIN;
    int rightValue = maxValue(root->rightBranch);
    return max(root->value, rightValue);
}

// Hàm in các node theo mức (level)
void printNode_level(node* root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->value << " ";
        if (current->leftBranch != NULL)
            q.push(current->leftBranch);
        if (current->rightBranch != NULL)
            q.push(current->rightBranch);
    }
}

// Hàm tìm node với giá trị x
node* Node(node* root, int x) {
    if (root == NULL || root->value == x)
        return root;
    if (x < root->value)
        return Node(root->leftBranch, x);
    return Node(root->rightBranch, x);
}

// Hàm tìm chiều cao của node có giá trị x
int heightX(node* root, int x) {
    node* targetNode = Node(root, x);
    return height(targetNode);
}

// Hàm tìm đường đi đến giá trị x
void findPath_X(node* root) {
    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    node* current = root;
    while (current != NULL) {
        cout << current->value << " ";
        if (current->value == x)
            break;
        else if (current->value < x)
            current = current->rightBranch;
        else
            current = current->leftBranch;
    }
    if (current == NULL)
        cout << "Khong tim thay gia tri x trong cay" << endl;
}

// Menu các tùy chọn của chương trình
void menu() {
    cout << "1. Them phan tu vao cay" << endl;
    cout << "2. Nhap gia tri vao cay" << endl;
    cout << "3. Xuat cac gia tri cua cay theo cac thu tu" << endl;
    cout << "4. Kiem tra gia tri co ton tai trong cay hay khong" << endl;
    cout << "5. Xoa mot node trong cay" << endl;
    cout << "6. Xuat so luong node trong cay" << endl;
    cout << "7. Xuat so luong node co hai nhanh trong cay" << endl;
    cout << "8. Xuat so luong node co mot nhanh trong cay" << endl;
    cout << "9. Xuat so luong node chi co nhanh phai trong cay" << endl;
    cout << "10. Xuat so luong node khong co nhanh trong cay" << endl;
    cout << "11. Tinh chieu cao cua cay" << endl;
    cout << "12. Xuat cac gia tri chan trong cay" << endl;
    cout << "13. Xuat cac gia tri lon hon x" << endl;
    cout << "14. Tim gia tri lon nhat trong cay" << endl;
    cout << "15. Tim gia tri lon nhat trong nhanh phai" << endl;
    cout << "16. Xuat cac node theo muc" << endl;
    cout << "17. Tinh chieu cao cua node co gia tri x" << endl;
    cout << "18. Tim duong di den gia tri x" << endl;
    cout << "0. Thoat" << endl;
    cout << "Moi ban chon chuc nang: ";
}

// Hàm chọn và thực thi chức năng
void choose(node*& TREE, int& size) {
    int choice;
    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            int value;
            cout << "Nhap gia tri can them vao cay: ";
            cin >> value;
            add(TREE, value);
            break;
        case 2:
            importTree(TREE, size);
            break;
        case 3:
            printTree(TREE);
            break;
        case 4:
            findX(TREE);
            break;
        case 5:
            deleteX(TREE);
            break;
        case 6:
            cout << "So luong node trong cay: " << countNode(TREE) << endl;
            break;
        case 7:
            cout << "So luong node co hai nhanh trong cay: " << countNode_2branch(TREE) << endl;
            break;
        case 8:
            cout << "So luong node co mot nhanh trong cay: " << countNode_1branch(TREE) << endl;
            break;
        case 9:
            cout << "So luong node chi co nhanh phai trong cay: " << countNode_rightBranch(TREE) << endl;
            break;
        case 10:
            cout << "So luong node khong co nhanh trong cay: " << countNode_noBranch(TREE) << endl;
            break;
        case 11:
            cout << "Chieu cao cua cay: " << height(TREE) << endl;
            break;
        case 12:
            cout << "Cac gia tri chan trong cay: ";
            find_evenNode(TREE);
            cout << endl;
            break;
        case 13:
            find_greaterThanX(TREE);
            break;
        case 14:
            cout << "Gia tri lon nhat trong cay: " << maxValue(TREE) << endl;
            break;
        case 15:
            cout << "Gia tri lon nhat trong nhanh phai: " << maxValue_rightBranch(TREE) << endl;
            break;
        case 16:
            cout << "Cac node theo muc: ";
            printNode_level(TREE);
            cout << endl;
            break;
        case 17:
            int x;
            cout << "Nhap gia tri x: ";
            cin >> x;
            cout << "Chieu cao cua node co gia tri " << x << " la: " << heightX(TREE, x) << endl;
            break;
        case 18:
            findPath_X(TREE);
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le, vui long chon lai!" << endl;
        }
    }
}
