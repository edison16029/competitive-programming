#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
class Graph {
    int V;
    vector<vector<pii>> g;

    public:
    Graph(int numOfVertices) {
        V =  numOfVertices;
        g = vector<vector<pii>>(V, vector<pii>());
    }

    void addEdge(int u, int v, int w) {
        g[u].push_back(make_pair(v,w));
        // g[v].push_back(make_pair(u,w)); For undirected
    }

    void printSingleSourceShortestPathResult(vector<int> &dist) {
        //Add code
        for(int i = 0; i < V; i++) {
            cout<<i<<" : "<<dist[i]<<endl;
        }
    }

    void BellmanFord(int source) {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;
        for(int i = 0; i < V-1; i++) {

            for(int i = 0; i < V; i++) {
                for(pii &nextNode : g[i]) {
                    int u = i;
                    int v = nextNode.first;
                    int w = nextNode.second;
                    if(dist[u] != INT_MAX and dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    } 
                }
            }
        }

        //If we do the same operation one more time, and some node's distance can still be relaxed
        //Then the graph contains negative cycle

        for(int i = 0; i < V; i++) {
            for(pii &nextNode : g[i]) {
                int u = i;
                int v = nextNode.first;
                int w = nextNode.second;
                if(dist[u] != INT_MAX and dist[u] + w < dist[v]) {
                    cout<<"Graph Contains Negative Cycle\n";
                    return;
                }
            }
        }
        printSingleSourceShortestPathResult(dist);
    }

};

int main() {
    /**
     * @brief Directed Graph without cycle
     * 
     * Expected output
     *  0 : 0
        1 : -1
        2 : 2
        3 : -2
        4 : 1
     * 
     */
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3); //Weight = -4 for -ve cycle, -3 for normal case

    g.BellmanFord(0);
    return 0;
}