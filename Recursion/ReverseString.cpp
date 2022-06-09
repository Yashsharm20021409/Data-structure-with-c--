#include<iostream>
using namespace std;

// void reverseString(int i,int j,string &str){

//     // rec call
//     cout<<str<<" ";

//     // base case 
//     if(i>j){
//         return ;
//     }

//     swap(str[i],str[j]);
//     i++;
//     j--;

//     // R.R
//     reverseString(i,j,str);
// }

// optimize code using single pointer only pending--------->>>>>>

void reverseString(int i,string &str){

    // rec call
    cout<<str<<" ";

    // base case 
    if(i>str.length()-1-i){
        return ;
    }

    swap(str[i],str[str.length()-1-i]);
    i++;

    // R.R
    reverseString(i,str);
}

int main(){
    string str;

    cout<<"Enter the string: ";
    cin>>str;

    int i =0 , j = str.length() -1;

    // reverseString(i,j,str);
    // optimize code
    reverseString(i,str);

    cout<<str<<endl;
}