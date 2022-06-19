#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cout<<"Enter the Size of an array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the Elements into the array..."<<endl;
    for(int i = 0;i<n ; i++){
        cin>>arr[i];
    }

    int dp[n];
    int max;
    int omax = 0;

    for(int i = 0 ; i<n ; i++){
        max = 0;
        for(int j = 0; j <i ; j++){
            if(arr[j]<arr[i]){
                if(dp[j]>max){
                    max = dp[j];
                }
            }
        }
        dp[i] = max+1;

        // to get max from dp = longest inc subsequence

        if(dp[i]>omax){
            omax = dp[i];
        }
    }
    cout<<endl;
    cout<<"Longest Increasing Subsequence is: "<<omax<<endl<<endl;
}