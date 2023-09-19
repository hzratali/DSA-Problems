class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int x : nums){
            int ind = abs(x);
            if(nums[ind] < 0) return ind;
            nums[ind] = -nums[ind];
        }
        return nums.size();
    }
};