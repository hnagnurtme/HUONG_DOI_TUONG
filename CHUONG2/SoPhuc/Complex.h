#ifndef Complex_H
#define Complex_H

class Complex{
private : 
	float thuc;
        float ao;
public: 
        Complex(float thuc = 0 , float ao = 0);

        void Nhap();

        void Xuat();

        friend Complex Cong(const Complex &so1 , const Complex &so2);

        friend Complex Tru(const Complex &so1 , const Complex &so2);

        friend Complex Nhan(const Complex &so1 , const Complex &so2);

        friend Complex Chia(const Complex &so1 , const Complex &so2);

};

#endif