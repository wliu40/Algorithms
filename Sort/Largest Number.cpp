  /*
  Given a list of non negative integers, arrange them such that they form the largest number.

  For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

  Note: The result may be very large, so you need to return a string instead of an integer.
  */
  
struct myMethod
{
    bool operator()(const string &s1, const string &s2)
    {
    	if (s1.length() == s2.length())//if their length are same, compare directly!
    	    return s1 > s2;
    	else//if their length are different, compare which combination is larger
    	//32939 + 3294 > 3294 + 32939
    	//329393294
    	//329432939
    	//false!
    	{
    	    string temp1 = s1 + s2;
	        string temp2 = s2 + s1;
    		return temp1 > temp2;
    	}
    }
}myObject;

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
    	bool isAllZero = true;
    	vector<string> strNums(nums.size());
    	//convert all the nums to string, then we can compare the strings
    	for (int i = 0; i < nums.size(); i++)
    	{
    		strNums[i] = to_string(nums[i]);
    		if (nums[i] != 0) //check if all the elements are '0'
    			isAllZero = false;
    	}
    	if (isAllZero)
    		return "0";
        //sort the elements using the rule we defined
    	sort(strNums.begin(), strNums.end(), myObject);
    	string result;
    	for (int i = 0; i < strNums.size(); i++)
    	{
    		result += strNums[i];
    	}
    	return result;
    }

};
