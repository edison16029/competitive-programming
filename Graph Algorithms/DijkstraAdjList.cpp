#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Complexity
 * TC: O(E * log V) or O(V*V * log V)
 * SC: O(E + V), E for graph, V for the Priority Queue
 * Here E is total number of edges.
 * In fully connected graph E = V * (V-1) i.e. E = V*V
 */

/**
 * @brief Expected Output
0 : 0
1 : 4
2 : 12
3 : 19
4 : 21
5 : 11
6 : 9
7 : 8
8 : 14
 */

typedef pair<int, int> pii;
class Graph {
    vector<vector<pii>> g;
    int n;
    
    public:
    
    Graph(int num){
        n = num;
        g = vector<vector<pii>> (n, vector<pii>());
    }
    
    void addEdge(int u, int v, int w){
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    void printDijkstraResults(vector<int> &dist){
        for(int i = 0; i < n; i++){
            cout<<i<<" : "<<dist[i]<<endl;
        }
    }

    void doDijkstra(int source) {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, source));

        while(!pq.empty()) { 
            pii pair = pq.top();
            pq.pop();
            int u = pair.second;
            int distU = pair.first;
            for(auto node_weight : g[u]){
                int v = node_weight.first;
                int w = node_weight.second;
                if(distU != INT_MAX and distU + w < dist[v]) {
                    dist[v] = distU + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        printDijkstraResults(dist);
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(1, 2, 8);
    g.addEdge(7, 6, 1);
    g.addEdge(2, 8, 2);
    g.addEdge(8, 6, 6);
    g.addEdge(7, 8, 7);
    g.addEdge(2, 3, 7);
    g.addEdge(6, 5, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(3, 4, 9);
    g.doDijkstra(0);
    return 0;
}