#include "Department.h"
int main(){
    Teacher *t = new Teacher("NVA",40);
    {
        Department d("CNTT",t);
        cout <<d;
    }
    cout <<*t;
    delete t;
    return 0;
}