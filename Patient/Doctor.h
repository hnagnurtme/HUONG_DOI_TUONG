#pragma once
#include "Patient.h"
using namespace std;

class Patient; 

class Doctor
{
    string nameD;
    vector<Patient *> patient;

public:
    Doctor(string = NULL);
    ~Doctor();
    void addPatient(Patient *);
    string getName() const;
    friend ostream &operator<<(ostream &, const Doctor &);
};
