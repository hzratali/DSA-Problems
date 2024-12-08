class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return f(events, 0, 0, dp);
    }
    int f(vector<vector<int>>&events, int idx, int cnt, vector<vector<int>>&dp){
        if(cnt == 2 || idx >= events.size()) return 0;
        if(dp[idx][cnt] == -1){
            int end = events[idx][1];
            int low = idx+1, high = events.size()-1;
            while(low < high){
                int mid = (low + high)/2;
                if(events[mid][0] > end) high = mid;
                else low = mid + 1;
            }
            int include = events[idx][2] + (low < events.size() && events[low][0] > end ? f(events, low, cnt+1, dp) : 0);
            int exclude = f(events, idx+1, cnt, dp);
            dp[idx][cnt] = max(include, exclude);
        }
        return dp[idx][cnt];
    }
};