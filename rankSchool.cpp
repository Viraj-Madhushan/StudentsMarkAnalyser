#include "rankSchool.h"
#include "mainInterface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void rankSchool::rankSheet()
{
    //read data from file, add total marks into array, descending order
    string clz;
    int stID;
    double tot;
    int lineAmount;




    //get length of file
    ifstream f("All_STUDENT.txt");
    if(f.is_open())
    {
        string line;
        for (lineAmount = 0; getline(f, line); ++lineAmount){}
    }
    f.close();

    double arrTot[lineAmount];
    int arrID[lineAmount];


    //Ask rank sheet or search by ID
    cout<<"------------- SCHOOL RANK -------------"<<endl;

    cout<<"\n";

    cout<<"1. Search by Student ID"<<endl;
    cout<<"2. Generate All Student Marks Sheet"<<endl;
    cout<<"3. Go Back To Main Menu"<<endl;

    cout<<"\n";

    cout<<"---------- ################## ----------"<<endl;

    cout<<"\n \n";

    int option;
    cout<<"Select an Option : ";
    cin>>option;

    //if condition for related option
    if(option==1)
    {
        ifstream rankSearch("All_STUDENT.txt");
        if(rankSearch.is_open())
        {
            int i=0;
            while(rankSearch >> stID >> clz >> tot )
            {
                arrTot[i] = tot;
                arrID[i] = stID;
                i++;
            }

            //rearranging order
            int temp, temp2;
            for(int k=0; k<lineAmount; k++)
            {
                for(int j=0; j<lineAmount-1; j++)
                {
                    if(arrTot[j] < arrTot[j+1])
                    {
                        temp = arrTot[j];
                        arrTot[j] = arrTot [j+1];
                        arrTot[j+1] = temp;

                        temp2 = arrID[j];
                        arrID[j] = arrID[j+1];
                        arrID[j+1] = temp2;
                    }
                }
            }

            //get student ID
            system("cls");//clear console

            cout<<"------------- SCHOOL RANK SEARCH by ID -------------"<<endl;

            cout<<"\n";

            int stIDin;
            cout << "Enter Student ID ";
            cin >> stIDin;


            system("cls");//clear console
            cout<<"------ STUDENT'S RANK ------"<<endl;

            cout<<"\n";

            cout << setw(1) <<"#" << setw(4) << "RANK" << setw(7) << "ST.ID" << setw(7)<< "TOTAL" << endl;
            cout <<"---------------------" <<endl;


            for (int j=0; j<lineAmount; j++)
            {
                if (arrID[j] == stIDin)
                {
                    cout << setw(1)<<"#" << setw(4) << j+1 << setw(7) <<arrID[j] << setw(7) << arrTot[j] << endl;
                    cout <<"---------------------" <<endl;
                    break;
                }
            }
        }
        rankSearch.close();

        //search again
        rankSchool::searchAgain();

    }//end of option 1
    else if(option==2)
    {
        ifstream rankSearch("All_STUDENT.txt");
        if(rankSearch.is_open())
        {
            int i=0;
            while(rankSearch >> stID >> clz >> tot )
            {
                arrTot[i] = tot;
                arrID[i] = stID;
                i++;
            }

            //rearranging order
            int temp, temp2;
            for(int k=0; k<lineAmount; k++)
            {
                for(int j=0; j<lineAmount-1; j++)
                {
                    if(arrTot[j] < arrTot[j+1])
                    {
                        temp = arrTot[j];
                        arrTot[j] = arrTot [j+1];
                        arrTot[j+1] = temp;

                        temp2 = arrID[j];
                        arrID[j] = arrID[j+1];
                        arrID[j+1] = temp2;
                    }
                }
            }

            system("cls");//clear console
            cout<<"------ STUDENTS RANK SHEET - ALL SCHOOL ------"<<endl;

            cout<<"\n";

            cout << setw(1) <<"#" << setw(4) << "RANK" << setw(7) << "ST.ID" << setw(7)<< "TOTAL" << endl;
            cout <<"---------------------" <<endl;


            for (int j=0; j<lineAmount; j++)
            {
                cout << setw(1)<<"#" << setw(4) << j+1 << setw(7) <<arrID[j] << setw(7) << arrTot[j] << endl;
                cout <<"---------------------" <<endl;
            }
        }
        rankSearch.close();
        //search again
        rankSchool::searchAgain();
    }//end of option 2
    else if(option==3)
    {
        system("cls");
        mainInterface mI;
        mI.userInterface();
    }
}

void rankSchool::searchAgain()
{
    //search again
    cout << "\n \n";
    string answer;
    cout<< "Do you like to search again? [y/n]" << setw(2) << ":";
    cin >> answer;

        if (answer=="y")
        {
            system("cls");
            rankSchool::rankSheet();
        }
        else
        {
            system("cls");
            mainInterface mI; //crerate object
            mI.userInterface();
        }
}
