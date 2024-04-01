#include "includes/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	//std::cout << *it << std::endl; //TEST
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

/*
Si vous l’exécutez une première fois avec votre MutantStack, puis une seconde fois en
remplaçant la MutantStack, par exemple par std::list, les deux résultats devront Ÿtre
identiques. Bien sûr, lorsque vous testez cet exemple avec un autre container, modiez le
code avec les fonctions membres correspondantes (push() peut devenir push_back()).
*/