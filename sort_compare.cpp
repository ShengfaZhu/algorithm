// compare merge sort and quick sort
#include <ctime>
#include <iostream>
#include <iomanip>
#include "./quick_sort.cpp"
#include "./merge_sort.cpp"
using namespace std;

int main() {
    double dur1 = 0.0, dur2 = 0.0;
    clock_t start,end;
    for (int k = 0; k < 500; k++) {
        vector<int> nums1, nums2;
        int count = 1000;
        for (int i = 0; i < count; i++) {
            nums1.push_back(rand() % count);
        }
        nums2 = nums1;
        start = clock();
        quick_sort(nums1, 0, nums1.size());
        end = clock();
        dur1 += (double)(end - start);
        
        start = clock();
        merge_sort(nums2, 0, nums2.size() - 1); 
        end = clock();
        dur2 += (double)(end - start);
    }
    cout << setiosflags(ios::fixed) << setprecision(5);//五位小数，不够添零
    cout << "Time of quick sort(s): " << dur1/CLOCKS_PER_SEC << endl;
    cout << "Time of merge sort(s): " << dur2/CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}