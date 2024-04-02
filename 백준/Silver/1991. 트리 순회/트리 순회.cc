#include <iostream>

struct NODE
{
	void PreorderTraversal(NODE* node)
	{
		if (nullptr == node)
			return;

		node->Print();
		PreorderTraversal(node->_lc);
		PreorderTraversal(node->_rc);
	}

	void InorderTraversal(NODE* node) 
	{
		if (nullptr == node)
			return;

		InorderTraversal(node->_lc);
		node->Print();
		InorderTraversal(node->_rc);
	}

	void PostorderTraversal(NODE* node) 
	{
		if (nullptr == node)
			return;

		PostorderTraversal(node->_lc);
		PostorderTraversal(node->_rc);
		node->Print();
	}

	void Print() const
	{
		std::cout << _value;
	}

	char _value{};
	NODE* _lc{}, * _rc{};
};


int main()
{
	int n{};
	char ch{};
	std::cin >> n;

	NODE* Tree = new NODE[n];

	while(n--)
	{
		std::cin >> ch;
		const int nodeIndex{ int(ch - 'A') };

		Tree[nodeIndex]._value = ch;

		std::cin >> ch;
		if ('.' != ch)
			Tree[nodeIndex]._lc = &Tree[int(ch - 'A')];

		std::cin >> ch;
		if ('.' != ch)
			Tree[nodeIndex]._rc = &Tree[int(ch - 'A')];
	}
	
	Tree->PreorderTraversal(Tree);
	std::cout << "\n";
	Tree->InorderTraversal(Tree);
	std::cout << "\n";
	Tree->PostorderTraversal(Tree);

	delete[] Tree;
	
	return 0;
}