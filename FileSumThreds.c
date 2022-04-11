#include "FileSumThreds.h"

int globalSum = 0;
pthread_mutex_t lock;
int main(int argc, char* argv[]){
    if (argc < 3)
    {
        fprintf(stderr, "Not enought arguments!\n");
        return EXIT_FAILURE;
    }
    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        pthread_create(&threads[i], NULL, SmOfFiles, (void*) argv[i]);
    }

    for (int i = 0; i < argc - 1; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return EXIT_SUCCESS;
}

void* SmOfFiles(void* arg){
    FILE* fp =fopen(arg, "rb");
    int16_t temp = 0;
    int16_t sum = 0;
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file\n");
    }
    while (fread(&temp, sizeof(int16_t), 1, fp) != EOF)
    {
        sum += temp;
    }
    pthread_mutex_lock(&lock);
    globalSum += sum;
    pthread_mutex_unlock(&lock);
    
    printf("Sum is: %d \n", sum);
    
    
}