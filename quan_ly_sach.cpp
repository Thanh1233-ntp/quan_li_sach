#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;
struct MatHang {
    int stt;
    string maSach;
    string tenSach;
    int soLuongTon;
    double donGiaTon;
    double donGiaBan;
    double thanhTien;
};


int timViTriTheoMaSach(MatHang danhSach[], int soLuong, const string& maSach)
 {
    for (int i = 0; i < soLuong; i++) 
	{
        if (danhSach[i].maSach == maSach) 
		{
        	cout <<  " ma sach ton tai:"<< maSach<< endl;
        		
            return i; 
        }
    }
    cout <<  " ma sach ton tai:"<< maSach<< endl;
    return -1; 
}
// cau 1 nhap danh sach cac mat hang, kiem tra tinh duy nhat cua ma sach khi nhap
// nhap danh sach cac mat hang
void nhapMatHang(MatHang danhSach[], int& soLuong) 
{
    if (soLuong >= MAX) 
	{
        cout << "khong the them mat hang.\n";
        return;
    }

    MatHang matHang;
    cout << "\nnhap thong tin :\n";
    matHang.stt = soLuong + 1;

    // nhap ma sach va kiem tra tinh duy nhat
    while (true)
	
	 {
        cout << "Mã sách: ";
        cin >> matHang.maSach;
        if (timViTriTheoMaSach(danhSach, soLuong, matHang.maSach) != -1)
		 {
            cout << "vui long nhap lai.\n";
        }
		 else {
		 	
            break;
        }
    }

    
    cout << "Tên sách: ";
    getline(cin, matHang.tenSach);

    cout << "so luong ton kho: ";
    cin >> matHang.soLuongTon;

    cout << "don gia ton kho: ";
    cin >> matHang.donGiaTon;

    cout << "Ðon gia ban: ";
    cin >> matHang.donGiaBan;

    matHang.thanhTien = matHang.soLuongTon * matHang.donGiaTon;
// cau 2 them mot cuon sach vao danh sach tai vi tri bat ky

    // Thêm cuon sach vào danh sách
    danhSach[soLuong] = matHang;
    soLuong++;

    cout << "Ðã thêm m?t hàng thành công!\n";
}

// them sach vao vi tri bat ky

void themSach(MatHang danhSach[], int& soLuong)
 {
    if (soLuong >= MAX)
	 {
        cout << "khong the them hang moi.\n";
        return;
    }

    MatHang matHang;
    cout << "\nNnhap thong tin mat hang them:\n";

    cout << "Mã sách: ";
    cin >> matHang.maSach;

    int viTri = timViTriTheoMaSach(danhSach, soLuong, matHang.maSach);
    if (viTri != -1) 
	{
        
        cout << "cap nhat lai don gia.\n";

        int soLuongNhap;
        double donGiaNhap;

        cout << "So luong nhap thêm: ";
        cin >> soLuongNhap;

        cout << "Ðon giá nhap: ";
        cin >> donGiaNhap;

        danhSach[viTri].soLuongTon += soLuongNhap;
        danhSach[viTri].donGiaTon = (danhSach[viTri].donGiaTon * (danhSach[viTri].soLuongTon - soLuongNhap) + donGiaNhap * soLuongNhap) /
                                    (danhSach[viTri].soLuongTon);
        danhSach[viTri].thanhTien = danhSach[viTri].soLuongTon * danhSach[viTri].donGiaTon;

        cout << "cap nhat thanh cong!\n";
    } 
	else
	 {
        // sach chua ton tai
        matHang.stt = soLuong + 1;

        cin.ignore();
        cout << "Tên sách: ";
        getline(cin, matHang.tenSach);

        cout << "Sso luong ton kho: ";
        cin >> matHang.soLuongTon;

        cout << "Ðon giá ton kho: ";
        cin >> matHang.donGiaTon;

        cout << "Ðon giá bán: ";
        cin >> matHang.donGiaBan;

        matHang.thanhTien = matHang.soLuongTon * matHang.donGiaTon;

        danhSach[soLuong] = matHang;
        soLuong++;

        cout << "Ðã thêm mat hang thành công!\n";
    }
}

// cau 3 xoa 1 cuon sach ra khoi danh sach 
void xoaSach(MatHang danhSach[], int& soLuong, const string& maSach)
 {
    int viTri = timViTriTheoMaSach(danhSach, soLuong, maSach);
    if (viTri == -1) 
	{
        cout << "Không tìm thay sach voi mã " << maSach << ".\n";
        return;
    }

    for (int i = viTri; i < soLuong - 1; i++) 
	{
        danhSach[i] = danhSach[i + 1];
    }
    soLuong--;
    cout << "Xóa sách thành công!\n";
}

// cau 4 sap xep danh sach mat hang theo thu tu giam dan cua gia ban
void sapXep(MatHang danhSach[], int soLuong) 
{
    for (int i = 0; i < soLuong - 1; i++) 
	{
        for (int j = i + 1; j < soLuong; j++)
		 {
            if (danhSach[i].donGiaBan < danhSach[j].donGiaBan)
			 {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }
    cout << "Danh sách dã du?c s?p x?p theo giá bán gi?m d?n.\n";
}

// cau 5 in tong gia tri ton kho
void inTongGiaTriTonKho(MatHang danhSach[], int soLuong)
 {
    int tongSoLuong = 0;
    double tongGiaTri = 0;

    for (int i = 0; i < soLuong; i++) 
	{
        tongSoLuong += danhSach[i].soLuongTon;
        tongGiaTri += danhSach[i].thanhTien;
    }

    cout << "\nT?n kho sách:\n";
    cout << "S? lu?ng: " << tongSoLuong << endl;
    cout << "S? ti?n: " << tongGiaTri << endl;
}


// cau 6 in danh sach ra man hinh theo mau
void menu()
 {
    MatHang danhSach[MAX];
    int soLuong = 0; // S? lu?ng m?t hàng hi?n t?i
    int luaChon;

    do 
	{
        cout << "\n=== QUAN LY SACH ===\n";
        cout << "1. Nhap danh sach mat hang\n";
        cout << "2. Them mot cuon sach\n";
        cout << "3. Xoa mot cuon sach\n";
        cout << "4. Sap xep theo gia ban giam dan\n";
        cout << "5. In tong gia tri ton kho\n";
        cout << "6. Hien thi danh sach\n";
        cout << "7. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) 
		{
        case 1:
            nhapMatHang(danhSach, soLuong);
            break;
        case 2:
            themSach(danhSach, soLuong);
            break;
        case 3: {
            string maSach;
            cout << "Nhap ma sach can xóa: ";
            cin >> maSach;
            xoaSach(danhSach, soLuong, maSach);
            break;
        }
        case 4:
            sapXep(danhSach, soLuong);
            break;
        case 5:
            inTongGiaTriTonKho(danhSach, soLuong);
            break;
    
        case 7:
            cout << "Thoát chuong trình.\n";
            break;
        default:
            cout << "lua chon khong phu hop vui long nhap lai.\n";
        }
    } while (luaChon != 7);
}

int main() 
{
    menu();
    return 0;
}

