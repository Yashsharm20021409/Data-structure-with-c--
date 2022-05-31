#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class graph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
      void addEdges(int u,int v,int weight){
        pair<int,int>p = make_pair(v,weight);
        adjList[u].push_back(p);
      }

      void printAdjList(){
        for(auto i:adjList){
          cout<<i.first<<"->";
          for(auto j:i.second){
            cout<<"(" <<j.first<< "," <<j.second<< ") ,";
          }
          cout<<endl;
        }
      }
      void dfsTopo(int src,unordered_map<int ,bool> &visited,
                        stack<int> &s){

        visited[src] = true;

        for(auto neighbour:adjList[src]){
          // here neighbour is pair and we want first(v) element
          if(!visited[neighbour.first]){
            dfsTopo(neighbour.first,visited,s);
          }
        }
        s.push(src);
      }

      void getShortestPath(int src,
                    vector<int>&distance,stack<int> &s){
        distance[src] = 0;

        while(!s.empty()){
          int top = s.top();
          s.pop();

          if(distance[top] != INT_MAX){
            for(auto i:adjList[top]){
              // i.second for adj list
              // always i.first for distance
              if(distance[top]+i.second < distance[i.first]){
                distance[i.first] = distance[top]+ i.second;
              }
            }
          }
        }
      }
};

int main(){
  graph g;

  g.addEdges(0,1,5);
  g.addEdges(0,2,3);
  g.addEdges(1,2,2);
  g.addEdges(1,3,6);
  g.addEdges(2,3,7);
  g.addEdges(2,4,4);
  g.addEdges(2,5,2);
  g.addEdges(3,4,-1);
  g.addEdges(4,5,-2);

  // g.printAdjList();

  // toposort function
  unordered_map<int ,bool>visited;
  stack<int> s;
  int n = 6;
  for(int i = 0 ; i< n ;i++){
    if(!visited[i]){
      g.dfsTopo(i,visited,s);
    }
  }

  // path finding function
  int src = 1;
  vector<int> distance(n);

  for(int i = 0 ; i<n ; i++){
    distance[i] = INT_MAX; //initialize vector with infinity
  }

  g.getShortestPath(src,distance,s);

  cout<<"Shortest Path is: "<<endl;

  for(int i = 0 ; i<distance.size() ; i++){
    cout<<distance[i]<<" ";
  }
  cout<<endl;

  return 0;
}