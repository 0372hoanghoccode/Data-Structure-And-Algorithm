#include <iostream> 
using namespace std; 

// Khai báo nguyên mẫu hàm (function prototypes)
void input(int[], int);                  // Hàm nhập các phần tử mảng
void output(int[], int);                 // Hàm xuất các phần tử mảng

void deleteElementAtPositionK(int[], int&); // Hàm xóa phần tử tại vị trí K
void getMaxValue(int[], int);            // Hàm tìm giá trị lớn nhất trong mảng
void getMinValue(int[], int);            // Hàm tìm giá trị nhỏ nhất trong mảng

void getMinusCount(int[], int);          // Hàm đếm số phần tử âm trong mảng

void getMaxMinusValue(int[], int);       // Hàm tìm giá trị âm lớn nhất trong mảng
void getMinPositiveValue(int[], int);    // Hàm tìm giá trị dương nhỏ nhất trong mảng

void findValuesEqualToX(int[], int&);    // Hàm tìm phần tử có giá trị bằng X
void countValuesEqualToX(int[], int);    // Hàm đếm số phần tử có giá trị bằng X

void printMenu();                        // Hàm in menu lựa chọn
void choose(int[], int&);                // Hàm xử lý lựa chọn từ menu

int main()
{
    int arrSize;                         // Khai báo biến lưu kích thước mảng
    cout << "n = ";                      // Xuất thông báo yêu cầu nhập kích thước mảng
    cin >> arrSize;                      // Nhập kích thước mảng từ bàn phím
    system("cls");                       // Xóa màn hình (trên Windows)

    int* arr = new int[arrSize];         // Cấp phát bộ nhớ động cho mảng

    input(arr, arrSize);                 // Gọi hàm nhập các phần tử mảng
    system("cls");                       // Xóa màn hình

    choose(arr, arrSize);                // Gọi hàm xử lý lựa chọn từ menu

    delete[] arr;                        // Giải phóng bộ nhớ đã cấp phát cho mảng
    return 0;                            // Kết thúc chương trình, trả về 0
}

// Hàm in menu lựa chọn
void printMenu() {
    cout << "\n--------------------------------------------------" << endl;
    cout << "1. Xuat mang" << endl;                   // In lựa chọn xuất mảng
    cout << "2. Xoa phan tu tai vi tri x trong mang" << endl; // In lựa chọn xóa phần tử tại vị trí x
    cout << "3. Liet ke nhung phan tu co gia tri lon nhat trong mang" << endl; // In lựa chọn liệt kê phần tử lớn nhất
    cout << "4. Liet ke nhung phan tu co gia tri nho nhat trong mang" << endl; // In lựa chọn liệt kê phần tử nhỏ nhất
    cout << "5. Dem so phan tu co gia tri am trong mang" << endl; // In lựa chọn đếm số phần tử âm
    cout << "6. Cho biet gia tri am lon nhat trong mang" << endl; // In lựa chọn tìm giá trị âm lớn nhất
    cout << "7. Cho biet gia tri duong nho nhat trong mang" << endl; // In lựa chọn tìm giá trị dương nhỏ nhất
    cout << "8. Tim phan tu co gia tri bang x co hay khong trong mang" << endl; // In lựa chọn tìm phần tử bằng x
    cout << "9. Dem so phan tu co gia tri bang x trong mang" << endl; // In lựa chọn đếm số phần tử bằng x
    cout << "0. Thoat" << endl; // In lựa chọn thoát chương trình
    cout << "--------------------------------------------------" << endl;
}

// Hàm xử lý lựa chọn từ menu
void choose(int arr[], int& arrSize) {
    int choice; // Khai báo biến lưu lựa chọn
    do {
        printMenu(); // In menu
        cout << "Nhap tuy chon: "; // Yêu cầu người dùng nhập lựa chọn
        cin >> choice; // Nhập lựa chọn từ bàn phím
        system("cls"); // Xóa màn hình

        // Xử lý lựa chọn dựa vào giá trị của biến choice
        switch (choice) {
        case 1:
            output(arr, arrSize); // Gọi hàm xuất mảng
            break;
        case 2:
            deleteElementAtPositionK(arr, arrSize); // Gọi hàm xóa phần tử tại vị trí K
            break;
        case 3:
            getMaxValue(arr, arrSize); // Gọi hàm tìm giá trị lớn nhất
            break;
        case 4:
            getMinValue(arr, arrSize); // Gọi hàm tìm giá trị nhỏ nhất
            break;
        case 5:
            getMinusCount(arr, arrSize); // Gọi hàm đếm số phần tử âm
            break;
        case 6:
            getMaxMinusValue(arr, arrSize); // Gọi hàm tìm giá trị âm lớn nhất
            break;
        case 7:
            getMinPositiveValue(arr, arrSize); // Gọi hàm tìm giá trị dương nhỏ nhất
            break;
        case 8:
            findValuesEqualToX(arr, arrSize); // Gọi hàm tìm phần tử bằng X
            break;
        case 9:
            countValuesEqualToX(arr, arrSize); // Gọi hàm đếm số phần tử bằng X
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl; // Thông báo thoát chương trình
            break;
        default:
            cout << "Khong ton tai lua chon" << endl; // Thông báo lựa chọn không hợp lệ
            break;
        }
        cout << endl; // In dòng trống
    } while (choice != 0); // Lặp lại nếu lựa chọn không phải là 0
}

// Hàm nhập các phần tử mảng
void input(int arr[], int arrSize) {
    cout << "Nhap mang co " << arrSize << " phan tu: " << endl; // Thông báo nhập mảng
    for (int i = 0; i < arrSize; i++)
    {
        cout << "a[" << i << "] = "; // Thông báo nhập phần tử thứ i
        cin >> arr[i]; // Nhập giá trị phần tử thứ i
    }
}

// Hàm xuất các phần tử mảng
void output(int arr[], int arrSize) {
    cout << "Mang nhap vao la: "; // Thông báo xuất mảng
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " "; // Xuất giá trị từng phần tử trong mảng
    cout << endl; // Xuất dòng trống
}

// Hàm xóa phần tử tại vị trí K
void deleteElementAtPositionK(int arr[], int& arrSize) {
    cout << "k = "; // Yêu cầu nhập vị trí K
    int k;
    cin >> k; // Nhập vị trí K
    system("cls"); // Xóa màn hình
    cout << "Mang sau khi xoa phan tu tai vi tri thu " << k << " la: "; // Thông báo kết quả
    if (arrSize <= 0) { // Nếu mảng rỗng
        return; // Kết thúc hàm
    }
    if (k < 0) // Nếu K nhỏ hơn 0
        k = 0; // Gán K bằng 0
    else if (k >= arrSize) // Nếu K lớn hơn hoặc bằng kích thước mảng
        k = arrSize - 1; // Gán K bằng vị trí cuối cùng
    for (int i = k; i < arrSize - 1; i++) // Dịch chuyển các phần tử
        arr[i] = arr[i + 1];
    --arrSize; // Giảm kích thước mảng
    for (int i = 0; i < arrSize; i++) // Xuất mảng sau khi xóa
        cout << arr[i] << " ";
    cout << endl; // Xuất dòng trống
}

// Hàm tìm giá trị lớn nhất trong mảng
void getMaxValue(int arr[], int arrSize) {
    int temp = arr[0]; // Giả sử phần tử đầu tiên là lớn nhất
    for (int i = 1; i < arrSize; i++)
        if (arr[i] >= temp)
            temp = arr[i]; // Cập nhật giá trị lớn nhất nếu tìm thấy
    cout << "Cac phan tu co gia tri lon nhat trong mang tai vi tri ";
    for (int i = 0; i < arrSize; i++)
        if (arr[i] == temp)
            cout << i << " "; // Xuất vị trí các phần tử có giá trị lớn nhất
    cout << endl; // Xuất dòng trống
}

// Hàm tìm giá trị nhỏ nhất trong mảng
void getMinValue(int arr[], int arrSize) {
    int temp = arr[0]; // Giả sử phần tử đầu tiên là nhỏ nhất
    for (int i = 1; i < arrSize; i++)
        if (arr[i] < temp)
            temp = arr[i]; // Cập nhật giá trị nhỏ nhất nếu tìm thấy
    cout << "Cac phan tu co gia tri nho nhat trong mang tai vi tri ";
    for (int i = 0; i < arrSize; i++)
        if (arr[i] == temp)
            cout << i << " "; // Xuất vị trí các phần tử có giá trị nhỏ nhất
    cout << endl; // Xuất dòng trống
}

// Hàm đếm số phần tử âm trong mảng
void getMinusCount(int arr[], int arrSize) {
    int temp = 0; // Khởi tạo biến đếm
    for (int i = 0; i < arrSize; i++)
        if (arr[i] < 0)
            temp++; // Tăng biến đếm nếu phần tử âm
    cout << "So phan tu am trong mang la " << temp << endl; // Xuất kết quả
}

// Hàm tìm giá trị âm lớn nhất trong mảng
void getMaxMinusValue(int arr[], int arrSize) {
    int temp = INT_MIN; // Khởi tạo biến lưu giá trị âm lớn nhất
    bool found = false; // Biến đánh dấu có tìm thấy phần tử âm hay không
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < 0 && arr[i] > temp) {
            temp = arr[i];
            found = true; // Nếu tìm thấy phần tử âm lớn nhất thì cập nhật biến
        }
    }
    if (found) {
        cout << "Phan tu am lon nhat trong mang la " << temp << endl; // Xuất giá trị âm lớn nhất
    } else {
        cout << "Khong co phan tu am trong mang" << endl; // Thông báo không có phần tử âm
    }
}

// Hàm tìm giá trị dương nhỏ nhất trong mảng
void getMinPositiveValue(int arr[], int arrSize) {
    int temp = INT_MAX; // Khởi tạo biến lưu giá trị dương nhỏ nhất
    bool found = false; // Biến đánh dấu có tìm thấy phần tử dương hay không
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0 && arr[i] < temp) {
            temp = arr[i];
            found = true; // Nếu tìm thấy phần tử dương nhỏ nhất thì cập nhật biến
        }
    }
    if (found) {
        cout << "Phan tu duong nho nhat trong mang la " << temp << endl; // Xuất giá trị dương nhỏ nhất
    } else {
        cout << "Khong co phan tu duong trong mang" << endl; // Thông báo không có phần tử dương
    }
}

// Hàm tìm phần tử có giá trị bằng X trong mảng
void findValuesEqualToX(int arr[], int& arrSize) {
    cout << "x = "; // Yêu cầu nhập giá trị X
    int x;
    cin >> x; // Nhập giá trị X
    system("cls"); // Xóa màn hình
    bool found = false; // Biến đánh dấu có tìm thấy phần tử bằng X hay không
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == x) {
            found = true; // Nếu tìm thấy phần tử bằng X thì cập nhật biến
            break;
        }
    }
    if (found) {
        cout << "Phan tu co gia tri " << x << " co trong mang" << endl; // Thông báo tìm thấy phần tử
    } else {
        cout << "Phan tu co gia tri " << x << " khong co trong mang" << endl; // Thông báo không tìm thấy phần tử
    }
}

// Hàm đếm số phần tử có giá trị bằng X trong mảng
void countValuesEqualToX(int arr[], int arrSize) {
    cout << "x = "; // Yêu cầu nhập giá trị X
    int x;
    cin >> x; // Nhập giá trị X
    system("cls"); // Xóa màn hình
    int temp = 0; // Khởi tạo biến đếm
    for (int i = 0; i < arrSize; i++)
        if (arr[i] == x)
            temp++; // Tăng biến đếm nếu phần tử bằng X
    if (temp > 0)
        cout << "So phan tu co gia tri " << x << " co trong mang la " << temp << endl; // Xuất kết quả
    else
        cout << "Phan tu co gia tri " << x << " khong co trong mang" << endl; // Thông báo không tìm thấy phần tử
}
