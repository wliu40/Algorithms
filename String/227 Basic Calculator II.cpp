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
			    char *end;//����������ĩβ
			    long currentNumber = strtol(i, &end, 10); //��ǰ�������������������ŷ��ţ�
			    i = end - 1;//update ָ��i
			    
				if (multi_div == ' ')//�������Ϊ�գ���ѵ�ǰ�����з��ű任��ѹ��vector
				{
					currentNumber *= sign;//�����ű任
					v.push_back(currentNumber);
				}
				else    				
				{
				    if(multi_div == '*') //��������˺ţ��Ͱ�vector��ĩβ���뵱ǰ����ˣ���ԭ�е�ĩβ�������������½��ѹ��
				        currentNumber *= v.back();
				    else //����������ţ�����vector��ĩβ�����Ե�ǰ������ԭ�е�ĩβ�������������½��ѹ��
				        currentNumber =  v.back()/currentNumber;
					v.pop_back();//������ֵ
					v.push_back(currentNumber);//ѹ����ֵ
					multi_div = ' '; //��multi_div��Ϊ��
				}
				break;
			}
		}
	}
	for(long i :v)//��������ջ������Ӿ��������
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

