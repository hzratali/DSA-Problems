class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        for(char c : s) str += to_string(c-'a'+1);
        while(k-- > 0){
            int digitSum = 0;
            for(char digit : str) digitSum += digit-'0';
            str = to_string(digitSum);
        }
        return stoi(str);
    }
};