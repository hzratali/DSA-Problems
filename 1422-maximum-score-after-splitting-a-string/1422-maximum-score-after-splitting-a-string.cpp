class Solution {
public:
    int maxScore(string s) {
        int ans = 0, zero = 0, one;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0') zero++;
            one = 0;
            for(int j=i+1; j<s.size(); j++){
                if(s[j] == '1'){
                    one++;
                }
            }
            ans = max(ans, zero+one);
        }
        return zero==s.size() ? ans-1 : ans;
    }
};