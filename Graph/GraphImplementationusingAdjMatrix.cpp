#include <iostream>
#include <vector>
using namespace std;

class graph
{
public:
    int AdjMatrix[6][6] ;
    void mat(){
    for(int i = 0 ; i<6 ; i++){
        for(int j = 0 ; j<6 ; j++){
            AdjMatrix[i][j] = 0;
        }
    }
    }


    void addEdge(int u, int v, bool direction)
    {
        AdjMatrix[u][v] = 1;

        if (direction == 0)
        {
            AdjMatrix[v][u] = 1;
        }
    }

    void display(int m)
    {
        int i, j;
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= m; j++)
            {
                cout<<AdjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    
    }
};

int main()
{
    graph g;
    g.mat();
    int n;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    int m;
    cout << "Enter Number of Edges: ";
    cin >> m;

    //  Enter vertices/Nodes in between you want edge

    for (int i = 0; i < m; i++)
    {
        int v, u;

        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.display(n);
    return 0;
}