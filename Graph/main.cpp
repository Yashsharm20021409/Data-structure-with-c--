#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class graph{
private:
    bool isCyclicBFS(int src){
            unordered_map<int , int> parent;
            queue<int> q;
            
            parent[src] = -1;
            q.push(src);
            visited[src] = 1;
            
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                
                for(auto nig:adjList[frontNode]){
                    if(visited[nig] == true && nig != parent[frontNode]){
                        return true;
                    }
                    else if(!visited[nig]){
                        q.push(nig);
                        visited[nig] = 1;
                        parent[nig] = frontNode;
                    }
                }
            }
            return false;
        }
 public:
        unordered_map<int,list<int>> adjList;
        unordered_map<int ,bool> visited;
        
        void addEdge(int u,int v,int direction){
            adjList[u].push_back(v);
            
            if(direction == 0){
                adjList[v].push_back(u);
            }
        }    
        
        
        
        void BFSCycle(int m,int n){
            for(int i = 0 ; i<n ; i++){
                if(!visited[i]){
                    bool ans = isCyclicBFS(i);
                    
                    if(ans == 1){
                        cout<<"Cycle is Present in this graph";
                        return;
                    }
                }
            }
            cout<<"Cycle is Not Present in this graph";
        }
};

int main(){
    int n ;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    
    int m;
    
    cout<<"Enter Number of Edges: ";
    cin>>m;
    graph g;
    
    for(int i = 0 ; i<m ; i++){
        int u,v;
        
        cin>>u>>v;
        
        g.addEdge(u,v,0);
    }
    
    g.BFSCycle(m,n);
    
}