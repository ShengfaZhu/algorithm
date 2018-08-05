#include <iostream>
#include <vector>
#include <cstdlib>// header file for rand
#include <queue>// header file for priority queue
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    if (low < 0 || high >= nums.size() || low > high) return -1;
    if (low == high) return low;
    int index = low + rand() % (high - low + 1);
    swap(nums[index], nums[low]);
    int ele = nums[low];
    while (low < high) {
        while (high > low && (nums[high] >= ele)) high--;
        nums[low] = nums[high];
        while (low < high && (nums[low] <= ele)) low++;
        nums[high] = nums[low]; 
    }
    nums[low] = ele;
    return low;
}

/* // partition method
int kMinimumEle(vector<int> nums, int k) {
    k--;
    if (nums.empty() || k < 0 || k > nums.size()) {
        return -1;
    }
    int low = 0, high = nums.size() - 1;
    int index = partition(nums, low, high);
    while (index != k) {
        if (index < k) low = index + 1;
        else high = index - 1;
        index = partition(nums, low, high);
    }
    return nums[index];
} */

// heap method
int kMinimumEle(vector<int> nums, int k) {
    if (nums.empty() || k < 0 || k > nums.size()) return -1;
    priority_queue<int> heap;
    for (int i = 0; i < nums.size(); i++) {
        if (heap.size() < k) heap.emplace(nums[i]);
        else {
            if (nums[i] < heap.top()) {
                heap.pop();
                heap.emplace(nums[i]);
            } 
        }
    }
    return heap.top();
}

int main()
{
    vector<int> nums = {5, 1, 3, 4, 9, 8, 8, 2};
    for (int i = 1; i <= nums.size(); i++) {
        cout << i << " : " << kMinimumEle(nums, i) << endl;
    }
    system("pause");
    return 0;
}
