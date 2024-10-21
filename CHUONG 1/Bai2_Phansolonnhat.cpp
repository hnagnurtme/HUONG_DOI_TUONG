#include <iostream>
using namespace std;

int main(){
        int tuso1,mauso1,tuso2,mauso2;
        cout << " Nhap tu so phan so 1  : ";
        cin >> tuso1;
        cout << " Nhap mau so phan so 1 : ";
        cin >> mauso1;

        while( mauso1 == 0){
                cout <<" Nhap lai mau so khac 0";
                cin >> mauso1;
        }
        cout << " Nhap tu so phan so 2  : ";
        cin >> tuso2;
        cout << " Nhap mau so phan so 2 : ";
        cin >> mauso2;

        while( mauso2 == 0){
                cout <<" Nhap lai mau so khac 0";
                cin >> mauso2;
        }
        if(( tuso1*mauso2 - mauso1*tuso2)*(mauso1*mauso2) >0){
                cout <<" Phan so sau lon hon  la :"<<tuso1<<" / "<<mauso1;
        }
        else  cout <<" Phan so sau lon hon  la :"<<tuso2<<" / "<<mauso2;
        

        
        return 0;
}