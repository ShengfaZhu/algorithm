#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 3, 2};
    // generate heap in the range of numsector
    make_heap(nums.begin(), nums.end());
    cout << "initial max value : " << nums.front() << endl;
    // pop max value
    pop_heap(nums.begin(), nums.end());
    nums.pop_back();
    cout << "after pop, the max vsalue : " << nums.front() << endl;
    // push a new value
    nums.push_back(6);
    push_heap(nums.begin(), nums.end());
    cout << "after push, the max value : " << nums.front() << endl;

    // define cmp function
    auto cmp = [](const int x, const int y) { return x > y;};
    vector<int> nums2 = {40, 50, 10, 30, 20};
    // generate heap in the range of numsector
    make_heap(nums2.begin(), nums2.end(), cmp);
    cout << "initial max value : " << nums2.front() << endl;
    // pop max value
    pop_heap(nums2.begin(), nums2.end(), cmp);
    nums.pop_back();
    cout << "after pop, the max vsalue : " << nums2.front() << endl;
    // push a new value
    nums2.push_back(0);
    push_heap(nums2.begin(), nums2.end(), cmp);
    cout << "after push, the max value : " << nums2.front() << endl;
    system("pause");
    return 0;
}