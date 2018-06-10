// merge sort recursive way
#include <iostream>
#include <cstdlib> //rand()
#include <climits>
#include <cassert>
#include <vector>
#include <ctime>
using namespace std;

void merge(vector<int>& nums, int p, int q, int r)
{
	assert(p <= q);
	assert(q + 1 <= r);
	int len1 = q - p + 1;
	int len2 = r - q;
	vector<int> L(nums.begin() + p, nums.begin() + q + 1);
	vector<int> R(nums.begin() + q + 1, nums.begin() + r + 1);
	L.push_back(INT_MAX), R.push_back(INT_MAX);
	int i = 0, j = 0, k = p;
	while (k <= r) {
		if (L[i] < R[j]) {
			nums[k] = L[i];
			i++;
		}
		else {
			nums[k] = R[j];
			j++;
		}
		k++;
	}
}

void merge_sort(vector<int>& nums, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(nums, low, mid);
		merge_sort(nums, mid + 1, high);
		merge(nums, low, mid, high);
	}
}


int main() {
    vector<int> nums;
    for (int i = 0; i < 20; i++) {
        nums.push_back(rand() % 20);
    }
    cout << "before sorting : " << endl;
    for (int i : nums) cout << i << "\t";
    merge_sort(nums, 0, nums.size() - 1);
    cout << "\nafter sorting : \n";
    for (int i : nums) cout << i << "\t";   
    system("pause");
    return 0;
}

