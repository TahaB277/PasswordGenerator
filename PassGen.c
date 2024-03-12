#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand(time(&t)); // setting seed for rand() fucntion

    char symbols[25] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '?', '/', '<', '>', ';', ':', '"', '[', ']', '{', '}' };
    // small chars from 97  to 123
    // capital letters from 65 to 91
    // numbers from 48 to 58

    int size;
    printf("Please give size of Password to be generated\n");
    scanf("%d", &size);
    if((size < 4) || (size > 15)){
        printf("Please pick a valid size!\n");
        return 1;
    }

    int randomizer1; 
    int randomizer2;
    char *ptr = malloc(size * sizeof(char));
    if(ptr == NULL){
        printf("Error with allocating the memory");
        return 1;
    }

    for(int i =0; i<size;i++){
        randomizer1 = rand() % 4 ; // 0 for symbols, 1 for small letters, 2 for capital letters, 3 for numbers
        switch (randomizer1) {
            case 0:
                randomizer2 = rand() % (sizeof(symbols) / sizeof(char));
                *(ptr + i) = symbols[randomizer2];
                break;
            case 1:
                randomizer2 = rand() % 26;
                *(ptr + i) = 97 + randomizer2;
                break;
            case 2:
                randomizer2 = rand() % 26;
                *(ptr + i) = 65 + randomizer2;
                break;
            case 3:
                randomizer2 = rand() % 10;
                *(ptr + i) = 48 + randomizer2;
                break;
        }
    }

    for(int j = 0;j<size;j++){
        printf("%c", *(ptr + j));
    }    
    printf("\n");

    return 0;
}