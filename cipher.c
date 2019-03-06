#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

    FILE *CB_cipherText_FD; // output file
    FILE *CB_key_FD; // key file
    
    //key file naming
    char CB_keyFileName_FD[128];
    char* CB_exten_FD = ".pda";

    if(argc == 3) // user gave output file name
    {
        CB_cipherText_FD = fopen(argv[2],"w"); // write only output file   
        //strncpy(CB_keyFileName, argv[2], sizeof(filename)); //TODO
    }
    else
    {
        CB_cipherText_FD = fopen("ciphered","w"); // write only output file    
    }



    CB_key_FD = fopen("key.pda","w"); // create key File
    
    

    if(!CB_textFile_FD)
    {
        printf("Failed to open %s", argv[1]);
        return 1;
    }


    char CB_buff_FD, CB_alea_FD , CB_res_FD;
    
    while(!feof(CB_textFile_FD)) // while file can be read
    {
               
        fscanf(CB_textFile_FD, "%c", &CB_buff_FD);
        CB_alea_FD = rand();
        CB_res_FD = CB_buff_FD ^ CB_alea_FD; // bitwise XOR of buff with alea
        fwrite(&CB_res_FD, sizeof(CB_res_FD), 1, CB_cipherText_FD); //write output file
        fwrite(&CB_alea_FD, sizeof(CB_alea_FD), 1, CB_key_FD); //write key file
        printf("%c",CB_res_FD); // display output file
    }

}