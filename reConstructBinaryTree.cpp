# include <iostream>
# include <vector>
using namespace std;

//根据二叉树前序和中序遍历的结果，重建二叉树
//分治思想，找到根结点，左右子树分别递归调用

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode *root = reConstruct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
		return root;
	}
private:
	TreeNode *reConstruct(vector<int> pre, int startPre, int endPre, vector<int> vin, int startIn, int endIn)
	{
		if (startPre > endPre || startIn > endIn) return NULL;
		TreeNode *root = new TreeNode(pre[startPre]);
		for (int i = startIn; i <= endIn; i++)
		{
			if (vin[i] == pre[startPre])
			{
				root->left = reConstruct(pre, startPre + 1, startPre + i - startIn, vin, startIn, i - 1);
				root->right = reConstruct(pre, startPre + i - startIn + 1, endPre, vin, i + 1, endIn);
				break;
			}
		}
		return root;
	}
};

vector<int> preOrderTraversal(TreeNode * root)
{
	vector<int> pre;
	if (root != NULL){
		pre.push_back(root->val);
		vector<int> temp = preOrderTraversal(root->left);
		pre.insert(pre.end(), temp.begin(), temp.end());
		temp = preOrderTraversal(root->right);
		pre.insert(pre.end(), temp.begin(), temp.end());
	}
	return pre;
}

vector<int> vinOrderTraversal(TreeNode * root)
{
	vector<int> vin;
	if (root != NULL){		
		vector<int> temp = vinOrderTraversal(root->left);
		vin.insert(vin.end(), temp.begin(), temp.end());
		vin.push_back(root->val);
		temp = vinOrderTraversal(root->right);
		vin.insert(vin.end(), temp.begin(), temp.end());
	}
	return vin;
}

vector<int> posOrderTraversal(TreeNode * root)
{
	vector<int> pos;
	if (root != NULL){
		vector<int> temp = posOrderTraversal(root->left);
		pos.insert(pos.end(), temp.begin(), temp.end());	
		temp = posOrderTraversal(root->right);
		pos.insert(pos.end(), temp.begin(), temp.end());
		pos.push_back(root->val);
	}
	return pos;
}

int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };//¶þ²æÊ÷µÄÇ°Ðò±éÀú½á¹û
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };//¶þ²æÊ÷µÄºóÐò±éÀú½á¹û
	Solution solu;
	TreeNode *root = solu.reConstructBinaryTree(pre, vin);
	//½«¶þ²æÊ÷°´Ç°Ðò¡¢ÖÐÐòºÍºóÐò±éÀú
	vector<int> pre1 = preOrderTraversal(root);
	cout << "PreOrder traveral : " << endl;
	for (int i = 0; i < pre1.size(); i++)
	{
		cout << pre1[i] << '\t';
	}
	cout << endl;
	vector<int> vin1 = vinOrderTraversal(root);
	cout << "InOrder traveral : " << endl;
	for (int i = 0; i < vin1.size(); i++)
	{
		cout << vin1[i] << '\t';
	}
	cout << endl;
	vector<int> pos = posOrderTraversal(root);
	cout << "PostOrder traveral : " << endl;
	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i] << '\t';
	}
	cout << endl;

	return 0;

}