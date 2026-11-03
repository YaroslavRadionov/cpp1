#include <iostream>
using namespace std;
class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
	}
	int operator [] (int index)
	{
		if (index < 0 || index >= size)
		{
			return -1;
		}
		return arr[index];
	}
	int operator () (int num)
	{
		for (int i = 0; i <= size; i++)
		{
			arr[i] += num;
		}
		return *arr;
	}
	void Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int set(int arr1[])
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr1[i];
		}
		return *arr;
	}
};
class plain
{
	char model[20];
	char type[20];
	int passagers;
	int maxpassagers;
public:
	plain()
	{
		strcpy_s(model, " ");
		strcpy_s(type, " ");
		passagers = 0;
		maxpassagers = 0;
	}
	void set(char* model, char* type, int passagers, int maxpassagers)
	{
		strcpy_s(this->model, model);
		strcpy_s(this->type, type);
		this->passagers = passagers;
		this->maxpassagers = maxpassagers;
	}
	void show()
	{
		cout << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Passagers: " << passagers << endl;
		cout << "Max passagers: " << maxpassagers << endl;
	}
	bool operator == (plain& other)
	{
		if (this->type == other.type)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	plain operator ++()
	{
		++this->passagers;
		return *this;
	}
	plain operator --()
	{
		--this->passagers;
		return *this;
	}
	bool operator > (plain& other)
	{
		if (this->maxpassagers > other.maxpassagers)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	plain operator ()(int num)
	{
		if (this->passagers + num > this->maxpassagers)
		{
			cout << "Error: too many passagers" << endl;
			return *this;
		}
		else
		{
			this->passagers += num;
			return *this;
		}
		return *this;
	}
	plain set()
	{
		cout << "Enter model: ";cin >> model;
		cout << "\nEnter type: ";cin >> type;
		cout << "\nEnter count of passagers: ";cin >> passagers;
		cout << "\nEnter max count of passagers: ";cin >> maxpassagers;
		return *this;
	}
};
int main()
{
	//1
	//int const size = 5;
	//Array arr(size);
	//int arr1[size] = { 1,2,3,4,5 };
	//arr.set(arr1);
	//arr.Show();
	//arr(10);
	//arr.Show();
	//cout << arr[2] << endl;

	//2
	plain plain1;
	plain plain2;
	int num;
	cout << "Enter data for first plain: " << endl;
	plain1.set();
	cout << "Enter data for second plain: " << endl;
	plain2.set();
	cout << "First plain: " << endl;
	plain1.show();
	cout << "Second plain: " << endl;
	plain2.show();
	if (plain1 == plain2)
	{
		cout << "Plains are equal" << endl;
	}
	else
	{
		cout << "Plains are not equal" << endl;
	}
	++plain1;
	plain1.show();
	--plain2;
	plain2.show();
	if (plain1 > plain2)
	{
		cout << "First plain has more max passagers";
	}
	cout << "Enter count of passagers to add to first plain: ";cin >> num;
	plain1(num);
	cout << "Enter count of passagers to add to second plain: ";cin >> num;
	plain2(num);
	plain1.show();
	plain2.show();
}