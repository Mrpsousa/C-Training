#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
    string str1 = "casa", str2 = "casa";
    
std::string text = "Let me split this into words";
 
std::istringstream iss(text);
std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());

    return 0;
}