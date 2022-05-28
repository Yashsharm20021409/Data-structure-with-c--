#include <iostream>
#include <vector>
#include <set>
#include<queue>
using namespace std;

class graph
{
public:
    int V;
    vector<set<int>> adj;
    graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void AdjList(int v, int u)
    {
        adj[v].insert(u);
        adj[v].insert(u);
    }

    void BFS(int start)
    {
        vector<bool> visited;
        visited.resize(V, false); // do this otherwise use use unorder map
        queue<int> q;

        q.push(start);
        visited[start] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    graph g(4);
    // graph g;
    g.AdjList(0, 1);
    g.AdjList(0, 2);
    g.AdjList(2, 0);
    g.AdjList(1, 2);
    g.AdjList(3, 3);
    g.AdjList(2, 3);
    g.BFS(2);
    return 0;
}
