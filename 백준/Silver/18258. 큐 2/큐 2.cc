#include <iostream>
#include <string>
using namespace std;

struct NODE
{
	NODE(const int& value)
		: _value(value) {};

	const int _value{};
	NODE* _link{};
};

class Queue
{
public:
	Queue() {};
	~Queue() { Clear(); };

public:
	void Enqueue(const int& value)
	{
		NODE* node{ new NODE{value} };

		if (Empty())
		{
			_front = _rear = node;
		}
		else
		{
			if (_front == _rear)
			{
				_front->_link = node;
			}
			else
			{
				_rear->_link = node;
			}

			_rear = node;
		}
		++_size;
	}

	const int Dequeue()
	{
		if (Empty())
			return int{};
		else
		{
			--_size;

			int value{_front->_value};

			if (_front == _rear)
			{
				delete _front;
				_front = _rear = nullptr;
			}
			else
			{
				NODE* link = _front->_link;
				delete _front;
				_front = link;
			}

			return value;
		}
	}

	const int Front()
	{
		if (Empty())
			return int{};
		else
			return _front->_value;
	}

	const int Back()
	{
		if (Empty())
			return int{};
		else
			return _rear->_value;
	}


	const bool Empty() const 
	{
		return (nullptr == _front);
	}

	const int& Size() const
	{
		return _size;
	}

private:
	void Clear()
	{
		NODE* link{};

		while (nullptr != _front)
		{
			link = _front->_link;
			delete _front;
			_front = link;
		}

		_size = 0;
		_front = _rear = nullptr;
	}

private:
	NODE* _front{}, * _rear{};
	int _size{};
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Queue queue{};
	int n{}, k{};
	string str{};

	cin >> n;

	while (n--)
	{
		cin >> str;

		if ("push" == str)
		{
			cin >> k;
			queue.Enqueue(k);
		}
		else if ("pop" == str)
		{
			if (queue.Empty())
				cout << -1 << "\n";
			else
				cout << queue.Dequeue() << "\n";
		}
		else if ("size" == str)
		{
			cout << queue.Size() << "\n";
		}
		else if ("empty" == str)
		{
			if (queue.Empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if ("front" == str)
		{
			if (queue.Empty())
				cout << -1 << "\n";
			else
				cout << queue.Front() << "\n";
		}
		else if ("back" == str)
		{
			if (queue.Empty())
				cout << -1 << "\n";
			else
				cout << queue.Back() << "\n";
		}
	}

	return 0;
}