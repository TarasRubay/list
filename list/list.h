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
	void clear();
	void push_front(t _data);
	void insert(t _data,int ind);
	void print();
	void remove_at(int index);
	void pop_back();
};
#include "list.h"
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
	node<t> *tmp = head;
	head = head->p_next;
	delete tmp;
	length--;
}

template<typename t>
inline void list<t>::clear()
{
	while (length)
	{
		pop_front();
	}
}

template<typename t>
inline void list<t>::push_front(t _data)
{
	head = new node<t>(_data,head);
	length++;
}

template<typename t>
inline void list<t>::insert(t _data, int ind)
{
	if (ind == 0) {
		push_front(_data);
	}
	else {
		node<t>* tmp = this->head;
		for (int i = 0; i < ind - 1; ++i) {
			tmp = tmp->p_next;
		}
		node<t> *n_node = new node<t>(_data, tmp->p_next);
		tmp->p_next = n_node;
	}
	length++;
}

template<typename t>
inline void list<t>::print()
{
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << this->operator[](i) << endl;
	}
	cout << endl;
	cout << "length - " << length << endl;
}

template<typename t>
inline void list<t>::remove_at(int index)
{
	node<t> *tmp = this->head;
	for (int i = 0; i < index-1; i++)
	{
		tmp = tmp->p_next;
	}
	node<t>* tmp2 = tmp->p_next;
	tmp->p_next = tmp2->p_next;
	delete tmp2;
	length--;
}

template<typename t>
inline void list<t>::pop_back()
{
	node<t> *tmp = this->head;
	for (int i = 0; i < length-1; i++)
	{
		tmp = tmp->p_next;
	}
	node<t> *tmp2 = tmp->p_next;
	tmp->p_next = nullptr;
	delete tmp2;
	length--;
}
