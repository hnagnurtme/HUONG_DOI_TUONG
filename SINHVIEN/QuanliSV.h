#ifndef QuanliSV_H
#define QuanliSV_H
#include "Sinhvien.h"

class QuanliSV
{
private:
    Sinhvien * data;
    int count;
    int maxsize;
public:
    QuanliSV(int maxsize = 10);
    ~QuanliSV();
    void Add(Sinhvien);
    void Add_Range(Sinhvien[], int n);
    int IndexOf(Sinhvien);
    void RemoveAt(int);
    void Remove(Sinhvien);
    void Show();
    void Update(Sinhvien);
    void Sort_DiemTB();

};

#endif