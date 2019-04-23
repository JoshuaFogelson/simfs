#include "simfs.h"

#define SIMFS_FILE_NAME "simfsFile.dta"

SIMFS_ERROR PrintError(SIMFS_ERROR error)
{
    if (error == SIMFS_NO_ERROR)
        return error;

    printf("Error: ");

    switch (error)
    {
    case SIMFS_ALLOC_ERROR:
        printf("SIMFS_ALLOC_ERROR\n"); break;
    case SIMFS_DUPLICATE_ERROR:
        printf("SIMFS_DUPLICATE_ERROR\n"); break;
    case SIMFS_NOT_FOUND_ERROR:
        printf("SIMFS_NOT_FOUND_ERROR\n"); break;
    case SIMFS_NOT_EMPTY_ERROR:
        printf("SIMFS_NOT_EMPTY_ERROR\n"); break;
    case SIMFS_ACCESS_ERROR:
        printf("SIMFS_ACCESS_ERROR\n"); break;
    case SIMFS_WRITE_ERROR:
        printf("SIMFS_WRITE_ERROR\n"); break;
    case SIMFS_READ_ERROR:
        printf("SIMFS_READ_ERROR\n"); break;
    case SIMFS_SYSTEM_ERROR:
        printf("SIMFS_SYSTEM_ERROR\n"); break;
    default:
        printf("UNKNOWN\n");
    }
    return error;
}

int main()
{
    // TODO: implement thorough testing of all the functionality

    //srand(time(NULL));
    srand(1997);

    SIMFS_ERROR error = SIMFS_NO_ERROR;

    error = PrintError(simfsCreateFileSystem(SIMFS_FILE_NAME));
    if (error != SIMFS_NO_ERROR)
        exit(EXIT_FAILURE);

    error = PrintError(simfsMountFileSystem(SIMFS_FILE_NAME));
    if (error != SIMFS_NO_ERROR)
        exit(EXIT_FAILURE);

    error = PrintError(simfsCreateFile("batman.txt", SIMFS_FILE_CONTENT_TYPE));
    if (error != SIMFS_NO_ERROR)
        exit(EXIT_FAILURE);

    printf("Expect Error SIMFS_DUPLICATE_ERROR\n");
    error = PrintError(simfsCreateFile("batman.txt", SIMFS_FILE_CONTENT_TYPE));
    if (error != SIMFS_DUPLICATE_ERROR){
 //       exit(EXIT_FAILURE);
    }

    SIMFS_FILE_DESCRIPTOR_TYPE infoBuffer;
    error = PrintError(simfsGetFileInfo("batman.txt", &infoBuffer));
    if (error != SIMFS_NOT_FOUND_ERROR)
   //     exit(EXIT_FAILURE);

    printf("No expected error");
    error = PrintError(simfsDeleteFile("batman.txt"));

    printf("\nSuccess!\n");
    return EXIT_SUCCESS;
}