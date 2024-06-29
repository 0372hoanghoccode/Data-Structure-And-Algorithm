#include <iostream>
#define MAX 10
using namespace std;

struct StackArray
{
    int s[MAX]; // Mảng chứa các phần tử của stack
    int top;    // Chỉ số của phần tử trên cùng của stack
};

struct Node
{
    int data;   // Dữ liệu lưu trữ trong node
    Node *next; // Con trỏ đến node tiếp theo
};

struct StackList
{
    Node *head; // Con trỏ đến node đầu của stack
    Node *tail; // Con trỏ đến node cuối của stack
};

// Menu
int ChooseStackType(); // Hàm chọn loại stack (mảng hay danh sách liên kết)
int ChooseMenuOption(); // Hàm chọn chức năng cho stack
void HandleStackArray(StackArray &stack); // Xử lý stack sử dụng mảng
void HandleStackList(StackList &stack); // Xử lý stack sử dụng danh sách liên kết

// Hàm khởi tạo và thao tác với stack mảng
void CreateStack(StackArray &stack);
void Push(StackArray &stack, int x);
bool Pop(StackArray &stack, int &x);
bool IsEmpty(StackArray stack);
int CountElements(StackArray stack);
void ClearStack(StackArray &stack);
void DisplayStack(StackArray stack);

// Hàm khởi tạo và thao tác với stack danh sách liên kết
void CreateStack(StackList &stack);
void Push(StackList &stack, int x);
bool Pop(StackList &stack, int &x);
bool IsEmpty(StackList stack);
int CountElements(StackList stack);
void ClearStack(StackList &stack);
void DisplayStack(StackList stack);
Node* CreateNode(int x); // Hàm tạo node mới

int main()
{
    StackArray stackA;
    StackList stackL;
    bool running = true;
    int choice;

    while (running)
    {
        choice = ChooseStackType();
        switch (choice)
        {
        case 1:
            HandleStackArray(stackA);
            break;
        case 2:
            HandleStackList(stackL);
            break;
        case 0:
            cout << "Tam biet!\n";
            running = false;
            break;
        default:
            cout << "Lua chon khong hop le, vui long thu lai.\n";
            break;
        }
    }
    return 0;
}

int ChooseStackType()
{
    int choice;
    cout << "\nChon loai stack:\n";
    cout << "1. Stack su dung mang\n";
    cout << "2. Stack su dung DSLK\n";
    cout << "0. Thoat\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    return choice;
}

int ChooseMenuOption()
{
    int option;
    cout << "\nChon thao tac:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Kiem tra stack co rong khong\n";
    cout << "4. Dem so phan tu\n";
    cout << "5. Xoa stack\n";
    cout << "0. Thoat\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> option;
    return option;
}

// Hàm khởi tạo stack mảng
void CreateStack(StackArray &stack)
{
    stack.top = -1;
}

// Hàm thêm phần tử vào stack mảng
void Push(StackArray &stack, int x)
{
    if (stack.top == MAX - 1)
    {
        cout << "Stack đã đầy!\n";
        return;
    }
    stack.s[++stack.top] = x;
}

// Hàm lấy phần tử từ stack mảng
bool Pop(StackArray &stack, int &x)
{
    if (IsEmpty(stack))
    {
        cout << "Stack rỗng!\n";
        return false;
    }
    x = stack.s[stack.top--];
    return true;
}

// Hàm kiểm tra stack mảng có rỗng không
bool IsEmpty(StackArray stack)
{
    return stack.top == -1;
}

// Hàm đếm số phần tử trong stack mảng
int CountElements(StackArray stack)
{
    return stack.top + 1;
}

// Hàm xóa stack mảng
void ClearStack(StackArray &stack)
{
    stack.top = -1;
}

// Hàm hiển thị stack mảng
void DisplayStack(StackArray stack)
{
    for (int i = 0; i <= stack.top; i++)
    {
        cout << stack.s[i] << " ";
    }
    cout << endl;
}

// Hàm khởi tạo stack danh sách liên kết
void CreateStack(StackList &stack)
{
    stack.head = stack.tail = nullptr;
}

// Hàm thêm phần tử vào stack danh sách liên kết
void Push(StackList &stack, int x)
{
    Node *node = CreateNode(x);
    if (stack.head == nullptr)
    {
        stack.head = stack.tail = node;
    }
    else
    {
        stack.tail->next = node;
        stack.tail = node;
    }
}

// Hàm lấy phần tử từ stack danh sách liên kết
bool Pop(StackList &stack, int &x)
{
    if (IsEmpty(stack))
    {
        cout << "Stack rỗng!\n";
        return false;
    }
    Node *temp = stack.head;
    if (stack.head == stack.tail)
    {
        x = stack.head->data;
        delete stack.head;
        stack.head = stack.tail = nullptr;
    }
    else
    {
        while (temp->next != stack.tail)
        {
            temp = temp->next;
        }
        x = stack.tail->data;
        delete stack.tail;
        stack.tail = temp;
        stack.tail->next = nullptr;
    }
    return true;
}

// Hàm kiểm tra stack danh sách liên kết có rỗng không
bool IsEmpty(StackList stack)
{
    return stack.head == nullptr;
}

// Hàm đếm số phần tử trong stack danh sách liên kết
int CountElements(StackList stack)
{
    int count = 0;
    Node *temp = stack.head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hàm xóa stack danh sách liên kết
void ClearStack(StackList &stack)
{
    Node *temp;
    while (stack.head != nullptr)
    {
        temp = stack.head;
        stack.head = stack.head->next;
        delete temp;
    }
    stack.tail = nullptr;
}

// Hàm hiển thị stack danh sách liên kết
void DisplayStack(StackList stack)
{
    Node *temp = stack.head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm tạo node mới cho stack danh sách liên kết
Node* CreateNode(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = nullptr;
    return node;
}

// Hàm xử lý cho stack sử dụng mảng
void HandleStackArray(StackArray &stack)
{
    CreateStack(stack);
    cout << "Ban dang lam viec voi Stack su dung mang.\n";
    int choice;
    int x;
    while (true)
    {
        choice = ChooseMenuOption();
        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri can them vao stack: ";
            cin >> x;
            Push(stack, x);
            cout << "Stack sau khi push: ";
            DisplayStack(stack);
            break;
        case 2:
            if (Pop(stack, x))
            {
                cout << "Gia tri lay duoc khi pop la: " << x << endl;
                cout << "Stack sau khi pop: ";
                DisplayStack(stack);
            }
            break;
        case 3:
            cout << (IsEmpty(stack) ? "Stack rong.\n" : "Stack khong rong.\n");
            break;
        case 4:
            cout << "So luong phan tu trong stack: " << CountElements(stack) << endl;
            break;
        case 5:
            ClearStack(stack);
            cout << "Stack da duoc xoa.\n";
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le, vui long thu lai.\n";
            break;
        }
    }
}

// Hàm xử lý cho stack sử dụng danh sách liên kết
void HandleStackList(StackList &stack)
{
    CreateStack(stack);
    cout << "Ban dang lam viec voi Stack su dung DSLK.\n";
    int choice;
    int x;
    while (true)
    {
        choice = ChooseMenuOption();
        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri can them vao stack: ";
            cin >> x;
            Push(stack, x);
            cout << "Stack sau khi push: ";
            DisplayStack(stack);
            break;
        case 2:
            if (Pop(stack, x))
            {
                cout << "Gia tri lay duoc khi pop la: " << x << endl;
                cout << "Stack sau khi pop: ";
                DisplayStack(stack);
            }
            break;
        case 3:
            cout << (IsEmpty(stack) ? "Stack rong.\n" : "Stack khong rong.\n");
            break;
        case 4:
            cout << "So luong phan tu trong stack: " << CountElements(stack) << endl;
            break;
        case 5:
            ClearStack(stack);
            cout << "Stack da duoc xoa.\n";
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le, vui long thu lai.\n";
            break;
        }
    }
}
