/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。*/
//采用分治递归策略，进行搜索
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int low1 = 0;
		int low2 = 0;
		int high1 = array.size()-1;
		int high2 = array[0].size()-1;	
		return findTarget(target, array, low1, low2, high1, high2);
	}
	bool findTarget(int target, vector<vector<int> > array, int low1, int low2, int high1, int high2)
	{
		
		if (low1 > high1 || low2 > high2)
		{
			return false;
		}
		else if (target == array[low1][low2] || target == array[high1][high2])
		{
			return true;
		}
		else if (low1 == high1 && low2 == high2)
		{
			return false;
		}
		
		else if (target < array[low1][low2] || target > array[high1][high2])
		{
			return false;
		}
		else
		{
			int mid1 = (low1 + high1) / 2;
			int mid2 = (low2 + high2) / 2;
			return findTarget(target, array, low1, low2, mid1, mid2) || findTarget(target, array, low1, mid2+1, mid1, high2) || findTarget(target, array, mid1+1, low2+1, high1, mid2) || findTarget(target, array, mid1+1, mid2+1, high1, high2);
		}
	}
};
int main()
{
	vector<vector<int>> a(10, vector<int>(5, 0));//10ÐÐ5ÁÐ£¬³õÖµÎª1µÄ¶þÎ¬ÏòÁ¿£¬¾ØÕó
	cout << "Vector a : " << endl;
	int k = 1;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			a[i][j] = k;
			cout << a[i][j] << "\t";
			k++;
		}
		cout << endl;
	}
	int target = 20;
	Solution s;
	cout << s.Find(target, a) << endl;;
	return 0;
}