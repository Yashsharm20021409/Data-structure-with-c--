#include<bits/stdc++.h>
#include<unordered_map>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class graph{
private:
    void topoSortDFS(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adjList){
        visited[node] = true;
        
        for(auto neighbour:adjList[node]){
            if(!visited[neighbour]){
                topoSortDFS(neighbour,visited,s,adjList);
            }
        }
        s.push(node);
    }
public:
    unordered_map<int,list<int>> adjList;
    
    void addEdges(int u,int v){
        adjList[u].push_back(v);
    }
    
    unordered_map<int,bool> visited;
    
    
    //Using DFS 
    
    void topoSort(int node){
        stack<int> s;
        for(int i= 0; i<node ; i++){
            if(!visited[i]){
                topoSortDFS(i,visited,s,adjList);
            }
        }
        
        vector<int> ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        for(int i = 0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
    }
    
    
    
    // using BFS/Kahn's theorem and BFS
    
    void topoSortKahnsTheorem(int node){
        vector<int> indegree[node];
        vector<int> ans;
        
        for(auto i:adjList){
            for(auto j:i.second){
                indegree[j] += 1; 
            }
        }
        
        for(int i = 0 ; i<node;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto neighbour: adjList[neighbour]){
                indegree[neighbour] -=1;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        for(int i = 0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
    }
    
    
    
    // void printGraph(){
    //     for(auto i:adjList){
    //         cout<<i.first << "->";
    //         for(auto j:i.second){
    //             cout<<j<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
};

int main(){
    graph g;
    
    int node;
    cout<<"Enter Number of Nodes: ";
    cin>>node;
    
    int edges;
    cout<<"Enter Number of Edges: ";
    cin>>edges;
    
    for(int i = 0 ; i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v);
    }
    
    g.topoSort(node);
    // g.printGraph();
}
