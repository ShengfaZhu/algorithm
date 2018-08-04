#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

// definition of treenode
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// generate binary tree with level-traversal sequence
// denote nullptr with INT_MAX in sequence
TreeNode* buildTree(const vector<int>& seq) {
	if (seq.empty()) return NULL;
 	TreeNode* root = new TreeNode(seq[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while (!q.empty() && i < seq.size()) {
		TreeNode* curr = q.front();
		q.pop();
		if (seq[i] != INT_MAX) {
			curr->left = new TreeNode(seq[i]);
			q.push(curr->left);
		}
		i++;
		if (i < seq.size() && seq[i] != INT_MAX) {
			curr->right = new TreeNode(seq[i]);
			q.push(curr->right);
		}
		i++;
	}
	return root;
}

// level_traversal of BST
void levelTraversal(TreeNode* root) {
	if (root == nullptr) return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			TreeNode* curr = q.front();
			q.pop();
			cout << curr->val << "\t";
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
		cout << endl;
	}
}

// preorder traversal of BST
vector<int> preOrderTraversal(TreeNode * root)
{
	vector<int> v ;
	if (root == NULL) return v;
	else
	{
		v.push_back(root->val);
		vector<int> temp = preOrderTraversal(root->left);
		v.insert(v.end(), temp.begin(), temp.end());
		vector<int> temp2 = preOrderTraversal(root->right);
		v.insert(v.end(), temp2.begin(), temp2.end());
	}
	return v;
}

// inorder traversal of BST
vector<int> inOrderTraversal(TreeNode * root)
{
	vector<int> v;
	if (root == NULL) return v;
	else
	{
		vector<int> temp = inOrderTraversal(root->left);
		v.insert(v.end(), temp.begin(), temp.end());
		v.push_back(root->val);
		vector<int> temp2 = inOrderTraversal(root->right);
		v.insert(v.end(), temp2.begin(), temp2.end());
	}
	return v;
}

// postorder traversal of BST
vector<int> postOrderTraversal(TreeNode * root)
{
	vector<int> v;
	if (root == NULL) return v;
	else
	{
		vector<int> temp = postOrderTraversal(root->left);
		v.insert(v.end(), temp.begin(), temp.end());
		vector<int> temp2 = postOrderTraversal(root->right);
		v.insert(v.end(), temp2.begin(), temp2.end());
		v.push_back(root->val);
	}
	return v;
}

// test code
// int main()
// {
// 	vector<int> v = {5, 3, 7, 1, 4, 6, 8};
// 	TreeNode *root = buildTree(v);
// 	levelTraversal(root);
// 	system("pause");
// 	return 0;
// }