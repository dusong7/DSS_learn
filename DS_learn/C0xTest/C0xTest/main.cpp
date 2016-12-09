//
//  main.cpp
//  C0xTest
//
//  Created by apple on 16/12/9.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
using namespace std;

class Name
{
public:
    Name();
    ~Name();
    void ShowName(string name);
private:
};

Name::Name()
{
    //
}

Name::~Name()
{

}

void Name::ShowName(string name)
{
    cout<< name << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Name nm;
    nm.ShowName("Dusong7");
    return 0;
}
