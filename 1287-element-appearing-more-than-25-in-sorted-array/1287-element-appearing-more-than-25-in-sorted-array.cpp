class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> cnt;
        int target = arr.size()/4;
        for(int x : arr){
            cnt[x]++;
            if(cnt[x] > target) return x;
        }
        return -1;
    }
};