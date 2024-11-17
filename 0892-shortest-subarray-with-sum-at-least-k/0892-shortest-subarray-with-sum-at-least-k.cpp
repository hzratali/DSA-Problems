class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        long long sum = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);
            while(!pq.empty() && sum-pq.top().first >= k){
                ans = min(ans, i-pq.top().second);
                pq.pop();
            }
            pq.emplace(sum, i);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};