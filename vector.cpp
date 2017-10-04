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

	return 0;
}