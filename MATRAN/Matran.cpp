#include "Matran.h"
#include <iostream>
using namespace std;
Matran::Matran(int n) {
    this->n = n;
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = 0;
        }
    }
}

Matran::Matran(const Matran &matran) {
    this->n = matran.n;
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = matran.data[i][j];
        }
    }
}

Matran::~Matran() {
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matran Matran::operator+(const Matran &matran) {
    Matran result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result.data[i][j] = this->data[i][j] + matran.data[i][j];
        }
    }
    return result;
}

Matran Matran::operator-(const Matran &matran) {
    Matran result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result.data[i][j] = this->data[i][j] - matran.data[i][j];
        }
    }
    return result;
}

Matran Matran::operator*(const Matran &matran) {
    Matran result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result.data[i][j] += this->data[i][k] * matran.data[k][j];
            }
        }
    }
    return result;
}

Matran& Matran::operator=(const Matran &matran) {
    if (this != &matran) {
        for (int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;

        this->n = matran.n;
        data = new int*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[n];
            for (int j = 0; j < n; j++) {
                data[i][j] = matran.data[i][j];
            }
        }
    }
    return *this;
}
int  Matran :: operator ()(int i , int j){
    return data[i][j];
};

istream& operator>>(istream &in, Matran &matran) {
    for (int i = 0; i < matran.n; i++) {
        for (int j = 0; j < matran.n; j++) {
            in >> matran.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream &out, const Matran &matran) {
    for (int i = 0; i < matran.n; i++) {
        for (int j = 0; j < matran.n; j++) {
            out << matran.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
