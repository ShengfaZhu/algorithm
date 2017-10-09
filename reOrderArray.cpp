#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
// reorder array to make all odd numbers is before even numbers
// and the order of odd numbers and even number doesn't chager.

// erase the even number and push back it into array 
void reOrderArray(vector<int> &array){
	vector<int>::iterator even = array.begin();
	int size = array.size();
	while (size)
	{
		if (*even % 2 == 0)
		{
			int temp = *even;
			even = array.erase(even);
			array.push_back(temp);
		}
		else even++;	
		size--;
	}
}

int main()
{
	vector<int> v = { 3, 1, 2, 4, 7, 5 };
	reOrderArray(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\t';
	}
}