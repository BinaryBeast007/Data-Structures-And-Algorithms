class BinarySearchTree {
	class Node {
		int data;
		Node left, right;

		public Node(int data) {
			this.data = data;
			left = right = null;
		}
	}
	Node root;
	BinarySearchTree() {
		root = null;
	}
	Node insert(Node root, int data) {
		if (root == null) {
			root = new Node(data);
			return root;
		}
		if (data <= root.data) {
			root.left = insert(root.left, data);
		}
		else {
			root.right = insert(root.right, data);
		}

		return root;
	}
	boolean search(Node root, int data) {
		if(root == null) {
			return false;
		}
		if(root.data == data) {
			return true;
		}
		if(data <= root.data) {
			return search(root.left, data);
		}else {
			return search(root.right, data);
		}
	}
	void inorder(Node root) {
		if (root != null) {
			inorder(root.left);
			System.out.println(root.data);
			inorder(root.right);
		}
	}

	public static void main(String[] args) {
		BinarySearchTree tree = new BinarySearchTree();

		tree.root = tree.insert(tree.root, 50);
		tree.root = tree.insert(tree.root, 33);
		tree.root = tree.insert(tree.root, 45);
		tree.root = tree.insert(tree.root, 6);
		tree.root = tree.insert(tree.root, 87);
		tree.root = tree.insert(tree.root, 789);

		tree.inorder(tree.root);

		if(tree.search(tree.root, 6)) {
			System.out.println("element present in the tree");
		}else {
			System.out.println("element not present in the tree");
		}
	}
}