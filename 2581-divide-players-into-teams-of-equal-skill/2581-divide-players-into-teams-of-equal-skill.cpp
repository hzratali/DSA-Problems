class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long n = skill.size(), ans = 0, currSum, l = 0, r = n-1, subSum = skill[0] + skill[n-1];
        while(l <= r){
            currSum = skill[l] + skill[r];
            if(currSum == subSum){
                ans += (skill[l] * skill[r]);
            }
            else return -1;
            l++;
            r--;
        }
        return ans;
    }
};