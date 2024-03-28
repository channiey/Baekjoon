#include <iostream>

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

		if (nullptr == node)
			return;

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
	}

	const int Dequeue()
	{
		if (Empty())
			return int{};
		else
		{
			const int value{ _front->_value };

			if (_front == _rear)
			{
				delete _front;
				_front = _rear = nullptr;
			}
			else
			{
				NODE* link{ _front->_link };
				delete _front;
				_front = link;
			}
			return value;
		}
	}

	const bool Empty() const 
	{
		return nullptr == _front;
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

		_front = _rear = nullptr;
	}

private:
	NODE* _front{}, * _rear{};
};

int main()
{
	int n{}, m{};
	Queue queue{};
	
	std::cin >> n;

	for (int i = 1; i <= n; i++)
		queue.Enqueue(i);

	while (true)
	{
		if (!queue.Empty())
		{
			m = queue.Dequeue();

			if (queue.Empty())
				break;

			m = queue.Dequeue();

			if (queue.Empty())
				break;

			queue.Enqueue(m);
		}
	}

	std::cout << m;

	return 0;
}