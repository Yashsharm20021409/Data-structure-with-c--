#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjList){
    unordered_map<int,int> parent;
    queue<int> q;
    parent[src] = -1;
    visited[src] = 1;
    q.push(src);
    
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto neighbor:adjList[frontNode]){
            if(visited[neighbor] == true && neighbor != parent[frontNode]){
                return true;
            }
            else if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = 1;
                parent[neighbor] = frontNode;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjList
    unordered_map<int,list<int>> adjList;
   
    for(int i = 0 ; i<m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    //To handle disconnected graph
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i,visited,adjList);
            
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
