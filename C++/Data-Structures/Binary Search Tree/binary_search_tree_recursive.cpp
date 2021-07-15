#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
class BST {
public:
    BstNode* root;
    BST();
    BstNode* get_new_node(int); 
    BstNode* insert(BstNode*, int);
    bool search(BstNode*, int);
    int find_min(BstNode*);
    int find_max(BstNode*);
    void level_order(BstNode* root);
    void preorder(BstNode*);
    void inorder(BstNode*);
    void postorder(BstNode*);
    BstNode* find_min_node(BstNode*);
    BstNode* Delete(BstNode*, int);
};
BST::BST() {
    root = NULL;
}
BstNode* BST::get_new_node(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* BST::insert(BstNode* root, int data) {
    if(root == NULL) {
        root = get_new_node(data);
    }else if(data <= root->data) {
        root->left = insert(root->left, data);
    }else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool BST::search(BstNode* root, int data) {
    if(root == NULL) {
        return false;
    }
    if(root->data == data) {
        return true;
    }
    if(data <= root->data) {
        return search(root->left, data);
    }else {
        return search(root->right, data);
    }
}
int BST::find_min(BstNode* root) {
    if(root == NULL) {
        cout << "error : tree is empty\n";
        return -1;
    }
    if(root->left == NULL) {
        return root->data;
    }
    return find_min(root->left);
}
int BST::find_max(BstNode* root) {
    if(root == NULL) {
        cout << "error : tree is empty\n";
        return -1;
    }
    if(root->right == NULL) {
        return root->data;
    }
    return find_max(root->right);
}
void BST::level_order(BstNode* root) {
    // time compexity   : O(N)
    // space complexity : worst/average O(N) ..... Best : O(1)
    if(root == NULL) return;
    queue<BstNode*> q;
    q.push(root);
    while(!q.empty()) {
        BstNode* current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
    cout << '\n';
}
/*  
    for preorder, inorder & postorder
    time compexity   : O(N)
    space complexity : O(N) ..... Best/Average : O(logN)
*/
void BST::preorder(BstNode* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void BST::inorder(BstNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void BST::postorder(BstNode* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
BstNode* BST::find_min_node(BstNode* root) {
    while(root->left != NULL) root = root->left;
	return root;
}
BstNode* BST::Delete(BstNode* root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        // data found
        // no child
        if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
        // only one child
        else if(root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        // two child
        else {
            BstNode* temp = find_min_node(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 6);
    bst.root = bst.insert(bst.root, 4);
    bst.root = bst.insert(bst.root, 10);
    bst.root = bst.insert(bst.root, 11);
    bst.root = bst.insert(bst.root, 7);
    bst.root = bst.insert(bst.root, 5);
    bst.root = bst.insert(bst.root, 2);
    bst.root = bst.insert(bst.root, 9);
    bst.root = bst.insert(bst.root, 1);
    bst.root = bst.insert(bst.root, 3);
    if(bst.search(bst.root, 10)) {
        cout << "data found..!\n";
    }else {
        cout << "data not found..!\n";
    }
    cout << "min element : " << bst.find_min(bst.root) << "\n";
    cout << "max element : " << bst.find_max(bst.root) << "\n";

    cout << "level order tree traversal : ";
    bst.level_order(bst.root);
    cout << "preorder tree traversal : ";
    bst.preorder(bst.root);
    cout << "\ninorder tree traversal : ";
    bst.inorder(bst.root);
    cout << "\npostorder tree traversal : ";
    bst.postorder(bst.root);
    bst.root = bst.Delete(bst.root, 4);
    cout << "\ninorder tree traversal : ";
    bst.inorder(bst.root);
    cout << "\n";

    return 0;
}
