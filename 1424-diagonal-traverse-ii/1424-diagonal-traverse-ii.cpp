class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int r=nums.size()-1; r>=0; r--){
            for(int c=0; c<nums[r].size(); c++){
                int diagonal = r+c;
                mp[diagonal].push_back(nums[r][c]);
            }
        }
        vector<int> ans;
        int curr = 0;
        while(mp.find(curr) != mp.end()){
            for(int num : mp[curr++]) ans.push_back(num);
        }
        return ans;
    }
};