#include "Patient.h"
#include "Doctor.h"
int main(){
    Patient *p1 = new Patient("Dave");
    Patient *p2 = new Patient("Franks");
    Patient *p3 = new Patient("Besty");
    Doctor *d1 = new Doctor("Jame");
    Doctor *d2 = new Doctor("Scott");
    d1->addPatient(p1);
    d2->addPatient(p1);
    d2->addPatient(p3);
    cout << *d1; cout <<*d2;
    cout <<*p1 ; cout <<*p2 ; cout << *p3;
    return 0;
}