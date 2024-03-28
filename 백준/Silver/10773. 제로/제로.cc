#include <iostream>

struct STACK_NODE
{
	STACK_NODE(const int& value, STACK_NODE* link)
		: _value(value), _link(link) {};

	int _value{};
	STACK_NODE* _link{};
};

STACK_NODE* Push(STACK_NODE* top, const int& value)
{
	STACK_NODE* node{ new STACK_NODE{value, top} };

	return node;
}

STACK_NODE* Pop(STACK_NODE* top)
{
	if (nullptr == top)
		return nullptr;

	STACK_NODE* link = top->_link;
	delete top;
	
	return link;
}

const unsigned int Sum(STACK_NODE* top)
{
	unsigned int Acc{};

	if (nullptr == top)
		return Acc;

	STACK_NODE* link{};

	while (nullptr != top)
	{
		Acc += top->_value;
		
		link = top->_link;
		delete top;
		top = link;
	}

	return Acc;
}

int main()
{
	int k{}, n{};
	STACK_NODE* top{};

	std::cin >> k;

	while (k--)
	{
		std::cin >> n;

		if (0 == n)
			top = Pop(top);
		else
			top = Push(top, n);
	}

	std::cout << Sum(top);
	top = nullptr;

	return 0;
}