#include<iostream>
using namespace std;
class List
{
public:
	List() { createlist(); }
	~List()
	{
		clear();
	}
	void createlist();
	void headinsert(const int & d);
	void tailinsert(const int & d);
	void insertpos(const int & d, const int &dl);
	void erase(const int & d);
	void updata(const int & d, const int &dl);
	void reverse();
	void print();
private:
	struct Node
	{
		int data;
		Node * next;
		Node(const int &d) :data(d), next(NULL) {}
	};
	Node * head;//定义头结点
	Node * curr = head;
	void clear()
	{
		Node * p = head;
		while (p)
		{
			Node * q = p->next;
			delete p;
			p=q;
		}//从前往后删除
		cout << "Clear the list." << endl;
	}

	Node * find(const int & d)
	{
		Node * p = head;
		for (; p; p = p->next)
		{
			if (p->next->data == d)
				break;
		}
		return p;
	}
};
void List::createlist()
{
	head = new Node(0);
	curr = head;
}

void List::headinsert(const int & d)//头插法
{
	Node * p = new Node(d);
	p->next = head->next;
	head->next = p;
}
void List::tailinsert(const int & d)
{
	Node * p = new Node(d);
	p->next = NULL;
    curr->next=p;
	curr = p;
}

void List::print()
{
	for (Node * p = head->next; p; p=p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void List::insertpos(const int & d, const int & dl)
{
	Node * p = find(d);
	Node * q = new Node(dl);
	q->next = p->next;
	p->next = q;
}

void List::erase(const int & d)
{
	Node * p = find(d);
	Node * q = p->next;
	p->next = p->next->next;
	delete q;
}

void List::updata(const int &d, const int & dl)
{
	Node * p = find(d);
	p->next->data = dl;
}

void List::reverse()//反转链表
{
	Node * p = head->next;
	Node * q = head->next->next;
	Node * m = head->next->next->next;
	p->next = NULL;
	while (m)
	{
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	q->next = p;
	head->next = q;
}
int main()
{
		List list;
		int i, j, k, n;
		cout << "How many nodes you want to build?" << endl;
		cin >> n;
		cout << "Which way is you want to choose?(headinsert:1,tailinsert : 2)" << endl;
		cin >> k;
		for (i = 0; i < n; i++)
		{
			cout << "What is the " << i + 1 << " data?" << endl;
			cin >> j;
			if (k == 1)
			{
				list.headinsert(j);
			}
			else
				list.tailinsert(j);
		}
		list.print();
		cout << "Where are you want to insert?" << endl;
		cin >> k;
		cout << "what is you want to insert?" << endl;
		cin >> n;
		if (k == 0 && n == 0)
		{
			goto main2;
		}
		else
		{
			list.insertpos(k, n);
			list.print();
		}
	main2:
		cout << "what are you want to delete?" << endl;
		cin >> n;
		if (n == 0)
		{
			goto main3;
			list.print();
		}
		else
		{
			list.erase(n);
			list.print();
		}
	main3:
		cout << "where are youn want to updata?" << endl;
		cin >> n;
		cout << "what are you want to updata?" << endl;
		cin >> k;
		if (n == 0 && k == 0)
		{
			goto main4;
		}
		else
		{
			list.updata(n, k);
			list.print();
		}
	main4:
		cout << "are you want to reverse?(yes: 1,no: 0)" << endl;
		cin >> n;
		if (n == 0)
        {
			list.print();
		}
		else
		{
			list.reverse();
			list.print();
		}
		//break;
	system("pause");
	return 0;
}
