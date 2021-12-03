#include<bits/stdc++.h>

using namespace std;

const int maxWeight = 2;
class Graph {

    int V;
    vector<vector<int>> g;
    vector<bool> visited;
    public:
    Graph(int v){
        V = v;
        visited = vector<bool>(V * maxWeight, false);
        g = vector<vector<int>> (V * maxWeight, vector<int>());

    }

    void addEdge(int u, int v){
        g[u].push_back(v);
        // g[v].push_back(u); //UNDIRECTED GRAPH
    }

    void BFS() {
        int startNode = 0;
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true; 
        while (!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            visited[node] = true;

            for(auto j : g[node]){
                if(!visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }

        }
        
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS();
    return 0;
}