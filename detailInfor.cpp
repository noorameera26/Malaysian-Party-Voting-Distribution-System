#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "generalInfor.h"
#include "detailInfor.h"

using namespace std;

detailInfor::detailInfor():generalInfor() //default constructor
{
    string Pment    = " ";
    string Dun      = " ";
    string Phone    = " ";
    string Email    = " ";
    string Party    = " ";
    int Day         = 00;
    int Month       = 00;
    int Year        = 1900;
}

detailInfor::~detailInfor() //destructor
{
}

void detailInfor::setDetail(string na, string id, string ge, string st, string pm, string du,
                            string ph, string em, string pa)
{ //set voter's general and detailed information
    generalInfor::setDetail(na, id, ge, st);
    extractBirthDate();

    Pment   = pm;
    Dun     = du;
    Phone   = ph;
    Email   = em;
    Party   = pa;
}

void detailInfor::extractBirthDate()
{ //extract birth date from voter's I.C. number
    int d,m,y;

    generalInfor::extractBirthDate(d, m, y);

    setBirthDate(d, m, y);
}

void detailInfor::setBirthDate(int d, int m, int y)
{ //set voter's birth date
    Day     = d;
    Month   = m;
    Year    = y;
}

void detailInfor::printDetail() const
{ //print voter's detailed information
    cout << endl << " Parliament Number : " << Pment;
    cout << endl << " DUN Number        : " << Dun;
    cout << endl << " Date of Birth     : " << Day << ":" << Month << ":19" << Year;
    cout << endl << " Phone number      : " << Phone;
    cout << endl << " Email address     : " << Email;
    cout << endl << " Party preference  : " << Party;
}

void detailInfor::printGeneral() const
{ //print voter's general information
    generalInfor::printGeneral();
}

void detailInfor::searchDetail(string id, bool& found) const
{ //call search voter's information function in base detailInfor class
    generalInfor::searchDetail(id, found);

    if  (found == true)
    {
        printDetail();
    }
}

void detailInfor::partyAnalysis(string pm, int& teratai, int& melor, int& dahlia, int& total) const
{ //analyse overall parties distribution based on selected parliament
    if(Pment == pm)
    {
        total++;

        if (Party == "T")
            teratai++;
        else if(Party == "M")
            melor++;
        else if (Party == "D")
            dahlia++;
    }
}

void detailInfor::genderAnalysis(string pm, int& female_T, int& male_T, int& female_M, int& male_M,
                                 int& female_D, int& male_D, int& total) const
{ //analyse demographic distribution based on genders for selected parliament
    if(Pment == pm)
    {
        total++;

        if (Party == "T")
            generalInfor::genderAnalysis(female_T, male_T);
        else if(Party == "M")
            generalInfor::genderAnalysis(female_M, male_M);
        else if (Party == "D")
            generalInfor::genderAnalysis(female_D, male_D);
    }
}


void detailInfor::ageAnalysis(string pm, int& total, int& age20s_T, int& age20s_M, int& age20s_D,
                              int& age30s_T, int& age30s_M, int& age30s_D, int& age50s_T, int& age50s_M, int& age50s_D,
                              int& age60s_T, int& age60s_M, int& age60s_D)
{ //analyse demographic distribution based on age groups for selected parliament
    if(Pment == pm)
    {
        total++;

        if (Party == "T")
        {
            generalInfor::ageAnalysis(age20s_T, age30s_T, age50s_T, age60s_T);
        }
        else if (Party == "M")
        {
            generalInfor::ageAnalysis(age20s_M, age30s_M, age50s_M, age60s_M);
        }
        else if (Party == "D")
        {
            generalInfor::ageAnalysis(age20s_D, age30s_D, age50s_D, age60s_D);
        }

    }

}

