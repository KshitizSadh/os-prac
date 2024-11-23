#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Kernel Version and Information:" << endl;
    system("uname -r");

    cout << "\nCPU Information:" << endl;
    system("lscpu");

    return 0;
}