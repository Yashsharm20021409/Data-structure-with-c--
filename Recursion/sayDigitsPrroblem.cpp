#include<iostream>
using namespace std;

void sayDigit(int num,string arr[]){
    // base case 
    if(num == 0){
        return ;
    }

    // processing
    int digit = num%10;
    num /=10;

    //R.R

    sayDigit(num,arr);

   // write this line below to print in proper manner as digit given in number
    cout<<arr[digit]<<" ";

}

int main(){
    string arr[10] = {
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };

    int num;
    cout<<"Enter Number: ";
    cin>>num;

    cout<<endl;
    sayDigit(num,arr);
    cout<<endl;
}