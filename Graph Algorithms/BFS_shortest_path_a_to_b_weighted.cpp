#include<bits/stdc++.h>

using namespace std;


class Graph {
const int maxWeight = 2;
    int V;
    vector<vector<int>> g;
    vector<int> pre;
    vector<bool> visited;
    public:
    Graph(int v){
        V = v;
        pre = vector<int>(V * maxWeight, -1);
        visited = vector<bool>(V * maxWeight, false);
        g = vector<vector<int>> (V * maxWeight, vector<int>());

    }

    void addEdge(int u, int v, int weight){
        if(weight == 2){
            /**
             * Every node will have one intermediate node associated with it
             */
            int middleNode = V + u;
            g[u].push_back(middleNode);
            g[middleNode].push_back(v);
        }
        else{
            g[u].push_back(v);
        }
    }

    void printShortestPath(int dest){
        stack<int> s;
        s.push(dest);
        int parent = pre[dest];
        int count = 0;
        while(parent != -1){
            count++;
            s.push(parent);
            parent = pre[parent];
        }
        cout<<"Length : "<<count<<endl;
       
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(node < V) {
                cout<<node<<" ";
            }
        }
    }

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
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 3, 2);
    g.BFS(0, 3);
    return 0;
}