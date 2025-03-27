#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char backup_file[255];
    char backup_dir[255] = "/media/sf_partilha/modulo01/backup";
    char filepath[1024];

    printf("Enter the file to backup\n");
    scanf("%s", backup_file);

    FILE *fp;
    char command[1024]; 
    // I used snprintf to create the command to find the file that the user inputed.
    snprintf(command, sizeof(command), "find / -type f -name '%s' 2>/dev/null | head -n 1", backup_file);

    // We run the command with popen and read it into fp, so we can read the output as if it were a file.
    fp = popen(command, "r");
    if(fp == NULL) {
        perror("popen failed");
        exit(1);
    }

    // Check if fp has anything in it, if it does it found the file in the system.
    if(fgets(filepath, sizeof(filepath), fp) == NULL) {
        printf("File not found\n");
        pclose(fp);
        exit(1);
    }

    pclose(fp);

    // Remove newline from filepath
    filepath[strcspn(filepath, "\n")] = 0;

    printf("Found file: %s \n", filepath);

    // Back up the found file running exec in a child process.
    pid_t pid = fork();

    if(pid < 0) {
        perror("Fork failed.");
        exit(1);
    }

    if(pid == 0) {
        execl("/bin/cp", "cp", filepath, backup_dir, NULL);
        perror("Backup failed.");
        exit(1);
    } else {
        wait(NULL);
        printf("Backup completed.\n");
    }

    return 0;
}