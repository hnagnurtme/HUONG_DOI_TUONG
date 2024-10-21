#ifndef TestCandidate_H
#define TestCandidate_H

#include "Candidate.h"
using namespace std;

class TestCandidate{
private:
        int size;
        Candidate  *ListCandidate;

public:
        TestCandidate(int size = 1);
        ~TestCandidate();

        void NhapDanhSach();

        void XuatDanhSach();

};

#endif