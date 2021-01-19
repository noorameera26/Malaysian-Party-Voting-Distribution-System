#ifndef GENERALINFOR_H
#define GENERALINFOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "birthDate.h"

using namespace std;

class generalInfor
{
    private:
        string Name;
        string IC;
        string Gender;
        string State;
        birthDate bday;

    public:
        generalInfor();
        ~generalInfor();
        void setDetail(string, string, string, string);
        void extractBirthDate(int&, int&, int&) const;
        void searchDetail(string, bool&) const;
        void printGeneral() const;
        void genderAnalysis(int&, int&) const;
        void ageAnalysis(int&, int&, int&, int&);
};

#endif // GENERALINFOR_H
