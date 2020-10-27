#include <iostream>
using namespace std;

class Node
{
public:
	Node* next;
	Node* prev;
	int key;
	int data;
	Node()
	{
		next = NULL;
		prev = NULL;
		data = 0;
		key = 0;
	}
	Node(int k, int d)
	{
		next = NULL;
		prev = NULL;
		data = d;
		key = k;
	}
};

class DoublyLinkedList
{

private:
	Node* nodeExists(int k)
	{
		Node* temp = head;
		Node* temp2 = NULL;
		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			while (temp != NULL)
			{
				if (temp->key == k)
				{
					temp2 = temp;
				}
				temp = temp->next;
			}

			return temp2;
		}
	}
public:
	Node* head;
	DoublyLinkedList()
	{
		head = NULL;
	}

	void insertAt(Node* n)
	{
		

		if (nodeExists(n->key) != NULL)
		{
			cout << "Cannot insert node with same key!" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
			}
			else
			{
				Node* temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				};
				temp->next = n;
				n->prev = temp;
			}
		}
	}
	void deleteNode(int k)
	{
		Node* toDel = nodeExists(k);

		if (toDel == NULL)
		{
			cout << "Node not found cannot delete!" << endl;
		}
		else
		{
			//Deleting head Node
			if (toDel->key == head->key)
			{
				head = head->next;
				cout << "Head Node deleted!" << endl;
			}
			//Deleting last Node
			else if (toDel->next == NULL)
			{
				toDel->prev->next = NULL;
				toDel->prev = NULL;
			}
			//Deleting in between node
			else
			{
				Node* prev = toDel->prev;
				Node* next = toDel->next;

				prev->next = toDel->next;
				next->prev = toDel->prev;

				toDel->next = NULL;
				toDel->prev = NULL;
			}
		}
	}
	

	void reverse()
		{
			Node* temp = NULL;
			Node* current = head;

			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}

			if (temp != NULL)
				head = temp->prev;

			cout << "Linked List reversed!" << endl;
			display();
		}
	
	void display() {
		cout << endl;
		if (head == NULL) {
			cout << "No Nodes in Doubly Linked List";
		}
		else {
			cout << endl << "Doubly Linked List Values : ";
			Node* temp = head;

			while (temp != NULL) {
				cout << "(" << temp->key << "," << temp->data << ") <--> ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};
int main()
{

	DoublyLinkedList dl;
	Node a(1, 10);
	Node b(2, 20);
	Node c(3, 30);
	dl.insertAt(&a);
	dl.insertAt(&b);
	dl.insertAt(&c);

	int selection = 0;
	int k;
	Node* n = new Node;

	while (selection != 4)
	{
		cout << "\n1) Append\n2) REVERSE LIST \n3) Display\n4) Exit\n\n";
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "New node data" << endl;
			cout << "new node Key" << endl;
			dl.insertAt(n);
			break;
		case 2:

			dl.reverse();
			break;
		case 3:
			dl.display();
			break;
		default:
			break;
		}

	}

}