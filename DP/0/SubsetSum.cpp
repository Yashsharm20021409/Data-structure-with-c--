#include<iostream>

using namespace std;

int main(){
    int n;

    cout<<"Enter the size of an array: ";
    cin>>n;

    int arr[n];

    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }

    int target;

    cout<<"Enter Target: ";
    cin>>target;

    bool dp[n+1][target+1];

    for(int i = 0 ; i<=n ; i++){
        for(int j = 0 ; j<=target ; j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j] == true){
                   dp[i][j] = true;
                }
                else{
                    int val = arr[i-1];
                    if(val<=j){
                        if(dp[i-1][j-val] == true){
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[n][target];
}