#include <iostream>
#include <vector>
using namespace std;
//�����������ɡ������;���

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//���ɶ�����,root->left->right
//��ǰ�����У������սڵ㣬����Ψһȷ��������
//�սڵ���INT_MAX��ʾ
TreeNode *binaryTreeGenerate(vector<int> v)
{
	static int pos = -1;
	pos++;
	if (v.empty()) return NULL;
	TreeNode *t = new TreeNode(NULL);
	if (v[pos] == INT_MAX) return NULL;
	else
	{
		t->val = v[pos];
		t->left = binaryTreeGenerate(v);
		t->right = binaryTreeGenerate(v);
	}
	return t;
}

//��������ǰ�����
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

//���������������
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

//�������ĺ������
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

void Mirror(TreeNode *root)
{
	if (root == NULL) return;
	else
	{
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		Mirror(root->left);
		Mirror(root->right);
	}
}



int main()
{
	vector<int> v = { 8, 6, 5, INT_MAX, INT_MAX, 7, 
		INT_MAX, INT_MAX, 10, 9, INT_MAX, 
		INT_MAX, 11, INT_MAX, INT_MAX };
	TreeNode *root = binaryTreeGenerate(v);
	Mirror(root);
	vector<int> v3 = preOrderTraversal(root);

	for (vector<int>::iterator iter = v3.begin(); iter != v3.end();iter++)
	{
		cout << *iter << '\t';
	}
}