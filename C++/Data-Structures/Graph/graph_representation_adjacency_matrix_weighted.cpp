#include<iostream>
#include <cstring>
#include <climits>
using namespace std;

struct Edge {
    int startVertex;
    int endVertex;
    int weight;
};

int main() {
    int v, e;
    cout << "number of nodes/vertices : ";
    cin >> v;
    cout << "number of edges : ";
    cin >> e;

    int vertex_list[v];
    cout << "input the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cin >> vertex_list[i];
    }
    int adj[v][v];
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            adj[i][j] = INT_MAX;
        }
    }
    cout << "input the edges :\n";
    for(int i=0; i<e; i++) {
        Edge edge;
        cout << "start vertex : ";
        cin >> edge.startVertex;
        cout << "end vertex : ";
        cin >> edge.endVertex;
        cout << "weight : ";
        cin >> edge.weight;
        adj[edge.startVertex][edge.endVertex] = edge.weight;
        adj[edge.endVertex][edge.startVertex] = edge.weight;
    }

    cout << "the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cout << vertex_list[i] << " ";
    }
    cout << "\nadjacent edges :\n";
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(adj[i][j] != INT_MAX) {
                cout << "[adj " << j << " wt " << adj[i][j] << "] ";
            }
        }
        cout << "\n";
    }

    return 0;
}
