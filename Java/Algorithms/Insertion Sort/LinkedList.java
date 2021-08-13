public class LinkedList {
	Node head;
	static class Node {
		int data;
		Node next;
		Node(int data) {
			this.data = data;
			next = null;
		}
	}
	LinkedList() {
		head = null;
	}
	public void push_front(int new_data) {
		Node new_node = new Node(new_data);
		new_node.next = head;
		head = new_node;
	}
	public static void insert(LinkedList list, int data) {
		// Create a new node with given data
		Node new_node = new Node(data);

		// If the Linked List is empty,
		// then make the new node as head
		if (list.head == null) {
			list.head = new_node;
		}else {
			// Else traverse till the last node
			// and insert the new_node there
			Node last = list.head;
			while (last.next != null) {
				last = last.next;
			}
			// Insert the new_node at last node
			last.next = new_node;
		}
		// Return the list by head
		// return list;
	}
	public static void printList(LinkedList list) {
		Node currNode = list.head;
		// Traverse through the LinkedList
		while (currNode != null) {
			System.out.print(currNode.data + " ");
			currNode = currNode.next;
		}
		System.out.println();
	}
	public static LinkedList deleteByKey(LinkedList list, int key) {
		Node currNode = list.head, prev = null;
		// CASE 1: If head node itself holds the key to be deleted
		if (currNode != null && currNode.data == key) {
			list.head = currNode.next;
			return list;
		}
		// CASE 2: If the key is somewhere other than at head
		while (currNode != null && currNode.data != key) {
			prev = currNode;
			currNode = currNode.next;
		}
		if (currNode != null) {
			prev.next = currNode.next;
		}
		return list;
	}
	public static LinkedList deleteAtPosition(LinkedList list, int index) {
		Node currNode = list.head, prev = null;
		// CASE 1: head node itself is to be deleted
		if (index == 0 && currNode != null) {
			list.head = currNode.next;
			return list;
		}
		// CASE 2: validating index
		int counter = 0;
		while (currNode != null) {
			if (counter == index) {
				prev.next = currNode.next;
				break;
			}else {
				prev = currNode;
				currNode = currNode.next;
				counter++;
			}
		}
		if (currNode == null) {
			System.out.println("invalid index");
		}
		return list;
	}
	public static LinkedList deleteAtBeginning(LinkedList list) {
		Node currNode = list.head;
		if(currNode == null) {
			System.out.println("error : can not delete from empty list");
			return list;
		}
		list.head = currNode.next;
		return list;
	}
	public static LinkedList deleteAtTail(LinkedList list) {
		Node currNode = list.head;
		if (currNode == null)
            return list;
        if (currNode.next == null) {
			list.head = null;
            return list;
        }
        // Find the second last node
        Node second_last = currNode;
        while (second_last.next.next != null)
            second_last = second_last.next;
        // Change next of second last
        second_last.next = null;
        return list;
	}
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		insert(list, 10);
		insert(list, 20);
		insert(list, 30);
		insert(list, 40);
		insert(list, 50);
		printList(list);
		list = deleteByKey(list, 10);
		printList(list);
		list = deleteAtBeginning(list);
		printList(list);
		list = deleteAtPosition(list, 0);
		printList(list);
		list = deleteAtTail(list);
		printList(list);
	}
}
