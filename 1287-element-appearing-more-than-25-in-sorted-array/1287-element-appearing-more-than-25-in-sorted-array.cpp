class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int x : arr) cnt[x]++;
        int target = arr.size()/4;
        for(auto &[key, val] : cnt){
            if(val > target) return key;
        }
        return -1;
    }
};