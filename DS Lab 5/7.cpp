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

	void insert(Node * n)
	{
		nodeCount++;
		

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
	DoublyLinkedList* mergeList(DoublyLinkedList* dl1, DoublyLinkedList* dl2)
	{
		Node* temp1 = dl1->head;

		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = dl2->head;
		dl2->head->prev = temp1;
		return dl1;
	};
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
		cout << endl << endl;
	}
};
int main()
{
	
	DoublyLinkedList dl;
	DoublyLinkedList dl2;
	
	Node a(1, 20);
	Node b(2, 30);
	Node c(3, 10);
	Node d(4, 40);
	Node e(5, 15);
	Node f(6, 5);
	Node g(7, 25);


	
	dl.insert(&a);
	dl2.insert(&b);
	dl.insert(&c);
	dl2.insert(&d);
	dl2.insert(&e);
	dl.insert(&f);
	dl.insert(&g);
	cout << "\nFirst Doubly List!" << endl;
	dl.display();
	cout << "\nSecond Doubly List!" << endl;
	dl2.display();
	DoublyLinkedList* merged;
	merged = dl.mergeList(&dl, &dl2);
	cout << "\nMerged Lists" << endl;
	merged->display();
}