/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
         
        int cnt1 = 0;
        int cnt2 = s.size()-1;
        while(cnt1 < cnt2)
        {
            //skip none-alphanumerical chars
            while (cnt1 < s.size() && !isalnum(s[cnt1]) )
                cnt1++;
            //skip none-alphanumerical chars
            while (cnt2 >=0 && !isalnum(s[cnt2]) )
                cnt2--;
            //when they meet, end the loop
            if (cnt1 >= cnt2)
                break;
            //if they donot meet yet, check their value, remember tolower or toupper before comparison
            if ( tolower(s[cnt1]) != tolower(s[cnt2]) )
                return false;
            //increase and decrease the index
            cnt1++;
            cnt2--;
        }
        return true;
    }
};
