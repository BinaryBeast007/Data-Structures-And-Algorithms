#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* get_new_Node(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
void inorder(struct Node* root) {
    if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
	inorder(root->left);
	inorder(root->right);
}
void postorder(struct Node* root) {
    if(root == NULL) return;
	inorder(root->left);
	inorder(root->right);
    printf("%d ", root->data);
}
struct Node* insert(struct Node* Node, int data) {
	if (Node == NULL)
		return get_new_Node(data);
	if (data < Node->data)
		Node->left = insert(Node->left, data);
	else if (data > Node->data)
		Node->right = insert(Node->right, data);
	return Node;
}
int search(struct Node* root, int data) {
    if(root == NULL) {
        return -1;
    }
    if(root->data == data) {
        return 1;
    }
    if(data <= root->data) {
        return search(root->left, data);
    }else {
        return search(root->right, data);
    }
}
int find_min(struct Node* root) {
    if(root == NULL) {
        printf("error : tree is empty\n");
        return -1;
    }
    if(root->left == NULL) {
        return root->data;
    }
    return find_min(root->left);
}
int find_max(struct Node* root) {
    if(root == NULL) {
        printf("error : tree is empty\n");
        return -1;
    }
    if(root->right == NULL) {
        return root->data;
    }
    return find_max(root->right);
}
struct Node* find_min_node(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // node with two children:
        // find smallest in the right subtree
        struct Node* temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
    printf("inorder traversal : ");
	inorder(root);
    printf("\n");
    printf("preorder traversal : ");
	preorder(root);
    printf("\n");
    printf("postorder traversal : ");
	postorder(root);
    printf("\n");
    deleteNode(root, 50);
    printf("inorder traversal : ");
	inorder(root);
    printf("\n");
    int data = 70;
    int index = search(root, data);
    if(index != -1) {
        printf("%d found!\n", data);
    }else {
        printf("data not found!\n");
    }
    int min = find_min(root);
    if(min != -1) {
        printf("min data : %d\n", min);
    }
    int max = find_max(root);
    if(max != -1) {
        printf("max data : %d\n", max);
    }

	return 0;
}
