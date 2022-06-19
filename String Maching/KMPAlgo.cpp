#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char *pat,int *lps,int m){
    // lenght of previous common suffix
    int len = 0;

    lps[0]  = 0;
    int i = 1;

    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                // to set len(j) at that position from where pattern is not match na ki bilkul start me
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *txt,char *pat){
    int m = strlen(pat);
    int n = strlen(txt);

    // Create lps for store longest common prefix suffix
    int lps[m];

    computeLPSArray(pat,lps,m);
    int i = 0;
    int j = 0;

    while(i<n){
        if(pat[i] == txt[j]){
            i++;
            j++;
        }

        if(j == m){
            int ind = i-j;
            cout<<"Pattern found at index: "<<ind<<endl;
            j = lps[j-1];
        }

        else if(i<n && pat[j] != txt[i]){
            if(j != 0){
               j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main(){
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(txt,pat);

    return 0; 
}