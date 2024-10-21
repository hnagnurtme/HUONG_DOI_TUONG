#include <iostream>
using namespace std;

int gcd(int a, int b){
        if( b == 0)  return a;
        else return gcd( b , a%b);
}
int main(){
        int tuso,mauso;
        cout << " Nhap tu so  : ";
        cin >> tuso;
        cout << " Nhap mau so : ";
        cin >> mauso;

        while( mauso == 0){
                cout <<" Nhap lai mau so khac 0";
                cin >> mauso;
        }
        
        int ucln = gcd(tuso, mauso);
        if( ucln != 1) {
                tuso /= ucln ;
                mauso/= ucln;
        }

        cout <<" Phan so sau khi rut gon la :"<<tuso<<" / "<<mauso;
        return 0;
}