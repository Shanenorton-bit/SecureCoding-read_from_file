#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINE_COUNT 200

void readFile(char *arg)
{
        //Copy the filename to buf
        char buf[100];
        strncpy(buf, arg, sizeof(buf));
        buf[sizeof(buf)-1] = '\0';

        //FID, line storage, and line array
        FILE *fp;
        char lineBuf[MAX_LINE_LENGTH];
        char lines[MAX_LINE_COUNT][MAX_LINE_LENGTH];
        fp = fopen(buf, "r");
	int i = 0;
	int counter = 0;
	
        //read the lines of the file to the max line count
        while(fgets(lineBuf, sizeof(lineBuf), fp) && i < MAX_LINE_COUNT)
        {
                lineBuf[sizeof(lineBuf) - 1] = '\0';
                strcpy(lines[i], lineBuf);
                i++;
		counter++;
        }
	
	//generate random seed and number
	srand(time(0));
	int upper = counter - 1;
	int lower = 0;
	int randNum = (rand() % (upper - lower + 1)) + lower;
	printf("Random line #%d  :  %s", randNum+1, lines[randNum]);
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		readFile(argv[1]);
	}
	else
	{
		printf("\nThis program expects an argument.\n\n");
	}
	return 0;


}
