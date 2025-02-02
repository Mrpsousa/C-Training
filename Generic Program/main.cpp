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
            cout << "\n Key :" << key << "\t" << "Data :" << data << endl;
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
        system("clear");
        switch (choice)
        {
            case 1: // saving the data to file
            {
                obj.input();
                file.open("data", ios::out | ios::app | ios::binary);
                file.write((char*) &obj, sizeof(obj)); //make saving in bin mode
                file.close();
                system("clear");
                cout << "Data written succesfully";
                obj.show();
                cout << "\n";
                getchar();
                //need to fix and put a "system("pause")" here
                break;
            }
            case 2: // display / show all records from the file
            {
                file.open("data",ios::in);
                while (file.read((char*) &obj, sizeof(obj)))
                {
                    obj.show();
                }
                getchar();
                break;
            }
            case 3:
            {
                int k, flag = 0;
                system("clear");
                cout << "Enter the record you want to search: ";
                cin >> k;
                file.open("data", ios::in | ios::binary);
                while(file.read((char*) & obj, sizeof(obj)))
                {
                    if(obj.rt_key() == k)
                    {
                        obj.show();
                        file.close();
                        flag = 1;
                        break;
                        
                    }
                }
                file.close();
                if(flag == 0)
                {
                    cout << "Sorry record not found \n";
                    getchar();
                    break;
                }else{  cout << " Found with sucess \n";}
            }
            case 4:
            {
                int k, flag = 0;
                char ch;
                system("clear");
                cout << "Enter the record(key filed)you want to modify/edit: ";
                cin >> k;
                file.open("data", ios::in | ios::out | ios::binary);
                while(file.read((char*) & obj, sizeof(obj)) && (flag == 0))
                {
                    if(obj.rt_key() == k)
                    {
                        cout << "key found with following details \n";
                        obj.show();
                        cout <<"\n";
                        cout << "Do You want to still edit - Y or N - \n";
                        cin >> ch;
                        if(ch=='y' || ch=='Y')
                        {
                            file.seekp(-1 * sizeof(obj), ios::cur);
                            obj.input();//initializing the object with new data
                            file.write((char*)&obj, sizeof(obj));
                            flag = 1;
                            
                        }else{
                            break;
                        }
                    }
                }
                if(flag == 1)
                    cout << "Change sucess";
                else
                    cout << "can't find ur record";
                
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
    cout << "\n";
    cout << "-------------------------------------------";
    cout << "\nWelcome to the project development \n";
    cout << "\nPlease enter te following option to operate:\n";
    cout << "\nPress 1: to save record \n";
    cout << "Press 2: to display all record \n";
    cout << "Press 3: to search perticular record \n";
    cout << "Press 4: to modify the record \n";
    cout << "Press 5: to delete specific record \n";
    cout << "Press 6: to to Exit \n";
}