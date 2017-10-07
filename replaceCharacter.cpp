// replace ' ' with '%20'
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		if (str == NULL || length < 0)
		{
			return;
		}
		int numBlank = 0;//记录空格数量
		int numCharOld = 0;//记录原字符数量,包括'\0'
		while (str[numCharOld] != '\0')//统计空格数量
		{
			if (str[numCharOld] == ' ')
			{
				numBlank++;
			}
			numCharOld++;
		}
		int numCharNew = numCharOld + numBlank * 2;//包括'\0'
		if (numCharNew > length)
		{
			return;
		}
		while (numCharNew >= 0 && numCharOld >= 0)
		{
			if (str[numCharOld] == ' ')
			{
				str[numCharNew--] = '0';
				str[numCharNew--] = '2';
				str[numCharNew--] = '%';
				numCharOld--;
			}
			else
			{
				str[numCharNew--] = str[numCharOld--];
			}
		}
	}
};
int main()
{
	char s[50] = "Hello world hi";
	cout << s << endl;
	char *str = s;
	Solution solu;
	solu.replaceSpace(str, 50);
	cout << s << endl;
}