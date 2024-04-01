#include <iostream>

struct NODE
{
	NODE(const int& value)
		: _value(value) {};

	const int _value{};
	NODE* _prev{}, * _next{};
};

class Deque
{
public:
	Deque() {};
	~Deque() { Clear(); };

public:
	void InsertFront(const int& value)
	{
		NODE* node{ new NODE{value} };

		if (nullptr == node)
			return;

		if (Empty())
		{
			_front = _rear = node;
		}
		else
		{
			node->_next = _front;
			_front->_prev = node;

			_front = node;
		}

		++_size;
	}

	void InsertRear(const int& value)
	{
		NODE* node{ new NODE{value} };

		if (nullptr == node)
			return;

		if (Empty())
		{
			_front = _rear = node;
		}
		else
		{
			node->_prev = _rear;
			_rear->_next = node;

			_rear = node;
		}

		++_size;
	}

	void DeleteFront()
	{
		if (Empty())
			return;

		if (_front == _rear)
		{
			delete _front;

			_front = _rear = nullptr;
		}
		else
		{
			NODE* next = _front->_next;
			next->_prev = nullptr;
			delete _front;

			_front = next;
		}

		--_size;
	}

	void DeleteRear()
	{
		if (Empty())
			return;

		if (_front == _rear)
		{
			delete _front;

			_front = _rear = nullptr;
		}
		else
		{
			NODE* prev = _rear->_prev;
			prev->_next = nullptr;
			delete _rear;

			_rear = prev;
		}

		--_size;
	}

	const int PeekFront()
	{
		if (Empty())
			return int{};
		else
			return _front->_value;
	}

	const int PeekRear()
	{
		if (Empty())
			return int{};
		else
			return _rear->_value;
	}

	const bool Empty() const
	{
		return (0 == _size);
	}

	const int& Size() const 
	{
		return _size;
	}

private:
	void Clear()
	{
		NODE* next{};

		while (nullptr != _front)
		{
			next = _front->_next;

			delete _front;

			_front = next;
		}

		_front = _rear = nullptr;

		_size = 0;
	}

private:
	NODE* _front{},* _rear{};
	int _size{};
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Deque deque{};
	int n{}, m{};

	std::cin >> n;

	while (n--)
	{
		std::cin >> m;
		switch (m)
		{
		case 1 :
		{
			std::cin >> m;
			deque.InsertFront(m);
		}
		break;
		case 2:
		{
			std::cin >> m;
			deque.InsertRear(m);
		}
		break;
		case 3:
		{
			if (deque.Empty())
				std::cout << -1 << "\n";
			else
			{
				std::cout << deque.PeekFront() << "\n";
				deque.DeleteFront();
			}
		}
		break;
		case 4:
		{
			if (deque.Empty())
				std::cout << -1 << "\n";
			else
			{
				std::cout << deque.PeekRear() << "\n";
				deque.DeleteRear();
			}
		}
		break;
		case 5:
		{
			std::cout << deque.Size() << "\n";
		}
		break;
		case 6:
		{
			if (deque.Empty())
				std::cout << 1 << "\n";
			else
				std::cout << 0 << "\n";
		}
		break;
		case 7:
		{
			if (deque.Empty())
				std::cout << -1 << "\n";
			else
				std::cout << deque.PeekFront() << "\n";
		}
		break;
		case 8:
		{
			if (deque.Empty())
				std::cout << -1 << "\n";
			else
				std::cout << deque.PeekRear() << "\n";
		}
		break;
		default:
			break;
		}
	}

	return 0;
}