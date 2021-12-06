#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Complexity
 * TC: O(V * V)
 * SC: O(V * V) where V*V is for graph, another V for Visited and for Dist
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
class Graph {
    
    vector<vector<int>> g;
    int n;
    
    public:
    
    Graph(int num){
        n = num;
        g = vector<vector<int>> (n, vector<int>(n, 0));
    }
    
    void addEdge(int u, int v, int w){
        g[u][v] = w;
        g[v][u] = w;
    }

    int getNodeAtMinDistance(vector<int> &dist, vector<bool> &visited){
        int minDist = INT_MAX;
        int node = -1;
        for(int i = 0; i < n; i++){
            if(visited[i] == false and dist[i] < minDist){
                minDist = dist[i];
                node = i;
            }
        }
        return node;
    }

    void printDijkstraResults(vector<int> &dist){
        for(int i = 0; i < n; i++){
            cout<<i<<" : "<<dist[i]<<endl;
        }
    }

    void doDijkstra(int source) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[source] = 0;

        //Here first u is always the source
        int u = getNodeAtMinDistance(dist, visited);
        while(u != -1) { // This runs for n iterations
            visited[u] = true;
            
            for(int v = 0; v < n; v++){
                int w = g[u][v];
                if(visited[v] == false and
                    w != 0 and 
                    dist[u] != INT_MAX and
                    dist[u] + w < dist[v]
                    ) {
                        dist[v] = dist[u] + w;
                    }
            }
            u = getNodeAtMinDistance(dist, visited);
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