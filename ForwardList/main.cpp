#include <iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data; // значение элемента
	Element* pNext; // адрес след
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructir:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor\t" << this << endl;
	}

	friend class ForwardList;
};
class ForwardList									//Forward - односвязный, одноправленный
{
	Element* Head; // Голова списка - указатель на 0вой элемент списка
public:
	ForwardList()
	{
		Head = nullptr; // Если список пуст, то его голова указывает на '0';
		cout << "ElConst\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDes:\t" << this << endl;
	}
	// Adding el
	void push_front(int Data)
	{
		//Создаем новый элемент
		Element* New = new Element(Data);
		// Новый элемент должен указывать на начало списка:
		New->pNext = Head;
		// Голову списка "переводим" на новый элемент:
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		// Доходим до конца списка
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		// Добавляем элемент в конец списка
		Temp->pNext = New;
	}
	//Methods:
	ForwardList Copy(ForwardList list,int N)
	{
		ForwardList CopyList;
		for (size_t i = 0; i < N; i++)
		{
			
		}
		return CopyList;
	}
	void print()const
	{
		Element* Temp = Head; // Temp - итератор, это указатель с помощью которого можно получить доступ к элементам и структурам данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // Переход на след эл
		}
	}
	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
	}
	void pop_back()
	{
		Element* Temp = this->Head;
		while (Temp->pNext)
			Temp = Temp->pNext; // переход в конец списка

		Element* Del = Temp->pNext;
		Temp->pNext = Del->pNext;
		//delete Del;
	}
	void insert(int Data, int Index)
	{
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (size_t i = 0; i < Index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
	}
	void erase(int Index)
	{


	}
};

int main()
{
	setlocale(LC_ALL, ""); int N;
	cout << "Введите N= "; cin >> N;
	ForwardList list;
	for (size_t i = 0; i < N; i++)
	{
		list.push_back(rand() % 100);
	}
	list.push_back(999);
	list.print();
	cout << tab;
	list.pop_front();
	list.print();
	
	list.pop_back();
}
