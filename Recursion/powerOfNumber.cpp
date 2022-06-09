#include<iostream>
using namespace std;

int power(int a,int b){

    // base case

    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    // processing
    int ans = power(a,b/2);

    // Recursive call
    if(b%2 == 0){
        // if power is even
        return ans*ans;
    }
    else{
        // if power is odd
        return a*ans*ans;
    }
}

int main(){
    int a;
    int b;

    cout<<"Enter Number: ";
    cin>>a;

    cout<<"Enter Power: ";
    cin>>b;

    int ans  = power(a,b);

    cout<<a<<" power "<<b<<" is "<<ans<<endl;
}