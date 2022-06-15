#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector <pair<int,int>> activity;
    int n;
    int start;
    int end;

    cout<<"Enter Number of Activity: ";
    cin>>n;

    for(int i = 0 ; i< n ; i++){
        cin>>start>>end;
        activity.push_back(make_pair(end,start));
    }

    // sort acc to .first
    sort(activity.begin(),activity.end());
    int count = 0;
    int curEnd =-1;

    for(int i =0 ; i< n ; i++){
        if(activity[i].second > curEnd){
            count++;
            curEnd = activity[i].first;
        }
    }

    cout<<"Number of Activities performed: "<<count<<endl;

    return 0;
}