class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> v;
            for(int j=l[i]; j<=r[i]; j++){
                v.push_back(nums[j]);
            }
            if(v.size() < 2){
                ans.push_back(false);
                continue;
            }
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            bool isArith = true;
            for(int j=2; j<v.size(); j++){
                if(diff != v[j]-v[j-1]){
                    isArith = false;
                    break;
                }
            }
            ans.push_back(isArith);
        }
        return ans;
    }
};