#include<iostream>
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
    Edge edge_list[e];

    cout << "input the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cin >> vertex_list[i];
    }
    cout << "input the edges :\n";
    for(int i=0; i<e; i++) {
        Edge edge;
        cout << "start vertex : ";
        cin >> edge.startVertex;
        cout << "end vertex : ";
        cin >> edge.endVertex;
        edge_list[i] = edge;
    }
    cout << "the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cout << vertex_list[i] << " ";
    }
    cout << "\nthe edges :\n";
    for(int i=0; i<e; i++) {
        cout << edge_list[i].startVertex << " " << edge_list[i].endVertex << '\n';
    }

    return 0;
}
