#include<iostream>
using namespace std;
class doublelist
{
public:
	doublelist() { createlist(); }
	~doublelist()
	{
		clear();
	}
	void createlist();
	void tailinsert(const int & d);
	void insertpos(const int & d, const int &dl);
	void erase(const int & d);
	void updata(const int & d, const int &dl);
	void reverse(int & d);
	void print();
private:
	struct node
	{
		int data;
		node * next;//指向结构体的指针
		node * prev;
		node(const int & d) :data(d), next(NULL), prev(NULL) {}//初始化指针
	};
	node * head;
	node * curr;
	void clear()
	{
		node * p = head;
		while (p)
		{
			node * q = p->next;
			delete p;
			p = q;
		}
		cout << "The memory was already clear!";
	}
	node * find(const int &d)
	{
		node * p = head;
		for (; p; p = p->next)
		{
			if (p->next->data == d)//找到目标值的前一个位置
				break;
		}
		//cout << p->data << endl;
		return p;
	}
};

void doublelist::createlist()
{
	head = new node(0);
	curr = head;
}

void doublelist::tailinsert(const int & d)
{
	node * p = new node(d);
	p->next = NULL;
	p->next = head;
	head->prev = p;
	curr->next = p;
	p->prev = curr;
	curr = p;
}

void doublelist::print()
{
	node * p;
	for (p = head->next; p != head; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void doublelist::insertpos(const int & d, const int &dl)
{
	node * p = find(d);
	node * q = new node(dl);
	q->next = p->next;
	p->next->prev = q;
	p->next = q;
	q->prev = p;

}

void doublelist::erase(const int & d)
{
	node * p = find(d);
	node * q = p->next;
	p->next = p->next->next;
	q->next->prev = q->prev;
	delete q;
}

void doublelist::updata(const int & d, const int & dl)
{
	node * p = find(d);
	p->next->data = dl;
}

void doublelist::reverse(int & d)
{
	node * temp = NULL;
	curr = head;
	while (d--)//每次循环看成123的反转
	{
		temp = head->prev;
		head->prev = temp->prev;
		temp->prev->next = head;
		temp->next = curr->next;
		curr->next->prev = temp;
		curr->next = temp;
		temp->prev = curr;
		curr = curr->next;
	}
}

int main()
{
	doublelist list;
	int i, j, k, n;
	cout << "How many nodes you want to build?" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "What is the " << i + 1 << " data?" << endl;
		cin >> j;
		list.tailinsert(j);
	}
	list.print();
	cout << "Where are you want to insert?" << endl;
	cin >> k;
	cout << "what is you want to insert?" << endl;
	cin >> j;
	if (k == 0 && j == 0)
	{
		goto main2;
	}
	else
	{
		list.insertpos(k, j);
		list.print();
	}
main2:
	cout << "what are you want to delete?" << endl;
	cin >> i;
	if (i == 0)
	{
		goto main3;
		list.print();
	}
	else
	{
		list.erase(i);
		list.print();
	}
main3:
	cout << "where are youn want to updata?" << endl;
	cin >> i;
	cout << "what are you want to updata?" << endl;
	cin >> k;
	if (i == 0 && k == 0)
	{
		goto main4;
	}
	else
	{
		list.updata(i, k);
		list.print();
	}
main4:
	cout << "are you want to reverse?(yes: 1,no: 0)" << endl;
	cin >> i;
	if (i == 0)
	{
		list.print();
	}
	else
	{
		list.reverse(n);
		list.print();
	}
	system("pause");
	return 0;
}