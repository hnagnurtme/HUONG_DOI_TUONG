#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack *st = new Stack(8);
    int number,temp;
    cout << " Nhap so n de chuyen sang he 16 ";
    cin >> number;
    temp = number;
    while (number > 0)
    {
        if (!st->push(number % 16))
            return 0;
        number /= 16;
    }

    char Hex[16] = "0123456789ABCDE";

    cout << " So " << temp << " he 16 la: ";
    while (!st->isEmpty())
    {
        int res;
        if (!st->pop(res))
            return 0;
        cout << Hex[res] << " ";
    }
}