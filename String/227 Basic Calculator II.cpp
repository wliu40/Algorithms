#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int calculate(string s) {
    int sign = 1;
	char multi_div = ' ';
	long currentNumber, res(0);
	vector<long int> v;
	for (const char *i = s.c_str(); *i; ++i)
	{
		switch (*i)
		{
			case ' ':
				break;
			case '+':
				sign = 1;
				break;
			case '-':
				sign = -1;
				break;
			case '*':
				multi_div = '*';
				break;
			case '/':
				multi_div = '/';
				break;
			default:
			{
			    char *end;//读到的数的末尾
			    long currentNumber = strtol(i, &end, 10); //当前遇到的数（不带正负号符号）
			    i = end - 1;//update 指针i
			    
				if (multi_div == ' ')//如果符号为空，则把当前数进行符号变换后压入vector
				{
					currentNumber *= sign;//正负号变换
					v.push_back(currentNumber);
				}
				else    				
				{
				    if(multi_div == '*') //如果遇到乘号，就把vector的末尾数与当前数相乘，把原有的末尾数弹出，并将新结果压入
				        currentNumber *= v.back();
				    else //如果遇到除号，就用vector的末尾数除以当前数，把原有的末尾数弹出，并将新结果压入
				        currentNumber =  v.back()/currentNumber;
					v.pop_back();//弹出旧值
					v.push_back(currentNumber);//压入新值
					multi_div = ' '; //把multi_div置为空
				}
				break;
			}
		}
	}
	for(long i :v)//把所有入栈的数相加就是最后结果
	{
		res += i;
	}
	return res;
}
int main()
{
	string s = " 1 *2 -3  *4/2 +1 ";
	cout << calculate(s) << endl;
}

