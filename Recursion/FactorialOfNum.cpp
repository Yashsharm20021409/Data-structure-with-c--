#include<iostream>
using namespace std;

int factorial(int n){

    // base case
    if(n == 0){
        return 1;
    }
    
    // use of recurance realtion
    // just to make you understand

//    int smallerProblem = factorial(n-1);
//    int biggerProblem = n*smallerProblem;

//    return biggerProblem; 

//    use of recurance realtion
      return n*factorial(n-1);
}

int main(){
    int n;

    cout<<"Enter the Number: ";
    cin>>n;

    int ans = factorial(n);

    cout<<"The Ans is: "<<ans<<endl;
}