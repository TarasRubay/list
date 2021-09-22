#pragma once
#include <iostream>
using namespace std;
template<typename t>
class list {
	template<typename t>
	struct node {
		node* p_next;
		t data;
		node(t _data = t(), node* _p_next = nullptr) {
			this->data = _data;
			this->p_next = _p_next;
		}
};
	int length;
	node<t> *head;
public:
	list();
	~list();
	void push_back(t _data);
	int getleng() { return length; }
	t& operator[](const int _ind);
	void pop_front();
};

template<typename t>
inline list<t>::list()
{
	length = 0;
	head = nullptr;
}

template<typename t>
inline list<t>::~list()
{
}

template<typename t>
inline void list<t>::push_back(t _data)
{
	if (head == nullptr) {
		head = new node<t>(_data);
	}
	else {
		node<t>* tmp = this->head;
		while (tmp->p_next != nullptr)
		{
			tmp = tmp->p_next;
		}
		tmp->p_next = new node<t>(_data);
	}
		length++;
}

template<typename t>
inline t& list<t>::operator[](const int _ind)
{
		node<t>* tmp = this->head;
	if (_ind <= length) {
		int count = 0;
		while (tmp != nullptr) {
			if (count == _ind)return tmp->data;
			tmp = tmp->p_next;
			count++;
		}
	}
	else
	{
		return tmp->data;
	}

}

template<typename t>
inline void list<t>::pop_front()
{
	//node<t> *temp = head;
	//head = head->p_next;
	//delete temp;
	//length--;
}
