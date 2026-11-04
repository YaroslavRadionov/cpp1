#include <iostream>
using namespace std;
template<typename T>
class list
{
	struct node
	{
		T value;
		node* next;
		node() :value(T()), next(nullptr) {}
		node(T value, node* next) :value(value), next(next) {}
	};
	node* head;
public:
	list()
	{
		head = nullptr;
	}
	void addtohead(T value)
	{
		node* newnode = new node(value, head);
		head = newnode;
	}
	void printlist()
	{
		node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	~list()
	{
		node* current = nullptr;
		while (current != nullptr)
		{
			current = head;
			head = current->next;
			delete current;
		}
	}
	void addtotail(T value)
	{
		node* newnode = new node(value, nullptr);
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newnode;
		}
	}
	
	int getelement(int pos)
	{
		int  i = 0;
		node* current = head;
		while (current != nullptr)
		{
			if (i == pos - 1)return current->value;
			current = current->next;
			i++;
		}
	}
	void deletefromtail()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void deletefromhead()
	{
		if (head == nullptr)return;
		node* current = head;
		head = head->next;
		delete current;
	}
};
class point
{
	int x;
	int y;
public:
	friend ostream& operator<<(ostream& out, const point& v);
	point()
	{
		x = 0;
		y = 0;
	}
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void show()
	{
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
	}
};
class vector
{
	list <point> points;
public:
	vector()
	{
		points = list<point>();
	}
	void addpointtobeginning(point p)
	{
		points.addtohead(p);
	}
	void addpointtoend(point p)
	{
		points.addtotail(p);
	}
	void deletefrombeginning()
	{
		points.deletefromhead();
	}
	void deletefromend()
	{
		points.deletefromtail();
	}
	void show()
	{
		points.printlist();
	}
};
ostream& operator<<(ostream& out, const point& v)
{
	out << "X: " << v.x << endl;
	out << "Y: " << v.y << endl;
	return out;
}



int main()
{
	list<int> l;
	l.printlist();
	for (int i = 0; i < 10; i++)
	{
		l.addtotail(i);
	}
	l.printlist();
	l.deletefromhead();
	l.printlist();
	point p1(1, 2);
	point p2(3, 4);
	point p3(5, 6);
	vector v;
	v.addpointtobeginning(p1);
	v.addpointtoend(p2);
	v.addpointtobeginning(p3);
	v.show();
	v.deletefrombeginning();
	v.show();
	v.deletefromend();
	v.show();
}