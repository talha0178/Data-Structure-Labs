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

	void insertAt()
	{
		Node* n = new Node;
		cout << "Enter node data\n";
		cin >> n->data;
		cout << "Enter node index\n";
		cin >> n->key;

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
	int primeProduct()
	{
		int product = 1;
		Node* temp = head;
		while (temp != NULL)
		{
			if (ifPrime(temp->data))
			{
				product *= temp->data;
			}
			temp = temp->next;
		}
		cout << "The product of prime nodes of Doubly linked list is: " << product << endl;
		return product;
	}
	bool ifPrime(int num)
	{
		bool chk = true;
		if (num == 0 || num == 1) {
			return  chk;
		}
		else {
			for (int i = 2; i <= num / 2; ++i) {
				if (num % i == 0) {
					chk = false;
					break;
				}
			}
		}
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

	int selection = 0;
	int k;
	Node* n = new Node;

	while (selection != 4)
	{
		cout << "\n1) Append\n2) PRIME PRODUCT \n3) Display\n4) Exit\n\n";
		cin >> selection;
		switch (selection)
		{
		case 1:

			dl.insertAt();
			break;
		case 2:

			dl.primeProduct();
			break;
		case 3:
			dl.display();
			break;
		default:
			break;
		}

	}

}