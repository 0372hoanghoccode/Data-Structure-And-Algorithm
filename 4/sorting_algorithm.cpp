#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int random(int, int);
void generator_random(int*, int);

void array_Generate(int*, int);
void array_Generate_Increase(int*, int);
void array_Export(int*, int);
void GenerateArray_and_Find();
void GenerateArray_and_Search();
void print_pair(int*, int);

int maxValue(int*, int);
int indexOf_maxValue(int*, int);
void indexesOf_maxValue(int*, int);

int IndexOf_X(int*, int, int);
int IndexOf_X_Improved(int*, int, int);
void IndexesOf_X(int*, int, int);
void find_IndexOf_X(int*, int, int);
void find_IndexOf_X_improved(int*, int, int);
void find_IndexsOf_X(int*, int, int);

int InterPolationSearch(int*, int, int);
void find_IndexOf_X_with_InterPolationSearch(int*, int, int);
void find_IndexsOf_X_with_InterPolationSearch(int*, int, int);

void Interchange_Sort(int*, int);
void Selection_Sort(int*, int);

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

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void generator_random(int* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = random(-1000, 1000);
}

void array_Generate(int* arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = random(-10000, 10000);
}

void array_Generate_Increase(int* arr, int size) {
    srand(time(NULL));
    if (size > 0) {
        arr[0] = rand() % 100;
        for (int i = 1; i < size; i++)
            arr[i] = arr[i - 1] + rand() % 100;
    }
}

void array_Export(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "_______________________________" << endl;
}

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

void print_pair(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++)
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        cout << endl;
    }
}

int maxValue(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int indexOf_maxValue(int* arr, int size) {
    int max = maxValue(arr, size);
    for (int i = 0; i < size; i++)
        if (arr[i] == max)
            return i;
    return -1;
}

void indexesOf_maxValue(int* arr, int size) {
    int max = maxValue(arr, size);
    cout << "Cac vi tri chua gia tri lon nhat gom: ";
    for (int i = 0; i < size; i++)
        if (arr[i] == max)
            cout << i << " ";
    cout << endl;
}

int IndexOf_X(int* arr, int size, int key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int IndexOf_X_Improved(int* arr, int size, int key) {
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = arr[i];
    temp[size] = key;
    int i;
    for (i = 0; temp[i] != key; i++);
    delete[] temp;
    if (i < size)
        return i;
    return -1;
}

void IndexesOf_X(int* arr, int size, int key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            cout << i << " ";
}

void find_IndexOf_X(int* arr, int size, int key) {
    clock_t begin, end;
    begin = clock();
    int index = IndexOf_X(arr, size, key);
    if (index == -1)
        cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
    else
        cout << "Gia tri x nam tai vi tri " << index << endl;
    end = clock();
    cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
}

void find_IndexOf_X_improved(int* arr, int size, int key) {
    clock_t begin, end;
    begin = clock();
    int index = IndexOf_X_Improved(arr, size, key);
    if (index == -1)
        cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
    else
        cout << "Gia tri x nam tai vi tri " << index << endl;
    end = clock();
    cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
}

void find_IndexsOf_X(int* arr, int size, int key) {
    if (IndexOf_X(arr, size, key) == -1)
        cout << "Gia tri x khong ton tai trong mang" << endl;
    else {
        cout << "Gia tri x nam tai vi tri ";
        IndexesOf_X(arr, size, key);
        cout << endl;
    }
}

int InterPolationSearch(int* arr, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        double mid1 = (double)(key - arr[left]) / (arr[right] - arr[left]);
        int mid2 = (right - left);
        int search_index = left + mid1 * mid2;
        if (arr[search_index] == key)
            return search_index;
        if (arr[search_index] < key)
            left = search_index + 1;
        else
            right = search_index - 1;
    }
    return -1;
}

void find_IndexOf_X_with_InterPolationSearch(int* arr, int size, int key) {
    clock_t begin, end;
    begin = clock();
    int index = InterPolationSearch(arr, size, key);
    if (index == -1)
        cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
    else
        cout << "Gia tri x nam tai vi tri " << index << endl;
    end = clock();
    cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
}

void find_IndexsOf_X_with_InterPolationSearch(int* arr, int size, int key) {
    if (InterPolationSearch(arr, size, key) == -1)
        cout << "Gia tri x khong ton tai trong mang" << endl;
    else {
        cout << "Gia tri x nam tai vi tri ";
        IndexesOf_X(arr, size, key);
        cout << endl;
    }
}

void Interchange_Sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
    cout << "Mang sau khi sap xep la: ";
    array_Export(arr, size);
}

void Selection_Sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[i], arr[min_index]);
    }
    cout << "Mang sau khi sap xep la: ";
    array_Export(arr, size);
}