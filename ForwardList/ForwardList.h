#pragma once
#pragma once
//ForwardList
#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

///////////////////////////////////////////////////////////////////////////////////////////
/////////////			CLASS DECLARATION - 				///////////////

template<typename T>class ForwardList;
template<typename T>class Iterator;

template<typename T>class Element
{
	T Data;		
	Element<T>* pNext;	
	static int count;
public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class ForwardList<T>;
	friend class Iterator<T>;
};


template<typename T>class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();

	Iterator& operator++();

	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;
	T& operator*();
};

template<typename T>class ForwardList	
{
	Element<T>* Head;	
	int size;
public:
	Iterator<T> begin();
	Iterator<T> end();
	ForwardList();
	ForwardList(const std::initializer_list<T>& il);
	~ForwardList();

	//					Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);

	//					Erasing Elements
	void pop_front();
	void pop_back();

	//					Methods:
	void print()const;
};

/////////////		CLASS DECLARATION END - 		///////////////
///////////////////////////////////////////////////////////////////////////////////////////