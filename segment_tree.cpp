// implement segment tree using vector
// based on given array

/* segment tree can be used to solve LeetCode 307. Range Sum Query - Mutable
problem, and so on.insert
Given array = {2, 4, 5, 7, 8, 9}, and store these numbers and sums into a 
binary tree as followed:
        35
    /       \
  6          29
/  \       /    \
2   4    12      17
        /  \    /  \
        5   7   8   9
the tree has an important characterister:
if the element at index ii is not a leaf, its left and right child are 
stored at index 2iand 2i+1 respectively. 
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> build_tree(vector<int>& array) {
    int sz = array.size();
    assert(sz);
    vector<int> tree(2 * sz, 0);
    // put array in second half of tree
    for (int i = 0; i < sz; i++)
        tree[i + sz] = array[i];
    // generate first half based on sums
    for (int i = sz - 1; i > 0; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    return tree;
}

// update tree due to changing of  an elemnt in array 
// O(log(n)) time complexity
void update_tree(vector<int>& tree, int pos, int val) {
    pos += tree.size() / 2;
    tree[pos] = val;
    while (pos > 1) {
        int left = pos, right = pos;
        if (pos % 2 == 0) right++;
        else left--;
        tree[pos / 2] = tree[left] + tree[right];
        pos = pos / 2;
    }
}

// range sum query of array using segment tree
int sum_range(vector<int>& tree, int left, int right) {
    left += tree.size() / 2;
    right += tree.size() / 2;
    int sum = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            sum += tree[left];
            left++;
        }
        if (right % 2 == 0) {
            sum += tree[right];
            right--;
        }
        left = left / 2;
        right = right / 2;
    }
    return sum;
}

int main() {
    vector<int> nums = {2, 4, 5, 7, 8, 9};
    vector<int> tree = build_tree(nums);
    for (int n : tree) cout << n << "\t";
    cout << endl << "after update : \n";
    update_tree(tree, 4, 10);
    for (int n : tree) cout << n << "\t";  
    cout << endl << sum_range(tree, 0, 4) << endl;
    system("pause");
    return 0;
}