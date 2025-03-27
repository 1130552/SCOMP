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
    snprintf(command, sizeof(command), "find / -type f -name '%s' 2>/dev/null | head -n 1", backup_file);

    fp = popen(command, "r");
    if(fp == NULL) {
        perror("popen failed");
        exit(1);
    }

    if(fgets(filepath, sizeof(filepath), fp) == NULL) {
        printf("File not found\n");
        pclose(fp);
        exit(1);
    }

    pclose(fp);

    filepath[strcspn(filepath, "\n")] = 0;

    printf("Found file: %s \n", filepath);

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
        printf("Backup completed.");
    }

    return 0;
}