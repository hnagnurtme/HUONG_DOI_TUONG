#include <iostream>
#include <string>
using namespace std;
class NhaCungCap{
    int MaNCC;
    string TenNCC;
    string DiaChi;
};
class PhieuNhapHang{
    int MaNhapHang;
    int MaNCC;
    string NgayNhap;
};
class LoaiHangHoa{
    int MaLoaiHang;
    string TenLoaiHang;
};

class NhanVien{
    int MaNV;
    string TenNV;
    string DiaChi;
    string Email;
    string SDT;
    string taikhoan;
    string matkhau;
};
class ThuNgan : public NhanVien{
    

};

class QuanLi : public NhanVien{

};

class HoaDon{
    int MaHD;
    int MaKhachHang;
    int MaNV;
    string NgayHD;
    int soluong;
    int ThueVAT;
    int ThanhTien;
};

class KhachHang{
    int MaKhachHang;
    string TenKhachHang;
    string SDT;
    string LoaiKhachHang;
};