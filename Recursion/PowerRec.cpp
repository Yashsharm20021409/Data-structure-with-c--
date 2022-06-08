#include<iostream>
using namespace std;

int Power(int n){

    // base case

    if(n == 0)
       return 1;

    // recurance relation   
    
    // int smallProblem = Power(n-1);
    // int biggerProblem = 2*smallProblem;

    // return biggerProblem;

    return 2*Power(n-1);
}

int main(){
    int n;

    cout<<"Enter Number: ";
    cin>>n;

    int ans = Power(n);

    cout<<"Ans: "<<ans<<endl;
}