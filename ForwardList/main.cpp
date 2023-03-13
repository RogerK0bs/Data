#include <iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data; // �������� ��������
	Element* pNext; // ����� ����
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
class ForwardList									//Forward - �����������, ��������������
{
	Element* Head; // ������ ������ - ��������� �� 0��� ������� ������
public:
	ForwardList()
	{
		Head = nullptr; // ���� ������ ����, �� ��� ������ ��������� �� '0';
		cout << "ElConst\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDes:\t" << this << endl;
	}
	// Adding el
	void push_front(int Data)
	{
		//������� ����� �������
		Element* New = new Element(Data);
		// ����� ������� ������ ��������� �� ������ ������:
		New->pNext = Head;
		// ������ ������ "���������" �� ����� �������:
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		// ������� �� ����� ������
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		// ��������� ������� � ����� ������
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
		Element* Temp = Head; // Temp - ��������, ��� ��������� � ������� �������� ����� �������� ������ � ��������� � ���������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // ������� �� ���� ��
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
			Temp = Temp->pNext; // ������� � ����� ������

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
	cout << "������� N= "; cin >> N;
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
