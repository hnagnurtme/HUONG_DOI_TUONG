#include <string>
using namespace std;
class Shape{
public :
    string diachi;
    int kichthuoc;
    static float tongDientich;
public:
    virtual  int  Nhap();
    virtual  void Xuat();
    virtual float ChuVi() = 0;
    virtual float DienTich() = 0;

};

class Circle : public Shape{
public:
    virtual  int Nhap();
    virtual  void Xuat();
    float DienTich();
    float ChuVi();

};

class Square : public Shape{
public:
    virtual  int Nhap();
    virtual  void Xuat();
    float DienTich();
    float ChuVi();

};

class TamGiacDeu : public Shape{
public:
    virtual  int Nhap();
    virtual  void Xuat();
    float DienTich();
    float ChuVi();

};

