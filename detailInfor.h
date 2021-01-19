#ifndef DETAILINFOR_H
#define DETAILINFOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class detailInfor: public generalInfor
{

    private:
        string Pment;
        string Dun;
        string Phone;
        string Email;
        string Party;
        int Day;
        int Month;
        int Year;

    public:
        detailInfor();
        ~detailInfor();
        void setDetail(string, string, string, string, string, string, string, string, string);
        void extractBirthDate();
        void setBirthDate(int, int, int);
        void printDetail() const;
        void printGeneral() const;
        void searchDetail(string, bool&) const;
        void partyAnalysis(string, int&, int&, int&, int&) const;
        void genderAnalysis(string, int&, int&, int&, int&, int&, int&, int&) const;
        void ageAnalysis(string, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&,
                         int&, int&);
};

#endif // DETAILINFOR_H
