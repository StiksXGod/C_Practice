#include <stdio.h>
#include <string.h>

#define PRIME 101
#define mod 72057594037927931

int poly_hash(char* str, int len){
    int hash = 0;
    for (int i = 0; i < len; i++)
    {
        hash = (hash+str[i]*pow(PRIME, len-i-1))%mod;
    }
    return hash;
    

}



void rabin_karp_serach(char* text, char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int pattern_hash = poly_hash(pattern,m);

    for (int i = 0; i <= n-m; i++)
    {
        int text_hash = poly_hash(text+i, m);
        if (text_hash == pattern_hash && strncmp(text+i,pattern,m)==0)
        {
            printf("Pattern found at index %d\n", i);
        }
        
    }
    
}