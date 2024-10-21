#ifndef Sinhvien_H
#define Sinhvien_H

class Sinhvien{
private:
    int MSSV;
    double DTB;
public:
    Sinhvien(int = 0,double = 0.0);
    Sinhvien(const Sinhvien &);
    ~Sinhvien();
    void ShowSV();
    int GetMSSV();
    double GetDTB();
};
#endif