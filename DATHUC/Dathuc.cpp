#include "Dathuc.h"

Dathuc::Dathuc(int n)
{
    this->n = n;
    heso = new int[n + 1]{0}; 
}


Dathuc::Dathuc(int heso[], int size)
{
    this->n = size - 1;
    this->heso = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        this->heso[i] = heso[i];
    }
}


Dathuc::Dathuc(const Dathuc &dathuc)
{
    this->n = dathuc.n;
    heso = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        heso[i] = dathuc.heso[i];
    }
}


Dathuc::~Dathuc()
{
    delete[] heso;
}

Dathuc Dathuc::operator+(const Dathuc &dathuc)
{
    int bac = (this->n > dathuc.n) ? this->n : dathuc.n;
    Dathuc result(bac);

    for (int i = 0; i <= bac; i++)
    {
        if (i <= this->n) result.heso[i] += this->heso[i];
        if (i <= dathuc.n) result.heso[i] += dathuc.heso[i];
    }

    return result;
}

Dathuc Dathuc::operator-(const Dathuc &dathuc)
{
    int bac = (this->n > dathuc.n) ? this->n : dathuc.n;
    Dathuc result(bac);

    for (int i = 0; i <= bac; i++)
    {
        if (i <= this->n) result.heso[i] += this->heso[i];
        if (i <= dathuc.n) result.heso[i] -= dathuc.heso[i];
    }

    return result;
}


Dathuc &Dathuc::operator=(const Dathuc &dathuc)
{
    if (this != &dathuc)
    {
        delete[] heso;
        this->n = dathuc.n;
        heso = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            heso[i] = dathuc.heso[i];
        }
    }
    return *this;
}


istream &operator>>(istream &in, Dathuc &dathuc)
{
    cout << "Nhap bac cua da thuc: ";
    in >> dathuc.n;

    delete[] dathuc.heso;
    dathuc.heso = new int[dathuc.n + 1];

    cout << "Nhap cac he so (tu bac cao den bac thap):" << endl;
    for (int i = dathuc.n; i >= 0; i--)
    {
        cout << "He so bac " << i << ": ";
        in >> dathuc.heso[i];
    }
    return in;
}


ostream &operator<<(ostream &out, const Dathuc &dathuc)
{
    for (int i = dathuc.n; i >= 0; i--)
    {
        out << dathuc.heso[i];
        if (i > 0)
        {
            out << "x";
            if (i > 1)
            {
                out << "^" << i;
            }
            out << " + ";
        }
    }
    return out;
}

int &Dathuc::operator[](int i)
{
    return heso[i];
}
