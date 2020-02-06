#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SHM_SIZE 1024 //shared memory size

void swap (char *fp);

int main (int argc, char **argv)
{
	FILE * input_file;
	char* input;
	int shmem_handle;
	char * shmem_point;
	int * read_from_file;
	int finished = 0;
        key_t key;
        sem_t sem_buffer;
	if (argc > 1) //if user enters a file
	{
		input = argv[1]; //takes in name of file user gave
	}
	else
	{
		printf ("please give a .txt input file : exiting program\n");
		exit(1); //no file given
	}
	/*
	if (input_file == NULL) //if file was not opened
	{
                printf("Could not open given file");
                exit(1);
        }
	*/
	swap (argv[1]);
}

	void swap (char *fp)
	{
        FILE* file_input = fopen(fp,"r");
        FILE* file_swap = fopen("screen.txt","w"); //temp swap file
	if (file_input == NULL) //if file was not opened
        {
                printf("Could not open given file");
                exit(1);
        }
        char buffer[3]; //one bigger for NULL byte
        char first[2]; //used for memcpy
        while (fread(buffer,1,2,file_input) == 2) //while reading from the file
        {
		memcpy (first , buffer , sizeof(buffer));
                // fprintf(file_swap, "%c%c" , first[0] , first[1]); //swaped, unswap lol only for swap
		printf("%c%c" , first[0] , first[1]);
	}
	printf  ("\0");  //null bit
	printf  ("\n");  //new line bit
        fclose(file_input); //always close when done
        fclose(file_swap);
	}
