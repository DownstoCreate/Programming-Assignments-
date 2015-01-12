#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "HuffmanCoding.h"

using namespace std;

main()
{
     cout << "Enter your input file: " ;
    string line,phrase;
    string str;
    cin >> str;
    const char * x = str.c_str();
    ifstream myfile;
    myfile.open (x);
    while(getline(myfile,line))
    {
        phrase += line;

    }
    cout << "Enter your output file: ";
    string output;
    cin >> output;
    HuffmanCoding test(line);
    test.compress(output);




}
