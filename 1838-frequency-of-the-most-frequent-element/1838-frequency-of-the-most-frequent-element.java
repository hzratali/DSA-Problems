class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, ans = 0;
        long curr = 0;
        for(int r=0; r<nums.size(); r++){
            long target = nums[r];
            curr += target;
            while((r-l+1)*target-curr > k) curr -= nums[l++];
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};