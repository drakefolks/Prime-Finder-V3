#include<iostream>
#include<cmath>;

using namespace std;

struct listnode
{
	int value;
	listnode* next;
	listnode(double value1, listnode* next1 = nullptr)
	{
		value = value1;
		next = next1;
	}
};

listnode* first;

class linked_list
{
public:
	void add(int num);
	void print();
	friend listnode;
};

void linked_list::add(int num)
{
	if (first == nullptr)
	{
		first = new listnode(num);
	}
	else
	{
		listnode* temp = first;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = new listnode(num);
	}
}

void linked_list::print()
{
	listnode* temp = first;

	while (temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main()
{
	linked_list list;
	int num = 2000000;
	bool prime = true;

	list.add(2);
	list.add(3);
	list.add(5);
	list.add(7);

	cout << "\nFinding primes...\n";
	for (int i = 10; i < num; i++)
	{
		listnode* temp = first;
		while (temp != nullptr)
		{
			if (i % temp->value == 0)
			{
				prime = false;
				break;
			}
			else
			{
				prime = true;
			}
			temp = temp->next;
		}

		if (prime)
		{
			list.add(i);
			cout << i << endl;
		}
	}

	cout << "\n\nPrime:\n";
}