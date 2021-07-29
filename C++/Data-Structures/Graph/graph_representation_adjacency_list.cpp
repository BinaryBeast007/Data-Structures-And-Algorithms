#include<iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};
class List {
    ListNode* head;
public:
    // list operations
    List();
    ListNode* get_new_node(const int&);
    void push_front(const int&);
    void print_list();
};
List::List() {
    head = NULL;
}
ListNode* List::get_new_node(const int& data) {
    // create a new node
    ListNode* newNode = new ListNode();
    // assign data to new node
    newNode->data = data;
    // set next as NULL
    newNode->next = NULL;
    // return the new node
    return newNode;
}
void List::push_front(const int &data) {
    // Time complexity of push_front is O(1)
    ListNode* newNode = get_new_node(data);
    newNode->next = head;
    head = newNode;
}
void List::print_list() {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
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
    List adj[v];
    cout << "input the edges :\n";
    for(int i=0; i<e; i++) {
        Edge edge;
        cout << "start vertex : ";
        cin >> edge.startVertex;
        cout << "end vertex : ";
        cin >> edge.endVertex;
        adj[edge.startVertex].push_front(edge.endVertex);
        adj[edge.endVertex].push_front(edge.startVertex);
    }
    cout << "the nodes/vertices :\n";
    for(int i=0; i<v; i++) {
        cout << vertex_list[i] << " ";
    }
    cout << "\nadjacent edges :\n";
    for(int i=0; i<v; i++) {
        adj[i].print_list();
    }

    return 0;
}
