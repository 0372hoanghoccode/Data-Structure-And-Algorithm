#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Hàm tạo số ngẫu nhiên trong khoảng từ min đến max
int random(int, int);

// Hàm tạo mảng ngẫu nhiên
void generator_random(int*, int);

// Các hàm tạo mảng
void array_Generate(int*, int);
void array_Generate_Increase(int*, int);

// Hàm xuất mảng ra màn hình
void array_Export(int*, int);

// Các hàm tạo và tìm kiếm giá trị trong mảng
void GenerateArray_and_Find();
void GenerateArray_and_Search();

// Hàm in các cặp giá trị trong mảng
void print_pair(int*, int);

// Các hàm tìm giá trị lớn nhất và vị trí của nó
int maxValue(int*, int);
int indexOf_maxValue(int*, int);
void indexesOf_maxValue(int*, int);

// Các hàm tìm vị trí của giá trị X trong mảng
int IndexOf_X(int*, int, int);
int IndexOf_X_Improved(int*, int, int);
void IndexesOf_X(int*, int, int);
void find_IndexOf_X(int*, int, int);
void find_IndexOf_X_improved(int*, int, int);
void find_IndexsOf_X(int*, int, int);

// Các hàm tìm kiếm sử dụng Interpolation Search
int InterPolationSearch(int*, int, int);
void find_IndexOf_X_with_InterPolationSearch(int*, int, int);
void find_IndexsOf_X_with_InterPolationSearch(int*, int, int);

// Các hàm sắp xếp
void Interchange_Sort(int*, int);
void Selection_Sort(int*, int);

// Hàm chọn lựa chức năng
void choose(int*, int);

int main() {
    int n;
    cout << "So luong phan tu la: ";
    cin >> n;
    int* array = new int[n];
    array_Generate(array, n);
    choose(array, n);
    delete[] array;
    return 0;
}

// Hàm chọn lựa chức năng để thực hiện
void choose(int* arr, int n) {
    while (true) {
        cout << "_______________________________" << endl;
        cout << "Nhap lua chon tuong ung theo de bai " << endl;
        cout << "Lua chon cua ban la: ";
        int choice, x;
        cin >> choice;
        switch (choice) {
            case 1:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                break;
            case 2:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                cout << "Gia tri lon nhat trong mang la " << maxValue(arr, n) << endl;
                break;
            case 3:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                cout << "Vi tri chua gia tri lon nhat trong mang la " << indexOf_maxValue(arr, n) << endl;
                break;
            case 4:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                indexesOf_maxValue(arr, n);
                break;
            case 5:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                cout << "Gia tri X can tim la: ";
                cin >> x;
                find_IndexOf_X(arr, n, x);
                break;
            case 6:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                cout << "Gia tri X can tim la: ";
                cin >> x;
                find_IndexOf_X_improved(arr, n, x);
                break;
            case 7:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                array_Export(arr, n);
                cout << "Gia tri X can tim la: ";
                cin >> x;
                find_IndexsOf_X(arr, n, x);
                break;
            case 8:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                GenerateArray_and_Find();
                break;
            case 9:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                GenerateArray_and_Search();
                break;
            case 10:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                print_pair(arr, n);
                break;
            case 11:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                Interchange_Sort(arr, n);
                break;
            case 12:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                Selection_Sort(arr, n);
                break;
            default:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                cout << "Lua chon khong hop le, hay nhap lai" << endl;
                break;
        }
    }
}

// Hàm tạo số ngẫu nhiên trong khoảng từ min đến max
int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

// Hàm tạo mảng ngẫu nhiên
void generator_random(int* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = random(-1000, 1000);
}

// Hàm tạo mảng ngẫu nhiên
void array_Generate(int* arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = random(-10000, 10000);
}

// Hàm tạo mảng tăng dần ngẫu nhiên
void array_Generate_Increase(int* arr, int size) {
    srand(time(NULL));
    if (size > 0) {
        arr[0] = rand() % 100;
        for (int i = 1; i < size; i++)
            arr[i] = arr[i - 1] + rand() % 100;
    }
}

// Hàm xuất mảng ra màn hình
void array_Export(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "_______________________________" << endl;
}

// Hàm tạo và tìm kiếm giá trị trong mảng
void GenerateArray_and_Find() {
    int n;
    cout << "So luong phan tu la: ";
    cin >> n;
    int* array = new int[n];
    array_Generate_Increase(array, n);
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    array_Export(array, n);
    int x;
    cout << "Gia tri x can tim la: ";
    cin >> x;
    cout << "Tim kiem tuyen tinh: " << endl << "  ";
    find_IndexOf_X(array, n, x);
    cout << "_______" << endl;
    cout << "Tim kiem tuyen tinh cai tien: " << endl << "  ";
    find_IndexOf_X_improved(array, n, x);
    cout << "_______" << endl;
    cout << "Tim tat ca cac vi tri cua x: " << endl << "  ";
    find_IndexsOf_X(array, n, x);
    delete[] array;
}

// Hàm tạo và tìm kiếm giá trị trong mảng sử dụng Interpolation Search
void GenerateArray_and_Search() {
    int n;
    cout << "So luong phan tu la: ";
    cin >> n;
    int* array = new int[n];
    array_Generate_Increase(array, n);
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    array_Export(array, n);
    int x;
    cout << "Gia tri x can tim la: ";
    cin >> x;
    InterPolationSearch(array, n, x);
    cout << "_______" << endl;
    find_IndexOf_X_with_InterPolationSearch(array, n, x);
    cout << "_______" << endl;
    find_IndexsOf_X_with_InterPolationSearch(array, n, x);
    delete[] array;
}

// Hàm in các cặp giá trị trong mảng
void print_pair(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++)
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        cout << endl;
    }
}

// Hàm tìm giá trị lớn nhất trong mảng
int maxValue(int* arr, int size) {
    return *max_element(arr, arr + size);
}

// Hàm tìm vị trí của giá trị lớn nhất trong mảng
int indexOf_maxValue(int* arr, int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }
    return maxIdx;
}

// Hàm tìm tất cả các vị trí của giá trị lớn nhất trong mảng
void indexesOf_maxValue(int* arr, int size) {
    int maxVal = maxValue(arr, size);
    for (int i = 0; i < size; i++) {
        if (arr[i] == maxVal)
            cout << i << " ";
    }
    cout << endl;
}

// Hàm tìm vị trí của giá trị X trong mảng
int IndexOf_X(int* arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Hàm cải tiến tìm vị trí của giá trị X trong mảng
int IndexOf_X_Improved(int* arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;
        if (arr[i] > x)
            return -1;
    }
    return -1;
}

// Hàm tìm tất cả các vị trí của giá trị X trong mảng
void IndexesOf_X(int* arr, int size, int x) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
    else
        cout << endl;
}

// Hàm tìm vị trí của giá trị X trong mảng và in ra kết quả
void find_IndexOf_X(int* arr, int size, int x) {
    int index = IndexOf_X(arr, size, x);
    if (index != -1)
        cout << "Gia tri " << x << " xuat hien dau tien o vi tri " << index << endl;
    else
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
}

// Hàm cải tiến tìm vị trí của giá trị X trong mảng và in ra kết quả
void find_IndexOf_X_improved(int* arr, int size, int x) {
    int index = IndexOf_X_Improved(arr, size, x);
    if (index != -1)
        cout << "Gia tri " << x << " xuat hien dau tien o vi tri " << index << endl;
    else
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
}

// Hàm tìm tất cả các vị trí của giá trị X trong mảng và in ra kết quả
void find_IndexsOf_X(int* arr, int size, int x) {
    IndexesOf_X(arr, size, x);
}

// Hàm tìm vị trí của giá trị X trong mảng sử dụng Interpolation Search
int InterPolationSearch(int* arr, int size, int x) {
    int low = 0, high = size - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

// Hàm tìm vị trí của giá trị X trong mảng và in ra kết quả sử dụng Interpolation Search
void find_IndexOf_X_with_InterPolationSearch(int* arr, int size, int x) {
    int index = InterPolationSearch(arr, size, x);
    if (index != -1)
        cout << "Gia tri " << x << " xuat hien dau tien o vi tri " << index << endl;
    else
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
}

// Hàm tìm tất cả các vị trí của giá trị X trong mảng và in ra kết quả sử dụng Interpolation Search
void find_IndexsOf_X_with_InterPolationSearch(int* arr, int size, int x) {
    bool found = false;
    int low = 0, high = size - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));
        if (arr[pos] == x) {
            cout << pos << " ";
            found = true;
            int left = pos - 1;
            while (left >= low && arr[left] == x) {
                cout << left << " ";
                left--;
            }
            int right = pos + 1;
            while (right <= high && arr[right] == x) {
                cout << right << " ";
                right++;
            }
            cout << endl;
            return;
        }
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    if (!found)
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
}

// Hàm sắp xếp mảng sử dụng Interchange Sort
void Interchange_Sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    array_Export(arr, size);
}

// Hàm sắp xếp mảng sử dụng Selection Sort
void Selection_Sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
    array_Export(arr, size);
}
