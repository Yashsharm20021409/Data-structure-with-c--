#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int longestCommonSubsequence(int s1,int s2,char *st1,char *st2){
    int longest[s1+1][s2+1];
    for(int i = 0 ; i<= s1 ; i++){
        for(int j = 0 ; j<= s2 ; j++){
            if(i == 0 || j == 0){
                longest[i][j] =0;
            }
            else if(st1[i-1] == st2[j-1]){
                longest[i][j] = longest[i-1][j-1] + 1;
            }
            else{
                longest[i][j] = max(longest[i-1][j],longest[i][j-1]);
            }
        }
    }
    return longest[s1][s2];
}

int main(){
    string str1;
    string str2;

    //smallest
    cout<<"Enter the String1: ";
    cin>>str1;

    //largest
    cout<<"Enter the String2: ";
    cin>>str2;

    int s1 = str1.length(); 
    int s2 = str2.length();

    char st1[s1+1];
    char st2[s2+1];

    strcpy(st1, str1.c_str());
    strcpy(st2, str2.c_str());

    int longest = longestCommonSubsequence(s1,s2,st1,st2);

    cout<<"Longest Common Subsequence is: "<<longest<<endl;
}