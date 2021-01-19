#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "generalInfor.h"
#include "detailInfor.h"
#include "birthDate.h"

using namespace std;

void Welcome()
{ //Display Main Header
    cout << endl << setw(90) << "PreDAVD - Preliminary Data Analysis on Voting Distribution System";
    cout << endl << setw(120) << setfill('*') << " "  << setfill(' ');
}

void DisplayMain()
{ //Display Main Menu
    cout << endl << " Main Menu:" << endl;
    cout << endl << " (1) Enter new voter's information.";
    cout << endl << " (2) Search voter's information based on I.C. number.";
    cout << endl << " (3) View analysis on overall distribution based on party preferences.";
    cout << endl << " (4) View analysis on demographic distribution based on genders.";
    cout << endl << " (5) View analysis on demographic distribution based on age groups.";
    cout << endl << " (6) View all voters\' information.";
    cout << endl << " (0) Exit the program.";
    cout << endl << endl << "     >> Your selection (1/2/3/4/5/6/0) : ";
}

void AddVoter(string& name, string& ID, string& gender, string& state, string& pment, string& dun,
              string& phone, string& email, string& party)
{ //Request and read new voter's information
    bool check;

    cout << endl << endl << setw(75) << "Entering new voter's information..." << endl << endl;

    cout << " 1. Full Name\t\t\t\t\t\t: ";
    getline(cin,name,'\n');

    cout << " 2. I.C. Number (Enter without space i.e. 701017101234) : ";
    getline(cin,ID,'\n');

        check = false;
        while(check == false) //Input validation for I.C. Number
        {
            if (ID.length()==12)
            {
                check = true;
                break;
            }
            cout << endl << "     >> Please re-enter the voter's I.C number (12 digits).";
            cout << endl << "     >> I.C. Number: ";
            getline(cin,ID,'\n');
        }

    cout << " 3. Gender (M / F)\t\t\t\t\t: ";
    getline(cin,gender,'\n');

        check = false;
        while(check == false)//Input validation for gender
        {
            if (gender.length()==1)
            {
                gender = toupper(gender[0]);

                if (gender == "M" || gender== "F")
                {
                    check = true;
                    break;
                }
            }
            cout << endl << "     >> Please re-enter the voter's gender (M / F).";
            cout << endl << "     >> Gender: ";
            getline(cin,gender,'\n');

        }

    cout << " 4. State\t\t\t\t\t\t: ";
    getline(cin,state,'\n');

    cout << " 5. Parliament number (i.e. 101)\t\t\t: ";
    getline(cin,pment,'\n');

        check = false;
        while(check == false)//Input validation for Parliament Number
        {
            if (pment.length()==3)
            {
                check = true;
                break;
            }
            cout << endl << "     >> Please re-enter the voter's parliament number (3 digits).";
            cout << endl << "     >> Parliament Number: ";
            getline(cin,pment,'\n');
        }

    cout <<  " 6. DUN number (i.e. 101-101)\t\t\t\t: ";
    getline(cin,dun,'\n');

        check = false;
        while(check == false) //Input validation for DUN Number
        {
            if (dun.length()==7)
            {
                check = true;
                break;

            }
            cout << endl << "     >> Please re-enter the voter's DUN number (Parliament number followed by "
                 << "DUN number, separated with a \'-\').";
            cout << endl << "     >> DUN Number: ";
            getline(cin,dun,'\n');
        }

    cout << " 7. Phone number (Enter without space i.e. 0123456789)  : ";
    getline(cin,phone,'\n');

    cout << " 8. Email address (i.e abc@gmail.com)\t\t\t: ";
    getline(cin,email,'\n');

    cout << " 9. Party preference (T/ M/ D)\t\t\t\t: ";
    getline(cin,party,'\n');

        check = false;
        while(check == false)//Input validation for party preference
        {
            if (party.length()==1)
            {
                party = toupper(party[0]);

                if (party == "T" || party == "M" || party == "D")
                {
                    check = true;
                    break;
                }
            }
            cout << endl << "     >> Please re-enter the voter's party preference (T/ M/ D).";
            cout << endl << "     >> Parliament Number: ";
            getline(cin,party,'\n');
        }

    cout << endl << endl << "     >> Would you like to add a new voter's information? (Y/N) : ";
}

void VoterSearch(string& ID)
{ //Request and read voter's I.C. Number for search purpose
    cout << endl << endl << setw(85) << "Searching a voter's information based on I.C number...";
    cout << endl << endl << " Voter's I.C. number (Enter without space i.e. 701017101234): ";
    getline(cin, ID,'\n');
}

void HeaderAnalysis()
{ //Print analysis' header
    cout << endl << endl << setw(75) << "Political Parties Distribution Analysis";
    cout << endl << setw(120) << setfill('*') << " "  << setfill(' ');
}

void ParliamentSearch(string& pment)
{ //Request and read voter's chosen parliament for analysis purpose
    cout << endl << endl << " Enter parliament code (i.e. 101): ";
    getline(cin, pment, '\n');

}

void PrintPartiesAnalysis(string pment, int t, int m, int d, int total)
{ //Display the overall distribution analysis of all parties for selected parliament
    cout << endl << setw(75) << "# Overall Distribution For All Parties #";
    cout << endl << endl << " Parliament Code: " << pment;
    cout << endl << " Total number of voters: " << total;
    cout << endl << setw(70) << "Teratai \t Melor \t Dahlia";

    cout << endl << " No. of voters" << setw(37) << t << "\t   " << m << "\t   " << d;
    cout << setprecision(2);
    cout << endl << " % of voters" << setw(40) << (double)t/double(total)*100 << "\t   "
         << (double)m/double(total)*100 << "\t   " << (double)d/double(total)*100;
}

void PrintGenderAnalysis(string pment, int female_T, int male_T, int female_M, int male_M, int female_D,
                         int male_D, int total)
{ //Display the demographic distribution analysis based on genders for selected parliament
    cout << endl << setw(75) << "# Demographic Distribution Based On Genders #";
    cout << endl << endl << " Parliament Code: " << pment;
    cout << endl << " Total number of voters: " << total;
    cout << endl << setw(70) << "Teratai \t Melor \t Dahlia";

    cout << setprecision(2);
    cout << endl << " % of male" << setw(40) << (double)male_T/double(total)*100 << "\t   "
         << (double)male_M/double(total)*100 << "\t   " << (double)male_D/double(total)*100;
    cout << endl << " % of female" << setw(38) << (double)female_T/double(total)*100 << "\t   "
         << (double)female_M/double(total)*100 << "\t   " << (double)female_D/double(total)*100;
}

void PrintAgeAnalysis(string pment, int total, int age20s_T, int age20s_M, int age20s_D, int age30s_T,
                      int age30s_M, int age30s_D, int age50s_T, int age50s_M, int age50s_D, int age60s_T,
                      int age60s_M, int age60s_D)
{ //Display the demographic distribution analysis based on age groups for selected parliament
    cout << endl << setw(80) << "# Demographic Distribution Based On Age Groups #";
    cout << endl << endl << " Parliament Code: " << pment;
    cout << endl << " Total number of voters: " << total;
    cout << endl << setw(65) << "% \t\t Teratai   Melor   Dahlia";

    cout << setprecision(2);
    cout << endl << setw(40) << "21-30" << setw(13) << (double)age20s_T/double(total)*100 << setw(9)
         << (double)age20s_M/double(total)*100 << setw(9) << (double)age20s_D/double(total)*100;
    cout << endl << setw(40) << "31-49" << setw(13) << (double)age30s_T/double(total)*100 << setw(9)
         << (double)age30s_M/double(total)*100 << setw(9) << (double)age30s_D/double(total)*100;
    cout << endl << setw(40) << "50-60" << setw(13) << (double)age50s_T/double(total)*100 << setw(9)
         << (double)age50s_M/double(total)*100 << setw(9) << (double)age50s_D/double(total)*100;
    cout << endl << setw(40) << ">60" << setw(13) << (double)age60s_T/double(total)*100 << setw(9)
         << (double)age60s_M/double(total)*100 << setw(9) << (double)age60s_D/double(total)*100;

}

void DisplayInformation()
{ //Display header for voter's information
    cout << endl << endl << setw(80) << "Voters' General and Detailed Information";
    cout << endl << setw(120) << setfill('*') << " "  << setfill(' ');
}



