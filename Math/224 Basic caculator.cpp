/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int calc(string s)
{
    //����һ�������ڵ���ʽ��ֵ�� ���Ժ��Զ���ո�
    //����㣺 "  -  1 + 50-1 +25   "
	int size = s.size();
	int pre(0), post(0), res(0);
	string sub;
	string signs = "+- ";
	while (1)
	{
		sub = "";
		post = s.find_first_not_of(signs, pre);
		
		if (post == string::npos)
			break;
		post = s.find_first_of(signs, post+1);
		if (post == string::npos)
			post = size;

		for(int i = pre; i < post; i++)
		{
			if (isdigit(s[i]) || s[i] == '+' || s[i] == '-')
			sub += s[i];
		}
		res += stoi(sub);
		pre = post;
	}
	return res;
}
//���Լ�������ŵģ���������ո�����ʽ�ӣ��磺 "  -  60-  (   -1-2 +  12 -(31  -5))  "
int calculate(string s) {
    int post(0), pre(0), sign_pos(0), res(0);
	string temp;
	char sign;
	while (post != string::npos)
	{
	    //�����ҵ�')'��λ�ã��浽post
    	post = s.find_first_of(')');
		if (post == string::npos)
			break;
		//�ڸ�λ��ǰ�ҵ�������Ե�'('��λ��, �浽pre
		pre = s.find_last_of('(', post);
		//��preǰ�ҵ������ŵ�λ��
		sign_pos = s.find_last_of("+-", pre);
		//���λ����Ч���������Ŵ浽sign��
		if (sign_pos != string::npos)
			sign = s.at(sign_pos);
		else
			sign = ' ';
        //����һ�������ڵ����ݴ���calc�����������һ��int��
		res = calc(s.substr(pre+1, post-pre-1));
		//�����������������ţ����Ѹ���ת��Ϊһ��string
		if (res < 0 && sign != ' ')
		{
			if (sign == '-')	
				s[sign_pos] = '+';
			else
				s[sign_pos] = '-';		
			temp = to_string(-res);	
		}
		else
			temp = to_string(res);
        //�����string replaceԭ�����Ǹ�ʽ�ӣ��ı�s������
		s.replace(pre, post-pre+1, temp);
	}
	return calc(s); //���s�ڲ��������ţ�ֱ��ʹ��calc�����ʽ�ӵ�ֵ
    }
int main()
{
	string s1 =  "  -  60-  (   -1-2 +  12 -(31  -5)) " ;
	fun(s1);
}
