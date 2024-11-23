#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create child process

    if (pid == 0) {  // Child process
        std::cout << "This is the child process with PID " << getpid() << std::endl;
        // Child performs a different task
        std::cout << "Child: Executing different code!" << std::endl;
    } else {  // Parent process
        std::cout << "This is the parent process with PID " << getpid() << std::endl;
        // Parent performs its task
        std::cout << "Parent: Executing different code!" << std::endl;
        wait(NULL);  // Wait for child to finish
    }

    return 0;
}

