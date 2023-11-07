#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void prefix_function(char* pattern, int* pi){
    int m = strlen(pattern);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j!=0 && pattern[i] != pattern[j])
        {
            j = pi[j-1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        pi[i] = j;
        
        
    }

}

void kmp_search(char* text, char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int pi[m];
    prefix_function(pattern, pi);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        while (k>0 && pattern[k]!=text[i])
        {
            k = pi[k-1];
        }
        if (pattern[k] == text[i])k++;

        if (k==m)
        {
            printf("%d ", i-m+1);
            k = pi[k-1];
        }
        
        
        
    }
    
}

int main(){
    char* pattern = "abcabc";
    int pi[strlen(pattern)];
    prefix_function(pattern, pi);
    for(int i = 0; i < strlen(pattern); ++i){
        printf("%d ", pi[i]);
    }
    printf("\n");
}
