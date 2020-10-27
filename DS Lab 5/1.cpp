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
	bool isEmpty()
	{
		if (head == NULL)
		{
			cout << "Doubly linked list is empty!" << endl;
			return true;
		}
		else
		{
			cout << "Linked list not empty!" << endl;
			return false;
		};
		
	}

	void insert(Node* n)
	{

		if (nodeExists(n->key) != NULL)
		{
			cout << "Cannot insert node with same key!"  << endl;
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

	bool isFull()
	{
		try {
			Node* ptr = new Node;
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "Linked list is Full!" << ba.what();
			cout << endl;
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
	void display() {
		if (head == NULL) {
			cout << "No Nodes in Doubly Linked List";
		}
		else {
			cout << endl << "Doubly Linked List Values : ";
			Node* temp = head;

			while (temp != NULL) {
				cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
				temp = temp -> next;
			}
		}

	}
};
int main()
{
	
	DoublyLinkedList dl;
	
	int selection = 0;

	while (selection != 6)
	{
		cout << "1)Insert Node\n2) Delete Node\n3) isFull\n4) isEmpty\n5) Display\n6) Exit\n\n";
		cin >> selection;
		switch (selection)
		{
		case 1:
			Node n;
			cout << "Enter node data\n";
			cin >> n.data;
			cout << "Enter node key\n";
			cin >> n.key;
			dl.insert(&n);
			break;
		case 2:
			int k;
			cout << "Enter key!" << endl;
			cin >> k;
			dl.deleteNode(k);
			break;
		case 3:
			dl.isFull();
			break;
		case 4:
			dl.isEmpty();
			break;
		case 5:
			dl.display();
			break;
		default:
			break;
		}
	}

}