#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>


/* This is the main function how scan the dirs*/
void listfiles(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        printf("\x1b[32m" "%s   ", entry->d_name);
    }

    closedir(dp);
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        char cwd[1024]; // Assuming a reasonable buffer size
    	getcwd(cwd, sizeof(cwd)); // if you don't write The path to the target dir it will just scan the working dir
    	listfiles(cwd);
    }
    else{
        char *path = argv[1];
        listfiles(path);
    }

    return 0;
}
