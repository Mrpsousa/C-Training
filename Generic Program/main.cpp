/*
1.Saving the data
2.Display/show all records
3.Search
4.Modify the data/record
5.deleting some data record from file
*/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

//---prototypes
void menu(void);

//--- classes
class record
{
    int key;
    char data[256];

    public:
        void input() //recording data
        {
            cout << "Please enter the key field \n";
            cin >> key;
            cout << "Please enter the data field \n";
            cin >> data;
        }
        
        void show() //display data
        {
            cout << "\n Key :" << key << "\t" << "Data :" << data;
        }

        int rt_key(){ return key; } //return key to search
};

fstream file;

int main()
{
    record obj;
    int choice;
    while(1)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
            case 1: // saving the data to file
            {
                obj.input();
                file.open("data", ios::out | ios::app);
                file.write((char*) &obj, sizeof(obj)); //make saving in bin mode
                system("clear");
                cout << "Data written succesfully";
                getchar();
                //need to fix and put a "system("pause")" here
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                exit(0);
                //ajeitar o "exit(0);"
            }
        }    
    }
    
    
    return 0;
}

void menu()
{
    cout << "\nWelcome to the project development \n";
    cout << "\nPlease enter te following option to operate:\n";
    cout << "\nPress 1: to save record \n";
    cout << "Press 2: to display all record \n";
    cout << "Press 3: to search perticular record \n";
    cout << "Press 4: to modify the record \n";
    cout << "Press 5: to delete specific record \n";
    cout << "Press 6: to to Exit \n";
}