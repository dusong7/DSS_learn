///This is a project for test thread
///

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream out;
    out.open("file",ios::app);
    out<<"Hello\n";
    out.close();

    string string1;
    ifstream in;
    in.open("file");
    while (getline(in,string1))
    {
        cout << string1 << endl;
    }
    in.close();

    return 0;
}