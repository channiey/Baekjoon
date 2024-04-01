#include <iostream>

template <typename T1, typename T2>
class Pair
{
public:
	Pair() {};
	Pair(const T1& first, const T2& second)
		: _first(first), _second(second){};

public:
	const T1 _first{}, _second{};
};

template <typename T>
class Node
{
public:
	Node(const T& value)
		: _value(value) {};

public:
	const T _value{};
	Node<T>* _prev{}, * _next{};
};

template <typename T>
class Deque
{
public:
	Deque() {};
	~Deque() { Clear(); };

public:
	void InsertFront(const T& value)
	{
		Node<T>* node{ new Node<T>{value} };

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

	void InsertRear(const T& value)
	{
		Node<T>* node{ new Node<T>{value} };

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

	const T DeleteFront()
	{
		if (Empty())
			return T{};

		const T value{ _front->_value };

		if (_front == _rear)
		{
			delete _front;

			_front = _rear = nullptr;
		}
		else
		{
			Node<T>* next = _front->_next;
			next->_prev = nullptr;
			delete _front;

			_front = next;
		}

		--_size;

		return value;
	}

	const T DeleteRear()
	{
		if (Empty())
			return T{};

		const T value{ _rear->_value };

		if (_front == _rear)
		{
			delete _front;

			_front = _rear = nullptr;
		}
		else
		{
			Node<T>* prev = _rear->_prev;
			prev->_next = nullptr;
			delete _rear;

			_rear = prev;
		}

		--_size;

		return value;
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
		Node<T>* next{};

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
	Node<T>* _front{},* _rear{};
	int _size{};
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	typedef Pair<int, int>	PAIR;

	Deque<PAIR> deque{};
	int n{}, m{};

	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> m; 
		deque.InsertRear(PAIR(i, m));
	}

	n = deque.DeleteFront()._second; 
	std::cout << 1 << " ";

	while (!deque.Empty())
	{
		if (n > 1)
		{
			--n;
			deque.InsertRear(deque.DeleteFront());
		}
		else if (n < 0)
		{
			++n;
			deque.InsertFront(deque.DeleteRear());
		}
		else
		{
			PAIR pair = deque.DeleteFront();
			std::cout << pair._first << " ";
			n = pair._second;
		}
	}

	return 0;
}