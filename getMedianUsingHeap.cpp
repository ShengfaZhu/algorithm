#include <iostream>
#include <vector>
#include <queue>//priority_queque needed
#include <functional>// greater needer
using namespace std;

class Solution {
	priority_queue<int, vector<int>, less<int>> left;//´ó¶Ñ
	priority_queue<int, vector<int>, greater<int>> right;//Ð¡¶Ñ
public:
	void Insert(int num)
	{
		if (left.empty() || num <= left.top()) left.push(num);
		else right.push(num);
		if(left.size() +1 == right.size())
		{
			left.push(right.top());
			right.pop();
		}
		if (left.size() == right.size()+2)
		{
			right.push(left.top());
			left.pop();
		}
	}

	double GetMedian()
	{ 
		return (left.size()== right.size() ? (left.top()+right.top())/2.0 : left.top());
	}

};



int main()
{
	int data[] = {5, 2, 4, 6, 8, 1, 0, 7, 3, 9};
	Solution solu;
	for (int i = 0; i < 10; i++)
	{
		solu.Insert(data[i]);
	}
	cout<<"the median number is " <<solu.GetMedian()<<endl;

}

