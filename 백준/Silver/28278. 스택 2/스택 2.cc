#include <iostream>

struct NODE
{
	NODE(const int& value, NODE* link)
		: _value(value), _link(link) {};

	const int _value{};
	NODE* _link{};
};

class Stack
{
public:
	Stack() {};
	~Stack() { Clear(); };

public:
	void Push(const int& value)
	{
		NODE* node{ new NODE{value, _top} };

		if (nullptr == node)
			return;

		_top = node;

		++_size;
	}

	void Pop()
	{
		if (Empty())
			return;

		NODE* link = _top->_link;
		delete _top;
		_top = link;

		--_size;
	}

	const int Peek() const
	{
		return _top->_value;
	}

	const unsigned int Size() const 
	{
		return _size;
	}

	const bool Empty() const 
	{
		return (0 == _size);
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

		_size = 0;
	}

private:
	NODE* _top{};
	unsigned int _size{};
};

void Print(const int& value)
{
	std::cout << value << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Stack stack{};
	int n{}, command{};

	std::cin >> n;
	
	while (n--)
	{
		std::cin >> command;

		switch (command)
		{
		case 1 : 
		{
			int value{};
			std::cin >> value;
			stack.Push(value);
		}
			break;
		case 2:
		{
			if (stack.Empty())
				Print(-1);
			else
			{
				Print(stack.Peek());
				stack.Pop();
			}
		}
			break;
		case 3:
		{
			Print(stack.Size());
		}
			break;
		case 4:
		{
			if (stack.Empty())
				Print(1);
			else
				Print(0);
		}
			break;
		case 5:
		{
			if (!stack.Empty())
				Print(stack.Peek());
			else
				Print(-1);
		}
			break;
		default:
			break;
		}
	}
	return 0;
}