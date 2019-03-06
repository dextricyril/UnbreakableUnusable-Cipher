#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2 || argc >3) // 1 or 2 arguments 0 is executable name
    {
        printf("Did not received enough arguments\nUsage: ./cipher textFile.txt\n");
        return 1;
    }
    srand(time(NULL)); // init rand

    FILE *CB_textFile_FD; //textFile input 
    CB_textFile_FD=fopen(argv[1],"r"); //open file in reading
    if(!CB_textFile_FD) //check if file opened successfully
    {
        printf("Failed to open %s", argv[1]);
        return 1;
    }
    FILE *CB_cipherFile_FD; // output file
    FILE *CB_key_FD; // key file
    
    //key file naming
    char CB_keyFileName_FD[128];
    char CB_exten_FD[] = ".pda";

    if(argc == 3) // user gave output file name
    {
        CB_cipherFile_FD = fopen(argv[2],"w"); // write only output file   
        strncpy(CB_keyFileName_FD, argv[2], sizeof(CB_keyFileName_FD)); //TODO
    }
    else
    {
        CB_cipherFile_FD = fopen("ciphered","w"); // write only output file
        strncpy(CB_keyFileName_FD, argv[1], sizeof(CB_keyFileName_FD));    
    }
    strncat(CB_keyFileName_FD, CB_exten_FD, (sizeof(CB_keyFileName_FD) - strlen(CB_keyFileName_FD)) );



    CB_key_FD = fopen(CB_keyFileName_FD,"w"); // create key File



    char CB_buff_FD, CB_alea_FD , CB_res_FD;
    
    // get size
    fseek(CB_textFile_FD, 0, SEEK_END);
    long CB_len_FD = ftell(CB_textFile_FD);
    
    if(CB_len_FD == 0) // check if file is empty
    {
         printf("File is empty %ld", CB_len_FD);
        return 1;
    }

    fseek(CB_textFile_FD, 0, SEEK_SET); // reset pointer to start of file
    while(!feof(CB_textFile_FD)) // while file can be read
    {
               
        fscanf(CB_textFile_FD, "%c", &CB_buff_FD);
        CB_alea_FD = rand();
        CB_res_FD = CB_buff_FD ^ CB_alea_FD; // bitwise XOR of buff with alea
        fwrite(&CB_res_FD, sizeof(CB_res_FD), 1, CB_cipherFile_FD); //write output file
        fwrite(&CB_alea_FD, sizeof(CB_alea_FD), 1, CB_key_FD); //write key file
        printf("%c",CB_res_FD); // display output file
    }
    //close all files
    fclose(CB_key_FD);
    fclose(CB_textFile_FD);
    fclose(CB_cipherFile_FD);
    return 0;

}