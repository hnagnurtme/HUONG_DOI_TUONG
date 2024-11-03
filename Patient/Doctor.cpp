#include "Doctor.h"

Doctor::Doctor(string name)
    : nameD(name)
{
}

Doctor::~Doctor()
{
}

void Doctor::addPatient(Patient *p)
{
    this->patient.push_back(p);
    p->addDoctor(this);
}

string Doctor::getName() const
{
    return this->nameD;
}

ostream &operator<<(ostream &o, const Doctor &d)
{
    int number = d.patient.size();
    if (number == 0)
    {
        o << d.nameD << " has no patients right now" << endl;
    }
    else
    {
        o << d.nameD << " is seeing patients: ";
        for (int i = 0; i < number; i++)
            o << d.patient[i]->getName() << " ";
        o << endl;
    }
    return o;
}
