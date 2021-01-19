#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "generalInfor.h"
#include "detailInfor.h"
#include "birthDate.h"

using namespace std;

birthDate::birthDate() //default constructor
{
    age = 0;
}

birthDate::~birthDate() //destructor
{
}

void birthDate::calculateAge(string ID) //calculate voter's age on year 2018
{
    int Age;

    Age = 118 - atoi(ID.substr(0, 2).c_str());

    setAge(Age);
}

void birthDate::setAge(int Age) //set voter's age
{
    age = Age;
}

int birthDate::getAge() const //return voter's age
{
    return age;
}




