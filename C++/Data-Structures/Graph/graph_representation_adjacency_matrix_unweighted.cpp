#include<iostream>
#include <cstring>
using namespace std;

struct Edge {
    int startVertex;
    int endVertex;
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
    bool adj[v][v];
    memset(adj, 0, sizeof(adj));
    cout << "input the edges :\n";

    for(int i=0; i<e; i++) {
        Edge edge;
        cout << "start vertex : ";
        cin >> edge.startVertex;
        cout << "end vertex : ";
        cin >> edge.endVertex;
        adj[edge.startVertex][edge.endVertex] = 1;
        adj[edge.endVertex][edge.startVertex] = 1;
    }
    cout << "the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cout << vertex_list[i] << " ";
    }
    cout << "\nadjacent edges :\n";
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(adj[i][j] != 0)
                cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
