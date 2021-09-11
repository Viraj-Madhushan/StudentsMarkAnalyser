#include "rankClass.h"
#include "mainInterface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void rankClass::rankDescending()
{
    //read data from file, add total marks into array, descending order
    string clz;
    int stID;
    int thrw;
    double tot;
    int lineAmount;


    cout<<"------ STUDENTS RANK IN THE CLASS ------"<<endl;

    cout<<"\n";

    cout << "Enter Class to get Rank List" << setw(2) << ":";
    cin >> clz;


    //get length of file
    ifstream f(clz+".txt");
    if(f.is_open())
    {
        string line;
        for (lineAmount = 0; getline(f, line); ++lineAmount){}
    }
    f.close();

    //assign to array length
    double arrTot[lineAmount];
    int arrID[lineAmount];

    //get data from file
    ifstream rankSearch(clz+".txt");
    if(rankSearch.is_open())
    {
        int i=0;
        while(rankSearch >> stID >> thrw >> thrw >> thrw >> tot )
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

        system("cls");
        cout<<"------ STUDENTS RANK SHEET - "<< clz <<" CLASS ------"<<endl;

        cout<<"\n";

        cout << setw(1) <<"#" << setw(4) << "RANK" << setw(8) << "ST. ID" << setw(7)<< "TOTAL" << endl;
        cout <<"---------------------" <<endl;

        for (int j=0; j<lineAmount; j++)
        {
            cout << setw(1)<<"#" << setw(4) << j+1 << setw(8) <<arrID[j] << setw(7) << arrTot[j] << endl;
            cout <<"---------------------" <<endl;
        }
    }
    rankSearch.close();






    //search again
        cout << "\n \n";
        string answer;
        cout<< "Do you like to search again? [y/n]" << setw(2) << ":";
        cin >> answer;

            if (answer=="y")
            {
                system("cls");
                rankClass::rankDescending();
            }
            else
            {
                system("cls");
                mainInterface mI; //crerate object
                mI.userInterface();
            }
}

