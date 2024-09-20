class Solution {
public:
    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        // Find the longest palindromic prefix by comparing substrings
        for(int i=0; i<s.size(); i++){
            if(!memcmp(s.c_str(), revStr.c_str() + i, s.size() - i)){
                // Append the necessary part from the reversed string to make it a palindrome
                return revStr.substr(0, i)+s;
            }
        }
        // Fallback case, append the whole reversed string to the original string
        return revStr+s;
    }
};