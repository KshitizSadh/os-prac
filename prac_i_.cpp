#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create child process

    if (pid == 0) {  // Child process
        std::cout << "This is the child process with PID " << getpid() << std::endl;
    } else {  // Parent process
        std::cout << "This is the parent process with PID " << getpid() << std::endl;
        wait(NULL);  // Wait for child to finish
    }

    return 0;
}
