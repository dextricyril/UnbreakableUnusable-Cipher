#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Did not received enough arguments\nUsage: ./cipher textFile.txt\n");
        return 1;
    }
    time_t CB_t = time(NULL); //set time 

    FILE *CB_textFile; //textFile input 
    CB_textFile=fopen(argv[1],"r"); //open file in reading

    FILE *CB_cipherText; // output file
    FILE *CB_key; // key file
    if(argc == 3) // user gave output file name
    {
        CB_cipherText = fopen("ciphered","w"); // write only output file    
    }
    else
    {
        CB_cipherText = fopen(argv[2],"w"); // write only output file        
    }
    
    CB_key = fopen("key.pda","w"); // create key File
    
    

    if(!CB_textFile)
    {
        printf("Failed to open %s", argv[1]);
        return 1;
    }


    char buff;
    
    while(!feof(CB_textFile)) // while file can be read
    {
               
        fscanf(CB_textFile, "%c", &buff);
        printf("%c",buff);
        fwrite(&buff, sizeof(buff), 1, CB_cipherText);
    }
}