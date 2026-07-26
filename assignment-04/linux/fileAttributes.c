#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

  
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat fileInfo;


    if (stat(argv[1], &fileInfo) == -1) {
        printf("No path provided!\n");
        return 1;
    }


    printf("=== File Attributes for: %s ===\n", argv[1]);

    // File Type
    printf("File Type:            ");

    if (S_ISREG(fileInfo.st_mode)) {

        printf("Regular File\n");
    }
    else if (S_ISDIR(fileInfo.st_mode)) {
        printf("Directory\n");

    }


    // Permissions
    printf("Permissions:          %04o\n", fileInfo.st_mode & 0777);

    // File Size
    printf("File Size:            %ld bytes\n", fileInfo.st_size);

    // Hard Links
    printf("Hard Links Count:     %ld\n", fileInfo.st_nlink);

    // Owner and Group
    printf("Owner (UID):          %d\n", fileInfo.st_uid);
    printf("Group (GID):          %d\n", fileInfo.st_gid);

    // Access Time
    printf("Last Access Time:     %s", ctime(&fileInfo.st_atime));

    // Modification Time
    printf("Last Modification:    %s", ctime(&fileInfo.st_mtime));

    // Status Change Time
    printf("Status Change Time:   %s", ctime(&fileInfo.st_ctime));

   
}