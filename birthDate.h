#ifndef BIRTHDATE_H
#define BIRTHDATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class birthDate
{
    private:
        int age;

    public:
        birthDate();
        ~birthDate();
        void calculateAge(string);
        void setAge(int);
        int getAge() const;
};

#endif // BIRTHDATE_H
