#include <iostream>
#include <vector>
using namespace std;


struct Node {
	int val;
	struct Node *next;
	Node(int x) :val(x), next(NULL) {}
};

class LinkList
{
private:
	Node *head;
public:
	LinkList();//���캯��
	LinkList(Node *head1);//���ع��캯��
	LinkList(vector<int> v);//���ع��캯��
	void insertHead(int val);//ͷ�庯��
	void insert(int val, int pos);//����
	void remove(int val);//ɾ��
	int getLength();//������
	vector<int> find(int val);//����
	void print();//��ӡ
	LinkList findKthToTail(unsigned int k);//ȡ������k��ĩβ������
	LinkList reverseList();//����ת
};

LinkList::LinkList()
{
	head = NULL;
}

LinkList::LinkList(Node *head1)
{
	head = head1;
}

LinkList::LinkList(vector<int> v)
{
	if (v.size() < 1) head = NULL;
	head = new Node(v[0]);
	Node *p = head;
	for (int i = 1; i < v.size(); i++)
	{
		Node *temp = new Node(v[i]);
		p->next = temp;
		p = temp;
	}
}

void LinkList::insertHead(int val)
{
	insert(val, 0);
}

void LinkList::insert(int val, int pos)
{
	if (pos < 0)
	{
		cout << "The position doesn't exit!" << endl;
		return;
	}
	Node *temp = new Node(val);
	if (pos == 0)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node *p = head;
		while (--pos || p->next == NULL)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

void LinkList::remove(int val)
{
	if (head == NULL)
	{
		cout << "The linklist is empty" << endl;
		return;
	}
	Node *last = head, *pre = head->next;
	while (pre != NULL)
	{
		if (pre->val == val)
		{
			pre = pre->next;
			last->next = pre;
		}
		else
		{

			pre = pre->next;
			last = last->next;
		}
	}
}

int LinkList::getLength()
{
	int length = 0;
	Node *p = head;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}

vector<int> LinkList::find(int val)
{
	vector<int> pos;
	if (head == NULL)
	{
		cout << "The linklist is empty." << endl;
		return pos;
	}
	Node *p = head;
	int count = 0;
	while (p != NULL)
	{
		if (p->val == val) pos.push_back(count);
		count++;
		p = p->next;
	}
	return pos;
}

void LinkList::print()
{
	if (head == NULL)
	{
		cout << "The linklist is empty." << endl;
		return;
	}
	Node *p = head;
	while (p != NULL)
	{
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
}

LinkList LinkList::findKthToTail(unsigned int k)
{
	if (head == NULL || k < 1) return NULL;
	Node *pre = head, *last = head;
	int count = 1;
	while (count < k)
	{
		if (pre->next == NULL)
		{
			return NULL;
		}
		else
		{
			pre = pre->next;
			count++;
		}
	}
	while (pre->next != NULL)
	{
		pre = pre->next;
		last = last->next;
	}
	return LinkList(last);

}

LinkList LinkList::reverseList()
{
	if (head == NULL) return NULL;
	Node *head_rev = new Node(head->val), *p = head->next;
	while (p != NULL)
	{
		Node *temp = new Node(p->val);
		temp->next = head_rev;
		head_rev = temp;
		p = p->next;
	}
	return LinkList(head_rev);
}
