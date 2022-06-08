#include<iostream>
using namespace std;

// tail recursion print counting in reverse order

// void printCounting(int n){
//     // base condition
//     if(n == 0)
//        return ;
    
//     cout<<n<<" ";

//     //Recurrance relation
//     printCounting(n-1);
// }
// head recursion

void printCounting(int n){
    // base condition
    if(n == 0)
       return ;
    
    //Recurrance relation
    printCounting(n-1);

    cout<<n<<" ";
}

int main(){
    int n;

    cout<<"Enter the Number: ";
    cin>>n;

    printCounting(n);

    return 0;
}