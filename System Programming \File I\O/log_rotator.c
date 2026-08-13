#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1024L

long getFileSize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) != 0) {
        perror("Unable to get file information");
        return -1;
    }

    return (long)st.st_size;
}

int ensureLogFile(const char *filename) {
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Unable to create/open log file");
        return 0;
    }

    fclose(file);
    return 1;
}

void appendLog(const char *filename, const char *message) {
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }

    fprintf(file, "%s\n", message);
    fclose(file);

    printf("Log added successfully.\n");
}

void rotateLog(const char *filename) {
    char backupName[256];

    snprintf(backupName, sizeof(backupName), "%s.1", filename);

    if (rename(filename, backupName) != 0) {
        perror("Unable to rotate log file");
        return;
    }

    if (!ensureLogFile(filename)) {
        fprintf(stderr, "Warning: old log was renamed but new log could not be created.\n");
        return;
    }

    printf("Log rotated successfully.\n");
}

int main(void) {
    const char *filename = "application.log";
    int choice;

    if (!ensureLogFile(filename))
        return 1;

    while (1) {
        printf("\n===== LOG ROTATOR =====\n");
        printf("1. Add log\n");
        printf("2. Show file size\n");
        printf("3. Rotate log\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        if (choice == 1) {
            char message[500];

            getchar();
            printf("Enter log message: ");
            if (fgets(message, sizeof(message), stdin) == NULL) {
                printf("Unable to read message.\n");
                continue;
            }

            message[strcspn(message, "\n")] = '\0';
            appendLog(filename, message);
        } else if (choice == 2) {
            long size = getFileSize(filename);

            if (size >= 0) {
                printf("Current file size: %ld bytes\n", size);

                if (size >= MAX_FILE_SIZE)
                    printf("Warning: file exceeds the recommended size limit.\n");
            }
        } else if (choice == 3) {
            rotateLog(filename);
        } else if (choice == 4) {
            printf("Program terminated.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
