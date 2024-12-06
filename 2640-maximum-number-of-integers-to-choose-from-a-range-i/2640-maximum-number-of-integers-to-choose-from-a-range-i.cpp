class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0, sum = 0;
        set<int> bannedSet(banned.begin(), banned.end());
        for(int i=1; i<=n; i++){
            if(bannedSet.find(i) == bannedSet.end()){
                sum += i;
                if(sum <= maxSum) cnt++;
            }
        }
        return cnt;
    }
};