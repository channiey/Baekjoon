#include <iostream>

struct NODE
{
	NODE(const unsigned int& value, NODE* link)
		: _value(value), _link(link) {};

	const unsigned int _value{};
	NODE* _link{};
};

class Stack
{
public:
	Stack() {};
	~Stack() { Clear(); };

public:
	void Push(const unsigned int& value)
	{
		NODE* node{ new NODE{value, _top} };
		_top = node;
	}

	void Pop()
	{
		if (nullptr != _top)
		{
			NODE* link = _top->_link;
			delete _top;
			_top = link;
		}
	}

	const unsigned int& Peek() const
	{
		return _top->_value;
	}

	const bool Empty() const 
	{
		return (nullptr == _top);
	}

	void Reverse()
	{
		NODE* p{}, * q{}, * r{};

		p = _top;

		while (nullptr != p)
		{
			r = q;
			q = p;
			p = p->_link;

			q->_link = r;
		}

		_top = q;
	}

private:
	void Clear()
	{
		NODE* link{};

		while (nullptr != _top)
		{
			link = _top->_link;
			delete _top;
			_top = link;
		}
	}

private:
	NODE* _top{};
};

int main()
{
	Stack A{}, B{};
	unsigned int n{}, k{};

	std::cin >> n;

	while (n--)
	{
		std::cin >> k;
		A.Push(k);
	}

	A.Reverse();

	n = 1;
	while (!A.Empty() || !B.Empty())
	{
		if (!A.Empty() && n == A.Peek())
		{
			A.Pop();
			++n;
			continue;
		}
		else if (!B.Empty() && n == B.Peek())
		{
			B.Pop();
			++n;
			continue;
		}
		else if (B.Empty() || A.Peek() < B.Peek())
		{
			B.Push(A.Peek());
			A.Pop();
			continue;
		}

		break;
	}

	std::cout << ((A.Empty() && B.Empty()) ? "Nice" : "Sad");

	return 0;
}