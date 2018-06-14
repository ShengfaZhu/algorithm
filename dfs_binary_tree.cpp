// DFS of binary tree
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// Definition of tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Depth first search of binary tree to get time stamp on each node
void dfs(TreeNode* root, int& t, unordered_map<int, vector<int>>& time) {
    if (root == NULL) return;
    time[root->val] = {++t, -1};
    dfs(root->left, t, time);
    dfs(root->right, t, time);
    time[root->val][1] = ++t;
}

// generate binary tree based on level traversal
// using INT_MAX to represent NULL 
TreeNode *generate_tree(const vector<int>& nums) 
{
    if (nums.empty())
        return NULL;
    queue<TreeNode*> q;// assist queue
    TreeNode *root = new TreeNode(nums.at(0));
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nums.size())
    {
        TreeNode *tmp = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != INT_MAX) {
            tmp->left = new TreeNode(nums[i]);
            q.push(tmp->left);
        }
        i++;
        if (i < nums.size() && nums[i] != INT_MAX){
            tmp->right = new TreeNode(nums[i]);
            q.push(tmp->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> nums = {3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4};
    TreeNode *root = generate_tree(nums);
    unordered_map<int, vector<int>> time;
    int t = 0;
    dfs(root, t, time);
    for (auto it = time.cbegin(); it != time.cend(); it++) {
        cout << it->first << " : ";
        for (int i : it->second) cout << i << "\t";
        cout << endl;  
    }
    system("pause");
    return 0;
}