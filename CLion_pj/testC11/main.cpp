#include <iostream>
#include <thread>
#include <sys/stat.h>

using namespace std;

void run()
{
    cout<<"Cur thhread"<<endl;
}

int main() {

    thread thread1(run);
    thread1.join();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}