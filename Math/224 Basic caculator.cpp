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
    //计算一个括号内的算式的值， 可以忽略多个空格
    //如计算： "  -  1 + 50-1 +25   "
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
//可以计算带括号的，包含随意空格数的式子，如： "  -  60-  (   -1-2 +  12 -(31  -5))  "
int calculate(string s) {
    int post(0), pre(0), sign_pos(0), res(0);
	string temp;
	char sign;
	while (post != string::npos)
	{
	    //依次找到')'的位置，存到post
    	post = s.find_first_of(')');
		if (post == string::npos)
			break;
		//在该位置前找到与其配对的'('的位置, 存到pre
		pre = s.find_last_of('(', post);
		//在pre前找到正负号的位置
		sign_pos = s.find_last_of("+-", pre);
		//如果位置有效，把正负号存到sign里
		if (sign_pos != string::npos)
			sign = s.at(sign_pos);
		else
			sign = ' ';
        //把这一对括号内的内容传给calc函数，计算得一个int数
		res = calc(s.substr(pre+1, post-pre-1));
		//调整计算结果的正负号，并把该数转换为一个string
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
        //用这个string replace原来的那个式子，改变s的内容
		s.replace(pre, post-pre+1, temp);
	}
	return calc(s); //最后s内不含有括号，直接使用calc计算该式子的值
    }
int main()
{
	string s1 =  "  -  60-  (   -1-2 +  12 -(31  -5)) " ;
	fun(s1);
}
