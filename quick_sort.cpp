// quick sort algorithm
#include <iostream>
#include <vector>
#include <cassert> // header file for assert()
#include <cstdlib> // header file for rand()
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    // 任取一元素与首元素交换，后续以首元素作为基准
    int r = low + rand() % (high - low + 1);
    int tmp = nums[low];
    nums[low] = nums[r];
    nums[r] = tmp;
    int pivot = nums[low];
    // 由向量两端向中部扫描
    while (low < high) {
        while (low < high && pivot <= nums[high])
            high--;
        nums[low] = nums[high];
        while (low < high && pivot >= nums[low])
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

void quick_sort(vector<int>& nums, int low, int high) {
    assert(low >= 0);
    assert(high <= nums.size());
    if (high - low < 2) return;// 仅含一个元素,有序
    int m = partition(nums, low, high - 1);
    quick_sort(nums, low, m);
    quick_sort(nums, m + 1, high);
}

int main() {
    vector<int> nums;
    for (int i = 0; i < 20; i++) {
        nums.push_back(rand() % 20);
    }
    cout << "before sorting : " << endl;
    for (int i : nums) cout << i << "\t";
    quick_sort(nums, 0, nums.size());
    cout << "\nafter sorting : \n";
    for (int i : nums) cout << i << "\t";   
    system("pause");
    return 0;
}

