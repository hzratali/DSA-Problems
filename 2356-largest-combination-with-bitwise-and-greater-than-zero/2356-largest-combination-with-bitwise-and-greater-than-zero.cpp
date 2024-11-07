class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCnt(24, 0);
        for(int i=0; i<24; i++){
            for(int num : candidates){
                if((num & (1<<i)) != 0) bitCnt[i]++;
            }
        }
        return *max_element(bitCnt.begin(), bitCnt.end());
    }
};