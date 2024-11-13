class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            // Assume we have picked nums[i] as the first pair element.
            // `low` indicates the number of possible pairs with sum < lower.
            int low = lower_bound(nums, i+1, nums.size()-1, lower-nums[i]);
            // `high` indicates the number of possible pairs with sum <= upper.
            int high = lower_bound(nums, i+1, nums.size()-1, upper-nums[i]+1);
            // Their difference gives the number of elements with sum in the given range.
            ans += 1LL * (high-low);
        }
        return ans;
    }
    long long lower_bound(vector<int>&nums, int l, int h, int ele){
        while(l <= h){
            int m = (l+h)/2;
            if(nums[m] >= ele) h = m-1;
            else l = m+1;
        }
        return l;
    }
};