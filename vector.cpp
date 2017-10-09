#include <iostream>
#include <vector>
using namespace std;
// c++ vector操作
int main()
{
	vector<int> a(10, 1);//大小为10，初值为1的一维向量
	cout << "Vector a : " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "\t";
	}
	vector<vector<int>> b(10, vector<int>(5,1));//10行5列，初值为1的二维向量，矩阵
	cout << "Vector b : " << endl;
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	vector<int> c;
	c.push_back(1);//在后面插入
	//c.insert(pos,elem);//在pos处插入elem
	//c.begin();//数组的头指针，与insert一起用，可以头插
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\t';
	}
	reverse(v.begin(), v.end());
	cout << "\nAfter reversing : " << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\t';
	}
	
	vector<int> v = { 3, 1, 2, 4, 7, 5 };
	vector<int> v_copy(v);
	//v_copy.assign(v.begin(), v.end());//copy v to v_copy

	return 0;
}