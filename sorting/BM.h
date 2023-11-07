#include<stdio.h>
#include<string.h>

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

void bm_search(char* text, char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int bad_char[ALPHABET_SIZE];
    memset(bad_char, m, 256*sizeof(int));

    for (int i = 0; i < m-1; i++)
    {
        bad_char[pattern[i]] = m-i-1;
    }
    int i = m-1;
    while(i<n){
        int j = m-1;
        while(text[i] == pattern[j]){
            if (j==0)
            {
                printf("Pattern found at index %d\n", i);
                break;

            }
            i--;
            j--;
            
        }
        i+=bad_char[text[i]];
    }
    
}