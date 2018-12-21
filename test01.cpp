#include <fstream>
#include <iostream>
#include <string.h>
 
using namespace std;

int main()
 {
    string line;
    string aux_str;
    char *s;
    //Cliente *aux = new Cliente;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            
            cout << s.c_str(line) << endl;
            getline (myfile,line);
            cout << line << endl;
            getline (myfile,line);
            cout << line << endl;
            getline (myfile,line);
            cout << line << endl;
            
        }
    myfile.close();
    
  }else cout << "Unable to open file"; 
  return 0;
}