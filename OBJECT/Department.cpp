#include "Department.h"
Department::Department(string name,Teacher* teacher): nameDep(name), teacher(teacher){}
Department::~Department(){
    delete this->teacher;
}

ostream& operator<<(ostream&o, const Department&d){
    o<<d.nameDep <<": "<<*d.teacher<<endl;
    return o;
}
