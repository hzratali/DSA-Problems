class Solution {
public:
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
    string largestGoodInteger(string num) {
        for(auto x : sameDigitNumbers){
            if(contains(x, num)) return x;
        }
        return "";
    }
    bool contains(string s, string num){
        for(int i=0; i<=num.size()-3; i++){
            if(num[i]==s[0] && num[i+1]==s[1] && num[i+2]==s[2]) return true;
        }
        return false;
    }
};