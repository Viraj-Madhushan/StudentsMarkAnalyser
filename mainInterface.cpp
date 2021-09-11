#include "mainInterface.h"
#include "enterMark.h"
#include "searchStu.h"
#include "rankClass.h"
#include "rankSchool.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void mainInterface::userInterface()
{
    cout<<"---------- STUDENT MARK SHEET ----------"<<endl;

    cout<<"\n";

    cout<<"1. Enter Student Marks"<<endl;
    cout<<"2. Search Student"<<endl;
    cout<<"3. Student Rank in class"<<endl;
    cout<<"4. Student Rank in school"<<endl;
    cout<<"5. Exit"<<endl;

    cout<<"\n";

    cout<<"---------- ################## ----------"<<endl;

    cout<<"\n \n";

    //create objects
    enterMark interFace;
    searchStu ss;
    rankClass rc;
    rankSchool rs;

    int option;
    cout<<"Select an Option : ";
    cin>>option;

    //clear console
    system("cls");

    switch(option)
    {
        case 1: interFace.markInterface(); break;

        case 2: ss.stuD();break;

        case 3: rc.rankDescending();break;

        case 4: rs.rankSheet(); break;

        case 5: exit( 0 );
    }
}
