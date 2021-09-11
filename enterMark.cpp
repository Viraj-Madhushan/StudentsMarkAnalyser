#include "enterMark.h"
#include "mainInterface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

void enterMark::markInterface()
{
    //select bio or maths
    cout<<"------ ENTER MARK - SELECT STREAM ------"<<endl;

    cout<<"\n";

    string strm;
    cout<<"Select Stream [B-Bio/M-Maths]" <<setw(2)<<":";
    cin>>strm;

    system("cls");//clear console

    if((strm=="b")||(strm=="B"))
    {
        stDetailsBio();
    }
    else if((strm=="m")||(strm=="M"))
    {
        stDetailsMaths();
    }
    else
    {
        cout<<"Wrong Entry...!"<<endl;
        markInterface();
    }
}

/*-----------------------------B I O------------------------------------*/
void enterMark::stDetailsBio()
{
    cout<<"-------- ENTER MARK - BIO STREAM -------"<<endl;

    cout<<"\n";

    cout<< setw(25) << left << "Class (b1,b2,b3)" << setw(2) << ":";
    cin>>clz;

    cout<< setw(25) << left << "Student ID" << setw(2) << ":";
    cin>>stID;

    cout<<"\n \n";

    cout<<"--------------- SUBJECTS ---------------"<<endl;

    cout<<"\n";

    cout<< setw(25) << left << "BIOLOGY" << setw(2) << ":";
    cin>>sub1;

    cout<< setw(25) << left << "CHEMISTRY" << setw(2) << ":";
    cin>>sub2;

    cout<< setw(25) << left << "PHYSICS" << setw(2) << ":";
    cin>>sub3;

    enterMark::inputData();
}

/*-----------------------------M A T H S------------------------------------*/
void enterMark::stDetailsMaths()
{
    cout<<"-------- ENTER MARK - MATHS STREAM -------"<<endl;

    cout<<"\n";

    cout<< setw(25) << left << "Class (m1,m2,m3,m4,m5)" << setw(2) << ":";
    cin>>clz;

    cout<< setw(25) << left << "Student ID" << setw(2) << ":";
    cin>>stID;

    cout<<"\n \n";

    cout<<"--------------- SUBJECTS ---------------"<<endl;

    cout<<"\n";

    cout<< setw(25) << left << "COMB. MATHS" << setw(2) << ":";
    cin>>sub1;

    cout<< setw(25) << left << "CHEMISTRY" << setw(2) << ":";
    cin>>sub2;

    cout<< setw(25) << left << "PHYSICS" << setw(2) << ":";
    cin>>sub3;

    enterMark::inputData();
}

void enterMark::inputData()
{
    //input data into files according to classes

    double tot;
    tot=sub1+sub2+sub3;//calculate total marks


    fstream clzSheet;
    clzSheet.open(clz+".txt", ios::app);

    if(clzSheet.is_open())
    {
        clzSheet << stID << ' ' << sub1 << ' ' << sub2 << ' ' << sub3 <<' ' << tot<< endl;
    }
    clzSheet.close();

    //All students marks
    clzSheet.open("All_STUDENT.txt", ios::app);
    if(clzSheet.is_open())
    {
        clzSheet << stID << ' ' << clz << ' ' << tot << endl;
    }
    clzSheet.close();

    //add more details
    system("cls");
    cout << "Data Added Successfully!" << endl;
    char answer;
    cout << "Do you like to add another result? [y/n]" << setw(2) << ":";
    cin >> answer;

    if(answer=='y')
    {
        system("cls");
        markInterface();
    }
    else if(answer=='n')
    {
        system("cls");
        mainInterface mI;
        mI.userInterface();
    }
}

