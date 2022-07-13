#include<iostream>
using namespace std;



void makeSet(int parent[],int rank[]){
    int n; // number of nodes
    
    for(int i = 1 ; i<=n ; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node,int parent[]){
    if(node = parent[node]){
        return node;
    }
    // path compress
    return parent[node] = findParent(parent[node],parent);
}

void unionmake(int u,int v,int parent[],int rank[]){
    u = findParent(u,parent);
    v = findParent(v,parent);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int m;
    cin>>m;

    int parent[10000];
    int rank[100000];

    makeSet(parent,rank);

    while (m--)
    {
        int u,v;
        cin>>u>>v;
        unionmake(u,v,parent,rank);
    }

    if(findParent(2,parent) != findParent(3,parent)){
        cout<<"differ";
    }
    else{
        cout<<"same";
    }
    return 0;
}