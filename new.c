#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 256

typedef struct {
    int i;
    char s[50];
    float f;
} record_t;

int main() {
    int fd = open("text.txt", O_RDONLY);
    char buf[BUFF_SIZE];
    record_t records[100];
    ssize_t bytesRead;
    int num = 0;

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((bytesRead = read(fd, buf, sizeof(buf) - 1)) > 0) {
        buf[bytesRead] = '\0'; // Null-terminate the buffer for processing

        char *line = strtok(buf, "\n"); // Tokenize the buffer by lines
        while (line != NULL) {
            if (sscanf(line, "%d %s %f", &records[num].i, records[num].s, &records[num].f) == 3) {
                num++; // Successfully parsed one record
            }
            line = strtok(NULL, "\n"); // Move to the next line
        }
        printf("Print: %s\n",buf);
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);

    // Print the records to verify
    for (int i = 0; i < num; i++) {
        printf("%d %s %.2f\n", records[i].i, records[i].s, records[i].f);
    }

    return 0;
}
