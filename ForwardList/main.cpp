#include <iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data; // �������� ��������
	Element* pNext; // ����� ����
	static int count;
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
int Element::count = 0;//�������������� ����������� ����������, ����������� � ������
class ForwardList									//Forward - �����������, ��������������
{
	Element* Head; // ������ ������ - ��������� �� 0��� ������� ������
	int size;
public:
	ForwardList()
	{
		size = 0;
		//Element::count++;
		Head = nullptr; // ���� ������ ����, �� ��� ������ ��������� �� '0';
		cout << "ElConst\t" << this << endl;
	}
	~ForwardList()
	{
		//Element::count--;
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
		size++;
		//Head = new Element(Data, Head);
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
		size++;
	}
	//Methods:
	ForwardList Copy(ForwardList list,int N)
	{
	
	}
	void print()const
	{
		Element* Temp = Head; // Temp - ��������, ��� ��������� � ������� �������� ����� �������� ������ � ��������� � ���������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // ������� �� ���� ��
		}
		//cout << "���-�� �� ������ = " << Head->count << endl;
		cout << "���-�� �� ������ = " << size << endl;
	}
	void pop_front()
	{
		Element* Buf = Head;
		Head = Head->pNext;
		delete Buf;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext; // ������� � ����� ������
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void insert( int Index, int Data)
	{
		if (Index == 0)return push_front(Data);
		if (Index > size)return;
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (size_t i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
		
	}
	void erase(int Index)
	{
		//int counter=0;
		Element* pTemp = Head;
		Element* Temp = Head;
		for (size_t i = 0; i < Index; i++)
		{
			if (Index - 1 == 0)
			{
				Head = pTemp->pNext;
				delete pTemp;
				size--;
				break;
			}
			else
			{

				Temp->pNext = pTemp->pNext;
				delete pTemp;
				size--;
				break;
			}
			if (i==Index-1)
			{
				Temp = pTemp;
				pTemp = pTemp->pNext;
				//counter++;
			}
		}
		/*while (pTemp != nullptr)
		{
			if (counter == Index - 1)
			{
				if (Index - 1 == 0)
				{
					Head = pTemp->pNext;
					delete pTemp;
					size--;
					break;
				}
				else
				{
					Temp->pNext = pTemp->pNext;
					delete pTemp;
					size--;
					break;
				}
			}
			else
			{
				Temp = pTemp;
				pTemp = pTemp->pNext;
				counter++;
			}
		}*/
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
	list.print();
	int index, value;
	cout << "������� ������ = "; cin >> index;
	cout << "\n������� �������� = "; cin >> value;
	list.insert(index, value);
	list.print();
	//ForwardList list2;
	//list2.push_back(13);
	//list2.push_back(12);
	//list2.push_back(11);
	//list2.push_back(1);
	//list2.print();
	cout << "������� ������ ���������� �������� = "; cin >> index;
	list.erase(index);
	list.print();
}
