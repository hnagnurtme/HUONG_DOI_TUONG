#include "Teacher.h"
Teacher::Teacher(string name,int age) : name(name),age(age) {}

Teacher::~Teacher(){}

ostream& operator <<(ostream& o,const Teacher &t){
    o<<t.name <<" , age : " <<t.age <<endl;
    return o;
}