class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n+1, 0);
        for(int i=1; i<=n; i++) prefixSum[i] = prefixSum[i-1] + nums[i-1];
        deque<int> ind;
        int ans = INT_MAX;
        for(int i=0; i<=n; i++){
            while(!ind.empty() && prefixSum[i]-prefixSum[ind.front()] >= k){
                ans = min(ans, i-ind.front());
                ind.pop_front();
            }
            while(!ind.empty() && prefixSum[i]<=prefixSum[ind.back()]) ind.pop_back();
            ind.push_back(i);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};