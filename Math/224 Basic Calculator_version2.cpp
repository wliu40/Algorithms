class Solution {
public:
//可以计算带括号的，包含随意空格数的式子，如： "  -  60-  (   -1-2 +  12 -(31  -5))  "
    //重点：
    /////////////////////////////////////////
    //1. s.c_str()的用法
    //2.strtol(start, &end, 10)的用法;
    //3.如何巧妙使用一个栈结构来进行式子的计算
    /////////////////////////////////////////
int calculate(string s) {
    typedef long long ll;
    vector<int> signs(1, 1);
    int globalSign(1), localSign(1);
    ll ans(0);
    for (const char *x = s.c_str(); *x; x++){ // s.c_str()返回了字符串s的头字母指针，转化为一个字符数组， 当*x != nullptr时，遍历字符数组
        switch(*x)
		{
		    case ' ':
	            break;
		    case '+':
		        localSign = 1;
		        break;
	        case '-':
	            localSign = -1;
	            break;
	        case '(':
	            globalSign *= localSign;
	            signs.push_back(globalSign);
	            localSign = 1;
	            break;
	        case ')':
	            signs.pop_back();
	            globalSign = signs.back();
	            break;
	        default:
			{
	            char *end;
	            ll num = strtol(x, &end, 10); // strtol把一个str转化为long int, x是s的查找起点，end是字符型指针，end将修改为可读数字的终点
	            ans += num * globalSign * localSign;
	            x = end - 1;
	            break;
        	}
		}
    }
    return ans;
}
/*////////////////////////////////体会一下用同样思想，c++的代码，该代码用时32ms
    long long res(0);
    string::size_type pos1;
    int localSign(1), globalSign(1);
    stack<int> sk; 
    sk.push(1);
    for (int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
            case ' ':
                break;
            case '+':
                localSign = 1;
                break;
            case '-':
                localSign = -1;
                break;
            case '(':
                globalSign *= localSign;
                localSign = 1;
                sk.push(globalSign);
                break;
            case ')':
                sk.pop();
                globalSign = sk.top();
                break;
            default:
            {
                size_t pos2 = s.find_first_of(" -+", i);
                res += stoi( s.substr(i, pos2-i), &pos1 ) * localSign * globalSign;
                i = i+pos1-1;
                break;
            }
        }
    }
    return res;
*/
///////////////////////////////////////////////////////
/*
/// strtol example 
#include <stdio.h>      // printf 
#include <stdlib.h>     // strtol 

int main ()
{
  char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char * pEnd;
  long int li1, li2, li3, li4;
  li1 = strtol (szNumbers,&pEnd,10);
  li2 = strtol (pEnd,&pEnd,16);
  li3 = strtol (pEnd,&pEnd,2);
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  return 0;
}
*/
};
