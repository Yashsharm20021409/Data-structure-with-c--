#include<iostream>
using namespace std;


int main(){
    int profit[5] = {0,1,2,3,4};
    int weight[5] = {0,2,3,4,5};

    int m = 8; //knapsack size
    int n = 4; // number of object

    int knap[5][9];


    for(int i = 0 ;i<=n ; i++){
        for(int w = 0 ; w<= m ; w++){
            if(i == 0 || w == 0){
                knap[i][w] = 0;
            }
            else if(weight[i] <= w){
                knap[i][w] = max(profit[i]+ knap[i-1][w-weight[i]],knap[i-1][w]);
            }
            else{
                knap[i][w] = knap[i-1][w];
            }
        }
    }
    cout<<knap[n][m]<<endl;
}