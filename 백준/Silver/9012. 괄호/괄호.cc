#include <iostream>
#include <string>
using namespace std;

struct NODE
{
	NODE(const char& value, NODE* link)
		: _value(value), _link(link) {};

	const char _value{};
	NODE* _link{};
};

class Stack
{
public:
	Stack() {};
	~Stack() { Clear(); };

public:
	const bool Push(const char& value)
	{
		NODE* node{ new NODE{value, _top} };

		if (nullptr == node)
			return false;

		_top = node;
		return true;
	}

	const bool Pop()
	{
		if (Empty())
			return false;

		NODE* link = _top->_link;
		delete _top;
		_top = link;

		return true;
	}

	const char Peek() const
	{
		if (Empty())
			return char{};

		return _top->_value;
	}

	const bool Empty() const 
	{
		return (nullptr == _top);
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

const bool IsPS(const string& str)
{
	Stack stack{};

	const size_t len = str.length();

	for (size_t i = 0; i < len; i++)
	{
		const char ch = str[i];

		if ('(' == ch)
			stack.Push(ch);
		else if (')' == ch)
		{
			if (stack.Empty() || '(' != stack.Peek())
				return false;
			
			stack.Pop();
		}
		else
			return false;
	}

	return stack.Empty();
}

int main()
{
	int T{};
	string str{};
	cin >> T;

	while (T--)
	{
		cin >> str;

		cout << (IsPS(str) ? "YES\n" : "NO\n");
	}
	
	return 0;
}