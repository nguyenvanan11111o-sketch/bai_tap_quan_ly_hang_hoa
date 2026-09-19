#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Cau truc ngay thang nam
struct Ngay {
    int ngay, thang, nam;
};

// Cau truc hang hoa
struct HangHoa {
    string ma;
    string ten;
    Ngay ngayXuat;
    double gia;
};

// Cau 2: Nhap mang n hang hoa
void Nhap(HangHoa a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap hang hoa thu " << i + 1 << ":\n";

        cout << "Ma hang: ";
        getline(cin >> ws, a[i].ma);

        cout << "Ten hang: ";
        getline(cin >> ws, a[i].ten);

        cout << "Ngay xuat hang (ngay thang nam): ";
        cin >> a[i].ngayXuat.ngay
            >> a[i].ngayXuat.thang
            >> a[i].ngayXuat.nam;

        cout << "Gia xuat hang (trieu dong): ";
        cin >> a[i].gia;
    }
}

// Cau 3: Xuat mang n hang hoa
void Xuat(HangHoa a[], int n) {
    cout << "\n";
    cout << left
         << setw(12) << "Ma hang"
         << setw(25) << "Ten hang"
         << setw(15) << "Ngay xuat"
         << setw(15) << "Gia (trieu)"
         << endl;

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(12) << a[i].ma
             << setw(25) << a[i].ten;

        cout << setfill('0')
             << setw(2) << a[i].ngayXuat.ngay << "/"
             << setw(2) << a[i].ngayXuat.thang << "/"
             << setw(4) << a[i].ngayXuat.nam;

        cout << setfill(' ') << "   "
             << fixed << setprecision(2)
             << a[i].gia << endl;
    }
}

// Ham hoan doi hai hang hoa
void HoanVi(HangHoa &a, HangHoa &b) {
    HangHoa temp = a;
    a = b;
    b = temp;
}

// Cau 4: Sap xep chon truc tiep tang dan theo gia
void SelectionSort(HangHoa a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j].gia < a[min].gia) {
                min = j;
            }
        }

        if (min != i) {
            HoanVi(a[i], a[min]);
        }
    }
}

// Cau 5: Tim kiem nhi phan theo gia
int BinarySearch(HangHoa a[], int n, double X) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid].gia == X) {
            return mid;
        }
        else if (a[mid].gia < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

// Cau 6: Ham main
int main() {
    int n;
    HangHoa a[100];

    cout << "Nhap so luong hang hoa: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong khong hop le!";
        return 0;
    }

    // Nhap hang hoa
    Nhap(a, n);

    // Xuat danh sach vua nhap
    cout << "\n===== DANH SACH HANG HOA VUA NHAP =====";
    Xuat(a, n);

    // Sap xep tang dan theo gia
    SelectionSort(a, n);

    cout << "\n===== DANH SACH SAU KHI SAP XEP =====";
    Xuat(a, n);

    // Nhap gia can tim
    double X;
    cout << "\nNhap gia hang hoa can tim X: ";
    cin >> X;

    // Tim kiem nhi phan
    int vt = BinarySearch(a, n, X);

    if (vt == -1) {
        cout << "\nKhong tim thay hang hoa co gia " << X;
    }
    else {
        cout << "\nTim thay hang hoa:\n";
        Xuat(&a[vt], 1);
    }

    return 0;
}
