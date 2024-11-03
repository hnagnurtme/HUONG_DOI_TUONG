#include "Teacher.h"
class Department{
    Teacher *teacher;
    string nameDep;
public:
    Department(string = "",Teacher* = nullptr);
    ~Department();
    friend ostream& operator<<(ostream& , const Department &);

};