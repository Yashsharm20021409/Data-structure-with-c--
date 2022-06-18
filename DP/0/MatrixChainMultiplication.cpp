#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// #define INF 1000000009
// #define INF INT_MIN


int matrixChainMultiPlication(int arr[],int n){
    int dp[n][n];

    // memset(dp,INF,sizeof(dp));

    // fill dagonal element with 0

    for(int i = 1 ; i<n ; i++){
        dp[i][i] = 0;
    }

    int ran;

    for(int i =2 ; i<n ; i++){
        for(int j =1 ; j<n-i+1 ; j++){
            ran = i+j-1;
            dp[j][ran] = INT_MAX;
            for(int k = j ; k<=ran-1 ; k++){
                dp[j][ran] = min(dp[j][ran],dp[j][k]+dp[k+1][ran]+arr[j-1] *arr[k]*arr[ran]);
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int n;

    cout<<"Enter Number of Matrices: ";
    cin>>n;

    int arr[n];

    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }

    int ans = matrixChainMultiPlication(arr,n);

    cout<<"Minmum operation Performd: "<<ans<<endl;
}