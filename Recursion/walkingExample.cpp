#include<iostream>
using namespace std;

void reachHome(int src,int dest){

    cout<<"Source "<<src<<" Destination "<<dest<<endl;

    // base case
    if(src == dest){
        cout<<"Reached home"<<endl;
        return ;
    }

    // processing :- we know one by one step we reach dest from src
    src++;

    //recursive call 
    reachHome(src,dest);
}

int main(){
    int src = 1;
    int dest = 10;

    reachHome(src,dest);
}