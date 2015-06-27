/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
        //find the index of the first not ' '
        int begin = s.find_first_not_of(" ");
        if (begin == string::npos){
            s = "";
            return;
        }
        //find the index of the first not ' '
        int end = s.find_last_not_of(" ");
        
        string ans = "";
        int cur = end;
        while (cur >= begin)
        {
            while (s[cur] != ' ' && cur >= begin)
                cur--;
            ans += s.substr(cur + 1, end-cur);
            ans += ' ';
            //skip the multiple ' 's between words
            while (s[cur] == ' ')
                cur--;
            end = cur;
        }
        ans.erase(ans.size() - 1); //erase the last ' '
        s = ans;
    }
};
