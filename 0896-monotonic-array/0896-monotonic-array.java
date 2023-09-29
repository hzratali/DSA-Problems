class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing=true, decreasing=true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) decreasing = false;
            if(nums[i] < nums[i-1]) increasing = false;
            if(!increasing && !decreasing) return false;
        }
        return true;
    }
};