#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapSack(int *weight,int *profit,int w,int n){
    // base case

    if(n == 0 || w == 0){
        return 0;
    }

    if(weight[n] > w){
        return knapSack(weight,profit,w,n-1);
    }
    else{
        return max(knapSack(weight,profit,w,n-1) , profit[n]+ knapSack(weight,profit,w-weight[n],n-1));
    }
}

int main(){
    int n;
    int w;
    cout<<"Enter Number of Items: ";
    cin>>n;

    cout<<"Enter size of KnapSack: ";
    cin>>w;

    int weight[n];
    int profit[n];

    cout<<"Enter values..."<<endl;
    cout<<"Weight"<<endl;
    for(int i = 0 ; i<n ; i++){
        cin>>weight[i];
    }
    cout<<"Profit"<<endl;
    for(int i = 0 ; i<n ; i++){
        cin>>profit[i];
    }

    int maxProfit = knapSack(weight,profit,w,n);
    cout<<"Maimum Profit gain: "<<maxProfit<<endl;
}