#include<iostream>
using namespace std;

struct Node
{
	int   data;
	Node* lptr;
	Node* rptr;
};
class queue
{
	Node*  cur;
	Node*   front;
	Node*   rear;
public:
	queue() :cur(NULL), front(NULL), rear(NULL) {}
	void pushFront();
	void pushRear();
	int  popFront();
	int  popRear();
	void push_From_BothEnds();
	int pop_From_BothEnds(int& p1, int& p2);
	void display();

};
void queue::push_From_BothEnds()
{
	Node* cur1 = new Node;
	cur1->lptr = cur1->rptr = NULL;
	Node* cur2 = new Node;
	cur2->lptr = cur2->rptr = NULL;

	cout << "Enter Data: ";
	cin >> cur1->data;
	cur2->data = cur1->data;

	if (front == NULL)
		front = rear = cur1;
	else
	{
		cur1->rptr = front;
		front->lptr = cur1;
		front = cur1;

		rear->rptr = cur2;
		cur2->lptr = rear;
		rear = cur2;

	}

}int queue::pop_From_BothEnds(int& p1, int & p2)
{


	if (front == NULL)
		cout << "Queue is Empty\n\n";
	else
	{

		Node* temp;
		p1 = front->data;
		if (front == rear)
		{
			front = rear = NULL;
			delete cur;
			return -1;
		}
		else
		{
			temp = front;
			front = front->rptr;
			front->lptr = NULL;
			delete temp;

			p2 = rear->data;
			temp = rear;
			rear = rear->lptr;
			rear->rptr = NULL;
			delete temp;
		}

	}

}
void queue::display()
{
	if (front == NULL)
		cout << "Queue Is Empty \n\n";
	else
	{
		int ch;
		cout << "------(MENU)-----\n";
		cout << "1) From Front End\n";
		cout << "2) From Rear End\n\n";
		cout << "Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cur = front;
			cout << "Queue Elements: ";
			while (cur)
			{
				cout << cur->data << " ";
				cur = cur->rptr;
			}
			cout << endl;
			break;

		case 2:
			cur = rear;
			cout << "Queue Elements: ";
			while (cur)
			{
				cout << cur->data << " ";
				cur = cur->lptr;
			}
			cout << endl;
			break;
		}


	}

}
void queue::pushFront()
{
	Node* cur = new Node;
	cur->lptr = cur->rptr = NULL;
	cout << "Enter Data: ";
	cin >> cur->data;


	if (front == NULL)
		front = rear = cur;
	else
	{
		cur->rptr = front;
		front->lptr = cur;
		front = cur;
	}

}
void queue::pushRear()
{
	Node* cur = new Node;
	cur->lptr = cur->rptr = NULL;
	cout << "Enter Data: ";
	cin >> cur->data;


	if (front == NULL)
		front = rear = cur;
	else
	{
		rear->rptr = cur;
		cur->lptr = rear;
		rear = cur;
	}

}
int queue::popFront()
{
	if (front == NULL)
		cout << "Queue Is Empty.... \n\n";
	else
	{
		int data;
		Node* temp;
		data = front->data;
		if (front == rear)
		{
			front = rear = NULL;
			delete cur;
		}

		else
		{
			temp = front;
			front = front->rptr;
			front->lptr = NULL;
			delete temp;
		}
		return data;
	}
	return -1;
}
int queue::popRear()
{
	if (front == NULL)
		cout << "Queue Is Empty.... \n\n";
	else
	{
		int data;
		Node* temp;
		data = rear->data;
		if (front == rear)
		{
			front = rear = NULL;
			delete cur;
		}

		else
		{
			temp = rear;
			rear = rear->lptr;
			rear->rptr = NULL;
			delete temp;
		}
		return data;
	}
	return -1;
}
int main()
{
	int ch;
	int pop;
	int p1, p2;
	queue obj;

	while (true)
	{
		system("CLS");
		cout << "----------(MAIN MENU)----------\n";
		cout << "1) Push From Front \n";
		cout << "2) Push From Rear \n";
		cout << "3) Pop From Front \n";
		cout << "4) Pop From Rear \n";
		cout << "5) Push From Boths Ends \n";
		cout << "6) Pop From both Ends \n";
		cout << "7) Display \n";
		cout << "8) Exit \n\n";
		cout << "Enetr Choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			obj.pushFront();
			system("Pause");
			break;
		case 2:
			obj.pushRear();
			system("Pause");
			break;
		case 3:

			pop = obj.popFront();
			if (pop != (-1))
				cout << "Pop Element1: " << pop << endl;

			system("Pause");
			break;
		case 4:

			pop = obj.popRear();
			if (pop != -1)
				cout << "Pop Element: " << pop << endl;
			system("Pause");

			break;
		case 5:
			obj.push_From_BothEnds();
			system("pause");
			break;
		case 6:
			pop = obj.pop_From_BothEnds(p1, p2);
			if (pop == -1)
				cout << p1 << endl;
			else
				cout << p1 << " " << p2 << endl;

			system("pause");
			break;
		case 7:
			obj.display();
			system("Pause");
			break;
		case 8:
			exit(-1);


		}
	}
}
