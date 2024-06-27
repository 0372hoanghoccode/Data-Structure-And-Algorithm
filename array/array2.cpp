#include <iostream> 
#include <string> 
using namespace std; 

// Định nghĩa lớp student
class student {
public:
    string name; // Tên sinh viên
    string ID;   // Mã sinh viên
    double score; // Điểm trung bình
public:
    // Hàm nhập thông tin sinh viên
    void import() {
        cout << "Ten sinh vien: ";
        getline(cin >> ws, name); // Nhập tên sinh viên (ws để loại bỏ ký tự trắng thừa)
        cout << "Ma sinh vien: ";
        getline(cin, ID); // Nhập mã sinh viên
        cout << "Diem trung binh: ";
        cin >> score; // Nhập điểm trung bình
        while (score < 0 || score > 10) // Kiểm tra điểm hợp lệ
        {
            cout << "Diem trung binh khong hop le, hay nhap lai" << endl;
            cout << "Diem trung binh: ";
            cin >> score; // Nhập lại điểm trung bình nếu không hợp lệ
        }
        cout << endl;
    }
    // Hàm xuất thông tin sinh viên
    void infoExport() {
        cout << "Ten sinh vien: " << name << endl;
        cout << "Ma sinh vien: " << ID << endl;
        cout << "Diem trung binh: " << score << endl;
    }
};

// Khai báo các hàm xử lý
void arrayImport(student x[], int y);  // Hàm nhập danh sách sinh viên
void arrayExport(student x[], int y);  // Hàm xuất danh sách sinh viên

void maxExport(student x[], int y);    // Hàm liệt kê sinh viên có điểm cao nhất

void find_Above5(student x[], int y);  // Hàm tìm sinh viên có điểm >= 5
void find_student(student x[], int y); // Hàm tìm sinh viên theo tên

void delete_student(student x[], int& y); // Hàm xóa sinh viên theo mã
void add_student(student*& x, int& y);    // Hàm thêm sinh viên vào danh sách

// Hàm chính
int main()
{
    int n, x;
    cout << "So sinh vien la: ";
    cin >> n; // Nhập số lượng sinh viên
    student* sinhVien = new student[n]; // Cấp phát động mảng sinh viên
    arrayImport(sinhVien, n); // Nhập thông tin danh sách sinh viên

    // In menu lựa chọn
    cout << endl;
    cout << "1. In danh sach sinh vien" << endl;
    cout << "2. Liet ke cac sinh vien co diem trung binh cao nhat lop" << endl;
    cout << "3. Cho biet so sinh vien co diem trung binh tu 5 tro len" << endl;
    cout << "4. Tim sinh vien co ten X trong lop" << endl;
    cout << "5. Xoa sinh vien co ma so cho truoc" << endl;
    cout << "6. Them mot sinh vien vao lop hoc" << endl;
    cout << "0. Thoat" << endl;
    cout << endl;

    // Nhập lựa chọn từ người dùng
    cout << "Nhap tuy chon: ";
    cin >> x;
    cout << endl;

    // Xử lý lựa chọn từ menu
    while (x != 0)
    {
        switch (x) {
        case 1:
            arrayExport(sinhVien, n); // Xuất danh sách sinh viên
            break;
        case 2:
            maxExport(sinhVien, n); // Liệt kê sinh viên có điểm cao nhất
            break;
        case 3:
            find_Above5(sinhVien, n); // Tìm sinh viên có điểm >= 5
            break;
        case 4:
            find_student(sinhVien, n); // Tìm sinh viên theo tên
            break;
        case 5:
            delete_student(sinhVien, n); // Xóa sinh viên theo mã
            break;
        case 6:
            add_student(sinhVien, n); // Thêm sinh viên vào danh sách
            break;
        default:
            cout << "Khong ton tai lua chon" << endl; // Thông báo nếu lựa chọn không hợp lệ
            break;
        }
        cout << "Nhap tuy chon: ";
        cin >> x; // Nhập lựa chọn mới từ người dùng
        cout << endl;
    }

    delete[] sinhVien; // Giải phóng bộ nhớ động
    return 0; // Kết thúc chương trình
}

// Hàm nhập danh sách sinh viên
void arrayImport(student x[], int y) {
    cout << endl << "Nhap danh sach sinh vien: " << endl << endl;
    for (int i = 0; i < y; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ": " << endl;
        x[i].import(); // Nhập thông tin từng sinh viên
    }
}

// Hàm xuất danh sách sinh viên
void arrayExport(student x[], int y) {
    cout << "Danh sach sinh vien vua nhap la: " << endl;
    for (int i = 0; i < y; i++)
    {
        x[i].infoExport(); // Xuất thông tin từng sinh viên
        cout << endl << endl;
    }
}

// Hàm liệt kê sinh viên có điểm cao nhất
void maxExport(student x[], int y) {
    cout << "Cac sinh vien co diem trung binh cao nhat la: " << endl;
    double max = x[0].score; // Giả sử sinh viên đầu tiên có điểm cao nhất
    for (int i = 1; i < y; i++)
        if (x[i].score > max)
            max = x[i].score; // Tìm điểm cao nhất
    for (int i = 0; i < y; i++)
        if (x[i].score == max)
            cout << " " << x[i].name << endl; // In tên sinh viên có điểm cao nhất
    cout << endl;
}

// Hàm tìm sinh viên có điểm >= 5
void find_Above5(student x[], int y) {
    int temp = 0;
    for (int i = 0; i < y; i++)
        if (x[i].score >= 5)
            temp += 1; // Đếm số sinh viên có điểm >= 5
    if (temp > 0)
        cout << "So sinh vien co diem trung binh tu 5 tro len la " << temp << endl << endl;
    else
        cout << "Khong co sinh vien nao co diem trung binh tu 5 tro len." << endl << endl;
}

// Hàm tìm sinh viên theo tên
void find_student(student x[], int y) {
    string name;
    cout << "Nhap ten sinh vien can tim: ";
    getline(cin >> ws, name); // Nhập tên sinh viên cần tìm (ws để loại bỏ ký tự trắng thừa)
    for (int i = 0; i < y; i++)
        if (x[i].name == name)
        {
            cout << "Thong tin cua sinh vien can tim la: " << endl;
            x[i].infoExport(); // Xuất thông tin sinh viên tìm thấy
            cout << endl << endl;
            return;
        }
    cout << "Sinh vien khong ton tai" << endl; // Thông báo nếu không tìm thấy sinh viên
    cout << endl << endl;
}

// Hàm xóa sinh viên theo mã
void delete_student(student x[], int& y) {
    string ID;
    cout << "Nhap ma sinh vien can xoa: ";
    getline(cin >> ws, ID); // Nhập mã sinh viên cần xóa (ws để loại bỏ ký tự trắng thừa)
    for (int i = 0; i < y; i++)
        if (x[i].ID == ID)
        {
            y--; // Giảm số lượng sinh viên
            cout << "Da xoa sinh vien co ma " << x[i].ID << " khoi danh sach" << endl;
            for (int j = i; j < y; j++)
                x[j] = x[j + 1]; // Dịch chuyển các sinh viên còn lại
            return;
        }
    cout << "Sinh vien khong ton tai" << endl; // Thông báo nếu không tìm thấy sinh viên
    cout << endl;
}

// Hàm thêm sinh viên vào danh sách
void add_student(student*& x, int& y) {
    student* newArray = new student[y + 1]; // Cấp phát bộ nhớ mới cho mảng sinh viên
    for (int i = 0; i < y; i++)
        newArray[i] = x[i]; // Sao chép dữ liệu cũ vào mảng mới
    delete[] x; // Giải phóng bộ nhớ cũ
    x = newArray; // Gán con trỏ mảng mới
    y++; // Tăng số lượng sinh viên
    cout << "Nhap thong tin sinh vien can them: " << endl;
    x[y - 1].import(); // Nhập thông tin sinh viên mới
    cout << endl;
}
