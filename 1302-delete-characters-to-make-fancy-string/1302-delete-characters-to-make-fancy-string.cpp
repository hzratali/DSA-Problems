class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        string ans = "";
        ans.push_back(s[0]);
        int cnt = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == prev) cnt++;
            else{
                prev = s[i];
                cnt = 1;
            }
            if(cnt < 3) ans.push_back(s[i]);
        }
        return ans;
    }
};