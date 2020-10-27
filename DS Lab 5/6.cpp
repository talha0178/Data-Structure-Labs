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
	int nodeCount;
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
		nodeCount = 0;
	}

	void insert()
	{
		nodeCount++;
		Node* n = new Node;
		cout << "Enter node data\n";
		cin >> n->data;
		n->key = nodeCount;

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
			sorting();
			
		}
	}

	void sorting()
	{
		int temp = 0;
		for (int i = 0; i < nodeCount * nodeCount; i++)
		{
			Node* currentPtr = head;
			Node* nextPtr = head->next;
			while (currentPtr != NULL && nextPtr != NULL)
			{
				if (currentPtr->data > nextPtr->data)
				{
					temp = currentPtr->data;
					currentPtr->data = nextPtr->data;
					nextPtr->data = temp;
				}
				currentPtr = currentPtr->next;
				nextPtr = currentPtr->next;
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
	void deleteAfter(int k)
	{
		Node* temp = nodeExists(k);

		if (temp == NULL)
		{
			cout << "Node not found cannot delete!" << endl;
		}
		else
		{
			Node* toDel = temp->next;
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
	int k;
	
	while (selection != 5)
	{
		cout << "\n1) INSERT SORTED NODE\n2) Delete At\n3) Delete After\n4) Display\n5) Exit\n\n";
		cin >> selection;
		switch (selection)
		{
		case 1:

			dl.insert();
			break;
		case 2:
			
			cout << "Enter index!" << endl;
			cin >> k;
			dl.deleteNode(k);
			break;
		case 3:
			
			cout << "Enter index to delete the next node!" << endl;
			cin >> k;
			dl.deleteAfter(k);
			break;
		case 4:
			dl.display();
			break;
		default:
			break;
		}
		
	}

}