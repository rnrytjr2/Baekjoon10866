// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
struct link
{
	link* prev=NULL;
	int value;
	link* next = NULL;
};
class Deque
{
public:
	Deque() { head = NULL; tail = NULL; size = 0; }
	~Deque() {}
	void PushFront(int value)
	{
		if (head == NULL)
		{
			head = new link();
			head->value = value;
			tail = head;
			size = 1;
		}
		else
		{
			link* temp = new link();
			temp->value = value;
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}
	void PushBack(int value)
	{
		if (head == NULL)
		{
			head = new link();
			head->value = value;
			tail = head;
			size = 1;
		}
		else
		{
			link* temp = new link();
			temp->value = value;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	int PopFront()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			int value;
			value = head->value;
			if (head->next != NULL)
			{
				head = head->next;
				head->prev = NULL;
				size--;
			}
			else
			{
				tail = NULL;
				head = NULL;
				size = 0;
			}
			return value;
		}
	}
	int PopBack()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			int value;
			value = tail->value;
			if (tail->prev != NULL)
			{
				tail = tail->prev;
				tail->next = NULL; 
				size--;
			}
			else
			{
				tail = NULL;
				head = NULL;
				size = 0;
			}
			return value;
		}
	}
	int Size()
	{
		return size;
	}
	int Empty()
	{
		if (size <= 0)
		{
			return 1;
		}
		return 0;
	}
	int Front()
	{
		if (head == NULL)
		{
			return -1;
		}
		return head->value;
	}
	int Back()
	{
		if (tail == NULL)
		{
			return -1;
		}
		return tail->value;
	}
private:
	link* head;
	link* tail;
	int size;
};

int main()
{
	int N;
	Deque deque;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command="";
		cin >> command;
		if (command == "push_front")
		{
			int value;
			cin >> value;
			deque.PushFront(value);
		}
		else if (command == "push_back")
		{
			int value;
			cin >> value;
			deque.PushBack(value);
		}
		else if (command == "pop_front")
		{
			cout << deque.PopFront()<<'\n';
		}
		else if (command == "pop_back")
		{
			cout << deque.PopBack()<<'\n';
		}
		else if (command == "size")
		{
			cout << deque.Size()<<'\n';

		}
		else if (command == "empty")
		{
			cout << deque.Empty() << '\n';
		}
		else if (command == "front")
		{
			cout << deque.Front() << '\n';
		}
		else if (command == "back")
		{
			cout << deque.Back() << '\n';
		}

	}
}
