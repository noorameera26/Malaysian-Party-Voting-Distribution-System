#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "generalInfor.h"
#include "detailInfor.h"
#include "birthDate.h"

using namespace std;

generalInfor::generalInfor():bday() //constructor
{
    Name    = " ";
    IC      = " ";
    Gender  = " ";
    State   = " ";
}

generalInfor::~generalInfor() //default constructor
{
}

void generalInfor::setDetail(string na, string id, string ge, string st)
{ //set voter's general information
    Name    = na;
    IC      = id;
    Gender  = ge;
    State   = st;
}

void generalInfor::printGeneral() const
{ //print voter's general information
    cout << endl << " Name              : " << Name;
    cout << endl << " I.C. Number       : " << IC;
    cout << endl << " Gender            : " << Gender;
    cout << endl << " State             : " << State;
}

void generalInfor::extractBirthDate(int& day, int& month, int& year) const
{ //extract birth date from I.C number
    day     = atoi(IC.substr(4, 2).c_str());
    month   = atoi(IC.substr(2, 2).c_str());
    year    = atoi(IC.substr(0, 2).c_str());
}

void generalInfor::searchDetail(string id, bool& found) const
{ //search detail's information based on I.C. number
    if (IC==id)
    {
        found = true;
    }
}

void generalInfor::genderAnalysis(int& female, int& male) const
{ //count voters' gender
    if (Gender == "F")
        female++;
    else if (Gender == "M")
        male++;
}

void generalInfor::ageAnalysis(int& age20, int& age30, int& age50, int& age60)
{ //count voters' age according to age groups
    int age;

    bday.calculateAge(IC);

    age = bday.getAge();

    if (age >= 21 && age <= 30)
        age20++;
    else if (age >= 31 && age <= 49)
        age30++;
    else if (age >= 50 && age <= 60)
        age50++;
    else if (age > 60)
        age60++;
}


