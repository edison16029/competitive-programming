#include<bits/stdc++.h>

using namespace std;

class Graph {

    int V;
    vector<vector<int>> g;
    vector<int> pre;
    vector<bool> visited;
    public:
    Graph(int v){
        V = v;
        pre = vector<int>(V, -1);
        visited = vector<bool>(V, false);
        g = vector<vector<int>> (V, vector<int>());

    }

    void addEdge(int u, int v){
        g[u].push_back(v);
        // g[v].push_back(u); //UNDIRECTED GRAPH
    }

    void printShortestPath(int dest){
        stack<int> s;
        s.push(dest);
        int parent = pre[dest];
        while(parent != -1){
            s.push(parent);
            parent = pre[parent];
        }
        while(!s.empty()){
            int node = s.top();
            cout<<node<<" ";
            s.pop();
        }
    }
    //TC : O(|V| + |E|) and SC: O(|V|)
    void BFS(int source, int dest) {
        int startNode = source;
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true; 
        while (!q.empty())
        {
            int node = q.front();
            if(node == dest){
                break;
            }
            q.pop();
            visited[node] = true;

            for(auto j : g[node]){
                if(!visited[j]){
                    visited[j] = true;
                    pre[j] = node;
                    q.push(j);
                }
            }

        }

        printShortestPath(dest);
        
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    // g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.BFS(0, 4);
    return 0;
}