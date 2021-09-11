#include "searchStu.h"
#include "mainInterface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>



using namespace std;

void searchStu::stuD()
{
    double sub1;
    double sub2;
    double sub3;
    double tot;
    int stID;
    int stIDin;
    string clz;


    cout<<"------ SEARCH STUDENT DETAILS ------"<<endl;

    cout<<"\n";

    cout<< setw(32) << left << "Class (b1,b2,b3/m1,m2,m3,m4,m5)" << setw(2) << ":";
    cin>>clz;

    cout << setw(32) << "Enter Student ID" << setw(2) << ":";
    cin >> stIDin;

    //if bio class
    if((clz=="b1")||(clz=="b2")||(clz=="b3"))
    {
        ifstream fileSearch(clz+".txt");
        if(fileSearch.is_open())
        {
            while(fileSearch>>stID>>sub1>>sub2>>sub3>>tot)
            {
                if(stIDin == stID)
                {
                    system("cls");//clear the console

                    cout<<"------ STUDENT DETAILS ------"<<endl;

                    cout<<"\n";

                    cout << setw(15) << "ID" << setw(2) << ":" <<stID<<endl;
                    cout << setw(15) << "CLASS" << setw(2) << ":" <<clz<<endl;

                    cout<<"-----------------------------"<<endl;

                    cout << setw(15) << "BIOLOGY" << setw(2) << ":" << sub1<<endl;
                    cout << setw(15) << "CHEMISTRY" << setw(2) << ":" << sub2<<endl;
                    cout << setw(15) << "PHYSICS" << setw(2) << ":" << sub3<<endl;

                    cout<<"-----------------------------"<<endl;

                    cout << setw(15) << "TOTAL MARKS" << setw(2) << ":" << tot<<endl;
                    break;
                }
            }
        }
        fileSearch.close();
    }
    //if Maths class
    else if((clz=="m1")||(clz=="m2")||(clz=="m3")||(clz=="m4")||(clz=="m5"))
    {
        ifstream fileSearch(clz+".txt");
        if(fileSearch.is_open())
        {
            while(fileSearch>>stID>>sub1>>sub2>>sub3>>tot)
            {
                if(stIDin == stID)
                {
                    system("cls");//clear the console

                    cout<<"------ STUDENT DETAILS ------"<<endl;

                    cout<<"\n";

                    cout << setw(15) << "ID" << setw(2) << ":" <<stID<<endl;
                    cout << setw(15) << "CLASS" << setw(2) << ":" <<clz<<endl;

                    cout<<"-----------------------------"<<endl;

                    cout << setw(15) << "COMB. MATHS" << setw(2) << ":" << sub1<<endl;
                    cout << setw(15) << "CHEMISTRY" << setw(2) << ":" << sub2<<endl;
                    cout << setw(15) << "PHYSICS" << setw(2) << ":" << sub3<<endl;

                    cout<<"-----------------------------"<<endl;

                    cout << setw(15) << "TOTAL MARKS" << setw(2) << ":" << tot<<endl;
                    break;
                }
            }
        }
        fileSearch.close();
    }
    else
    {
        system("cls");
        cout<< "Wrong Class Room!"<<endl;
    }

    searchStu::searchAgain();
}

void searchStu::searchAgain()
{
    //search again
    cout << "\n \n";
    string answer;
    cout<< "Do you like to search again? [y/n]" << setw(2) << ":";
    cin >> answer;

        if (answer=="y")
        {
            system("cls");
            searchStu::stuD();
        }
        else
        {
            system("cls");
            mainInterface mI; //crerate object
            mI.userInterface();
        }
}
