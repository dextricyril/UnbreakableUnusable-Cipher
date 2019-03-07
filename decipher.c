#include <stdio.h>


int main(int argc, char **argv)
{
    if(argc != 3) // 2 arguments 0 is executable name
    {
        printf("Did not received correct arguments\nUsage: ./cipher cipheredFile.txt key.pda\n");
        return 1;
    }

    FILE *CB_cipheredFile_FD; //cipheredFile input 
    FILE *CB_keyFile_FD;
    CB_cipheredFile_FD=fopen(argv[1],"r"); //open file in reading
    CB_keyFile_FD=fopen(argv[2],"r");
    if(!CB_cipheredFile_FD || !CB_keyFile_FD) //check if file opened successfully
    {
        printf("Failed to open %s or %s", argv[1] , argv[2]);
        return 1;
    }
    char CB_keyBuff_FD, CB_cipherBuff_FD, CB_res_FD;
    while(!feof(CB_cipheredFile_FD) && !feof(CB_keyFile_FD)) // stop  if one of the file reach its end
    {
        fscanf(CB_cipheredFile_FD,"%c",&CB_cipherBuff_FD); //read char from ciphered file
        fscanf(CB_keyFile_FD,"%c",&CB_keyBuff_FD); //read char from key file
        CB_res_FD = CB_cipherBuff_FD ^ CB_keyBuff_FD; // bitwise xor
        printf("%c",CB_res_FD); // display dicephering results
    }
    return 0;
}
