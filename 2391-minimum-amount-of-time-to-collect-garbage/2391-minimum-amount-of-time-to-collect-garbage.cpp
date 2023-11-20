class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> preSum(travel.size()+1, 0);
        preSum[1] = travel[0];
        for(int i=1; i<travel.size(); i++) preSum[i+1] = preSum[i] + travel[i];
        unordered_map<char, int> garbageLastPos, garbageCnt;
        for(int i=0; i<garbage.size(); i++){
            for(char c : garbage[i]){
                garbageLastPos[c] = i;
                garbageCnt[c]++;
            }
        }
        char garbageTypes[3] = {'M', 'P', 'G'};
        int ans = 0;
        for(char c : garbageTypes){
            if(garbageCnt[c]) ans += preSum[garbageLastPos[c]] + garbageCnt[c];
        }
        return ans;
    }
};