#include "list.h"
int main() {
	list<int> lst;
	
	for (int i = 0; i < 10; i++)
	{
	lst.push_back(i);
	}
	lst.print();
	lst.pop_front();
	lst.print();
	lst.push_front(20);
	lst.print();
	lst.insert(500, 4);
	lst.print();
	lst.remove_at(4);
	lst.print();
	lst.pop_back();
	lst.print();
	

	return 0;
}