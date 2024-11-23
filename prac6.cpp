#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* source = "source.txt";
    const char* destination = "destination.txt";

    int src = open(source, O_RDONLY);
    if (src == -1) {
        std::cerr << "Error opening source file!" << std::endl;
        return 1;
    }

    int dest = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        std::cerr << "Error opening destination file!" << std::endl;
        close(src);
        return 1;
    }

    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }

    close(src);
    close(dest);

    std::cout << "File copied successfully!" << std::endl;
    return 0;
}
