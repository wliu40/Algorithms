#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
void show(vector<int> v)
{
	for(int num:v){
		cout << num << " ";
	}
	cout << endl;
}
vector<int> recursiveSolver(string input, unordered_map<string, vector<int> > &mp)
    { 
    //如果说能在mp中找到该子式子所得的vector,那么就直接返回该vector, 否则需要计算该子式子的结果
        if ( mp.find(input) != mp.end() )
            return mp[input];
        vector<int> result;
        for(int i = 0; i < input.size(); i++)
        {
            char c = input[i];
            if (c == '*' || c == '+' || c == '-')
            {
				
                vector<int> result1 = recursiveSolver(input.substr(0, i), mp);
                cout << "input: " << input << " :: ";
                show(result1);
                vector<int> result2 = recursiveSolver(input.substr(i+1), mp);
                cout << "input: " << input << " :: ";
                show(result2);
                for(int num1 : result1){
                    for (int num2 : result2){
                        if(c == '+')
                            result.push_back(num1+num2);
                        else if (c == '-')
                            result.push_back(num1-num2);
                        else
                            result.push_back(num1*num2);
                    }
                }

            }

        }
        if (result.empty())
            result.push_back(stoi(input));
            mp[input] = result;
        return result;
    }
    vector<int> diffWaysToCompute(string input) 
    {
        unordered_map<string, vector<int> > mp;
        return recursiveSolver(input, mp);
    }

int main()
{	
	string s = "2*3-4*5+6";
	vector<int> v = diffWaysToCompute(s);
	for(int i : v)
		cout << i << " ";
}
