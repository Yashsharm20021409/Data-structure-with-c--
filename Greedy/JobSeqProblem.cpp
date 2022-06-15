#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
int main(){
    vector <pair<int,int>> job;
    int n;
    int profit;
    int deadLine;

    cout<<"Number of Jobs: ";
    cin>>n;

    // Enter profit and deadline tinto the vector
    for(int i =0 ; i< n ; i++){
        cin>>profit>>deadLine;
        job.push_back(make_pair(profit,deadLine));
    }

    sort(job.begin(),job.end(),compare);

    int maxEndTime =0;

    for(int i = 0 ; i<n ; i++){
        if(job[i].second > maxEndTime){
            maxEndTime = job[i].second;
        }
    }

    int fill[maxEndTime];
    int count =0;
    int maxProfit =0;

    for(int i = 0 ; i< n ; i++){
        fill[i] = -1;
    }

    for(int i = 0 ; i< n ; i++){
        int j = job[i].second-1;

        while(j>=0 && fill[j] != -1){
            j--;
        }

        if(j>=0 && fill[j] == -1){
            fill[j] = i;
            count++;
            maxProfit += job[i].first;
        }
    }

    cout<<"Count: "<<count<<" Profit: "<<maxProfit<<endl;
}
