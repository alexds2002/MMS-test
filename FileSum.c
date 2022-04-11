#include <sys/types.h>
#include <unistd.h>
#include "FileSum.h"

int main(int argc, char* argv[]){

    if (argc < 2)
    {
        fprintf(stderr, "Not enought arguments!\n");
        return EXIT_FAILURE;
    }
    int fd[argc - 1][2];
    for (int i = 0; i < argc - 1; i++)
    {
        if (pipe(fd[i]) < 0)
        {
            return -1;
        }
        
    }

    
    for (int i = 1; i < argc - 1; i++){
        
        pid_t pid = fork();
        if (0 == pid){
            int16_t sum = 0;
            int16_t temp = 0;
            FILE* fp;
            if(fopen(argv[i], "rb") == NULL){
                // errno(); if i have time
                printf("file[%d] - Could not open\n", i);
            }
            while (fread(&temp, sizeof(int16_t), 1, fp) != EOF)
            {
                sum += temp;
            }
            if(write(fd[i - 1][1], &sum, sizeof(sum))) == -1)}
                fprintf(stderr, "Error with pipes!\n");
                return EXIT_FAILURE;
            }
            printf("file[%d] - %d\n", i, sum);
            fclose(argv[i]);

            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < argc - 1; i++){
        int16_t totalSum = 0;
        int16_t temp = 0;
        if(read(fd[i][0], &temp, sizeof(int16_t))) == -1{
            fprintf(stderr, "Error with pipes!\n");
            return EXIT_FAILURE;
        }
        totalSum += temp;
        wait(NULL);
    }

    
    return EXIT_SUCCESS;
}