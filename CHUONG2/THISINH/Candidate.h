#ifndef Candidate_H
#define Candidate_H
#include <string>

using namespace std;
class Candidate{
private :
        int ma;
        string ten;
        unsigned int *sinhnhat;

        unsigned int *diem;// Toan = diem[0] Van = diem[1] Anh = diem[2]
public:
        Candidate(int ma =0 , string ten ="" ) ;

        ~Candidate();
        void Nhap();
        
        void Xuat();

        int TongDiem();


};

#endif