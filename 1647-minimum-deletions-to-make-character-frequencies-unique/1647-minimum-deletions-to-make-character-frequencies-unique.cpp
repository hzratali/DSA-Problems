class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char c : s) v[c-'a']++;
        sort(v.begin(), v.end(), greater<>());
        int ans = 0;
        for(int i=0; i<25; i++){
            if(v[i]<=v[i+1]){
                int prev = v[i+1];
                v[i+1] = max(0, v[i]-1);
                ans += (prev - v[i+1]);
            }
        }
        return ans;
    }
};