class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, currSum = 0;
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        while(j < nums.size()){
            int currNum = nums[j];
            int lastIndOcc = (mp.count(currNum) ? mp[currNum] : -1);
            while(i <= lastIndOcc || j-i+1 > k){
                currSum -= nums[i];
                i++;
            }
            mp[currNum] = j;
            currSum += nums[j];
            if(j - i + 1 == k) ans = max(ans, currSum);
            j++;
        }
        return ans;
    }
};