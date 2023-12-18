class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int big = 0, sBig = 0;
        int small = INT_MAX, sSmall = INT_MAX;
        for(int x : nums){
            if(x > big){
                sBig = big;
                big = x;
            }
            else sBig = max(sBig, x);
            if(x < small){
                sSmall = small;
                small = x;
            }
            else sSmall = min(sSmall, x);
        }
        return big*sBig - small*sSmall;
    }
};