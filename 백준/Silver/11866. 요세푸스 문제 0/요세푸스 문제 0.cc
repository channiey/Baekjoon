#include <iostream>
using namespace std;

struct NODE
{
	NODE(const int& value, NODE* link = nullptr)
		: _value(value), _link(link) {};

	const int _value{};
	NODE* _link{};
};

class Queue
{
public:
	Queue() {};
	~Queue() { Clear(); };

public:
	void Enqueu(const int& value)
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
				_front->_link = node;
			else
				_rear->_link = node;

			_rear = node;
		}
	}

	const int Dequeue()	
	{
		if (Empty())
		{
			return int{};
		}
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
	int n{}, k{};
	Queue queue{};

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		queue.Enqueu(i);

	cout << "<";
	while (!queue.Empty())
	{
		for (int i = 0; i < k - 1; i++)
			queue.Enqueu(queue.Dequeue());

		cout << queue.Dequeue();

		if (!queue.Empty())
			cout << ", ";
	}
	cout << ">";

	return 0;
}