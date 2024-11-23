#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "Memory Information:" << std::endl;
    system("free -h");

    return 0;
}
