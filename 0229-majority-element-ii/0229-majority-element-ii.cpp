class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        vector<int> ans;
        for(auto x : mp){
            if(x.second > floor(nums.size()/3)) ans.push_back(x.first);
        }
        return ans;
    }
};