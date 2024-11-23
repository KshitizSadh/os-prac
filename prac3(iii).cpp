#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create child process

    if (pid == 0) {  // Child process
        std::cout << "Child process with PID " << getpid() << " started." << std::endl;
        sleep(2);  // Simulating work in child
        std::cout << "Child process finished." << std::endl;
    } else {  // Parent process
        std::cout << "Parent process with PID " << getpid() << " started." << std::endl;
        wait(NULL);  // Wait for child to finish
        std::cout << "Parent process resumed after child finished." << std::endl;
    }

    return 0;
}
