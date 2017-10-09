#include <iostream>
#include <stack>
using namespace std;
//push and pop operator of stack
int main()
{
	stack<int> mystack;
	for (int i = 0; i < 5; i++)
	{
		mystack.push(i);
	}
	while (!mystack.empty())
	{
		cout << mystack.top() << "  ";
		mystack.pop();
	}
}