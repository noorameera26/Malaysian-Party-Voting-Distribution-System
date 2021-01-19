#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "generalInfor.h"
#include "detailInfor.h"
#include "birthDate.h"

using namespace std;

void Welcome();
void DisplayMain();
void AddVoter(string&, string&, string&, string&, string&, string&, string&, string&, string&);
void VoterSearch(string&);
void ParliamentSearch(string&);
void PrintPartiesAnalysis(string, int, int, int, int);
void PrintGenderAnalysis(string, int, int, int, int, int, int, int);
void PrintAgeAnalysis(string, int, int, int, int, int, int, int, int, int, int, int, int, int);
void HeaderAnalysis();
void DisplayInformation();

int main()
{
    ifstream in;
    string name, ID, gender, state, pment, dun, phone, email, party;
    int num = 0, choice, Total;
    char choice1;
    const int SIZE = 500;

    detailInfor info[SIZE]; //declare array of info objects from class detailInfor with size 1000

    in.open("Data.txt");

    if(in.fail())
    {
        cerr << "Input file could not be opened!" << endl;
        exit(-1);
    }

    while(!in.eof()) //read data from an input file
    {
        getline(in,name,',');
        getline(in,ID,',');
        getline(in,gender,',');
        getline(in,state,',');
        getline(in,pment,',');
        getline(in,dun,',');
        getline(in,phone,',');
        getline(in,email,',');
        getline(in,party); //changes here!
        in.ignore(10,'\n');

        info[num].setDetail(name, ID, gender, state, pment, dun, phone, email, party);

        num++;
    }
    in.close(); //close file

    do
    {
        Welcome(); // Display header
        DisplayMain(); // Display main menu
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 0: //User exits the program
                {
                    choice1 = 'N';

                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
                         << endl;

                    break;
                }
            case 1: //User adds new voter's information
                {
                    system("cls");

                    choice1 = 'Y';

                    while(choice1 == 'Y' || choice1 == 'y')
                    {
                        AddVoter(name, ID, gender, state, pment, dun, phone, email, party);
                        cin >> choice1;
                        cin.ignore();
                        info[num].setDetail(name, ID, gender, state, pment, dun, phone, email, party);
                        num++;
                    }

                    choice1 = 'Y';
                    break;
                }
            case 2: //User searches for a voter's information based I.C. Number
                {
                    system("cls");

                    choice1 = 'Y';

                    while(choice1 == 'Y' || choice1 == 'y')
                    {
                        int j = 0; bool found = false;

                        VoterSearch(ID);

                        while(j < num)
                        {
                            info[j].searchDetail(ID, found);
                            j++;

                            if(found == true)
                                break;
                        }

                        if(found == false)
                            cout << endl << " The voter's information does not exist!";

                        cout << endl << endl << endl << "     >> Would you like to search for another voter's"
                        << " information? (Y/N) : ";
                        cin >> choice1;
                        cin.ignore();
                    }

                    choice1 = 'Y';
                    break;
                }
            case 3: //User views parties overall distribution for selected parliament
                {
                    system("cls");

                    HeaderAnalysis();

                    choice1 = 'Y';

                    while(choice1 == 'Y' || choice1 == 'y')
                    {
                        int teratai=0, melur=0, dahlia=0;
                        Total=0;

                        ParliamentSearch(pment);

                        for(int j=0; j<num; j++)
                        {
                            info[j].partyAnalysis(pment, teratai, melur, dahlia, Total);
                        }

                        PrintPartiesAnalysis(pment, teratai, melur, dahlia, Total);

                        cout << endl << endl << endl << "     >> Would you like to view the overall"
                        << " distribution for different parliament? (Y/N): ";
                        cin >> choice1;
                        cin.ignore();
                    }

                    choice1 = 'Y';
                    break;
                }
            case 4: //User views demographic distribution based on genders for selected parliament
                {
                    system("cls");

                    HeaderAnalysis();

                    choice1 = 'Y';

                    while(choice1 == 'Y' || choice1 == 'y')
                    {
                        int female_T=0, male_T=0, female_M=0, male_M=0, female_D=0, male_D=0;
                        Total=0;

                        ParliamentSearch(pment);

                        for(int j=0;j<num;j++)
                        {
                            info[j].genderAnalysis(pment, female_T, male_T, female_M, male_M, female_D, male_D, Total);
                        }

                        PrintGenderAnalysis(pment, female_T, male_T, female_M, male_M, female_D, male_D, Total);

                        cout << endl << endl << endl << "     >> Would you like to view the distribution for"
                        << " different parliament? (Y/N): ";
                        cin >> choice1;
                        cin.ignore();
                    }
                    choice1 = 'Y';
                    break;
                }
            case 5: //User views demographic distribution based on age groups for selected parliament
                {
                    system("cls");

                    HeaderAnalysis();

                    choice1 = 'Y';

                    while(choice1 == 'Y' || choice1 == 'y')
                    {
                        int age20s_T=0, age20s_M=0, age20s_D=0, age30s_T=0, age30s_M=0, age30s_D=0, age50s_T=0,
                        age50s_M=0, age50s_D=0, age60s_T=0, age60s_M=0, age60s_D=0;

                        ParliamentSearch(pment);

                        for(int j=0;j<num;j++)
                        {
                            info[j].ageAnalysis(pment, Total, age20s_T, age20s_M, age20s_D, age30s_T, age30s_M, age30s_D,
                                                age50s_T, age50s_M, age50s_D, age60s_T, age60s_M, age60s_D);

                        }

                        PrintAgeAnalysis(pment, Total, age20s_T, age20s_M, age20s_D, age30s_T, age30s_M, age30s_D,
                                        age50s_T, age50s_M, age50s_D, age60s_T, age60s_M, age60s_D);

                        cout << endl << endl << endl << "     >> Would you like to view the distribution for"
                        << " different parliament? (Y/N): ";
                        cin >> choice1;
                        cin.ignore();
                    }
                    choice1 = 'Y';
                    break;
                }
            case 6: //User views voters' information
                {
                    system("cls");

                    DisplayInformation();

                    for(int j=0; j<num ; j++)
                    {
                        info[j].printGeneral();
                        info[j].printDetail();
                        cout << endl << endl;
                    }
                    cout << " Total number of voters in the Pre-DAVD system: " << num << endl << endl;

                    choice1 = 'Y';
                    break;
                }
            default: //User enters none of the available option
                {
                    cout << endl << "     >> You've entered the wrong input! Press any key to continue. ";
                    cin.get();

                    system("cls");

                    choice1 = 'Y';
                }
        }

        if (choice!=0) //Display return-to-main-menu-message
        {
            cout << endl << "     >> Returning to main menu. Press any key to continue.";
            cin.get();
            system("cls");
        }

    } while(choice1 !='N' && choice1 !='n' );

} //end of main function





