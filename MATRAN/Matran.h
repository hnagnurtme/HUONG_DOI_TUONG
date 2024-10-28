#ifndef MATRAN_H
#define MATRAN_H
#include <iostream>
using namespace std;

template <typename T> 
class Matran {
private:
    int n;
    T **data;
public:
    Matran(int n = 2);
    Matran(const Matran<T>& matran);
    ~Matran();
    Matran<T> operator+(const Matran<T>& matran);
    Matran<T> operator-(const Matran<T>& matran);
    Matran<T> operator*(const Matran<T>& matran);
    Matran<T>& operator=(const Matran<T>& matran);
    T operator()(int i, int j) const;

    template <typename U>
    friend istream& operator>>(istream& in, Matran<U>& matran);
    
    template <typename U>
    friend ostream& operator<<(ostream& out, const Matran<U>& matran);
};

template <typename T>
Matran<T>::Matran(int n) : n(n) {
    data = new T*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new T[n];
    }
}

template <typename T>
Matran<T>::Matran(const Matran<T>& matran) : n(matran.n) {
    data = new T*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new T[n];
        for (int j = 0; j < n; ++j) {
            data[i][j] = matran.data[i][j];
        }
    }
}

template <typename T>
Matran<T>::~Matran() {
    for (int i = 0; i < n; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
Matran<T> Matran<T>::operator+(const Matran<T>& matran) {
    Matran<T> result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = this->data[i][j] + matran.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matran<T> Matran<T>::operator-(const Matran<T>& matran) {
    Matran<T> result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = this->data[i][j] - matran.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matran<T> Matran<T>::operator*(const Matran<T>& matran) {
    Matran<T> result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result.data[i][j] += this->data[i][k] * matran.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matran<T>& Matran<T>::operator=(const Matran<T>& matran) {
    if (this != &matran) {
        for (int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
        n = matran.n;
        data = new T*[n];
        for (int i = 0; i < n; ++i) {
            data[i] = new T[n];
            for (int j = 0; j < n; ++j) {
                data[i][j] = matran.data[i][j];
            }
        }
    }
    return *this;
}

template <typename T>
T Matran<T>::operator()(int i, int j) const {
    return data[i][j];
}

template <typename U>
istream& operator>>(istream& in, Matran<U>& matran) {
    for (int i = 0; i < matran.n; ++i) {
        for (int j = 0; j < matran.n; ++j) {
            in >> matran.data[i][j];
        }
    }
    return in;
}

template <typename U>
ostream& operator<<(ostream& out, const Matran<U>& matran) {
    for (int i = 0; i < matran.n; ++i) {
        for (int j = 0; j < matran.n; ++j) {
            out << matran.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

template class Matran<int>;
template class Matran<double>;

#endif 