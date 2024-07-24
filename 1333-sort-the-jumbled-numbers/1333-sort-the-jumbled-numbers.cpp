class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++){
            string num = to_string(nums[i]);
            string formed = "";
            for(int j=0; j<num.size(); j++){
                formed += (to_string(mapping[num[j]-'0']));
            }
            int mappedValue = stoi(formed);
            vp.push_back({mappedValue, i});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans;
        for(auto pair : vp) ans.push_back(nums[pair.second]);
        return ans;
    }
};