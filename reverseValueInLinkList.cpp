#include <iostream>
#include <vector>
using namespace std;
//将链表值反转输出,vector operate

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> value;
		if (head != NULL)
		{
			value.push_back(head->val);
			while (head->next!= NULL)
			{
				value.push_back(head->next->val);
				head = head->next;
			}
			reverse(value.begin(), value.end());
		}
		return value;
	}
};

int main()
{
	
	return 0;
}