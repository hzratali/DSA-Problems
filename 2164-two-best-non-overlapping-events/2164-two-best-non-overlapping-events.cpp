class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Create a min-heap to store the ending time with value.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());
        int mxVal = 0, mxSum = 0;
        for(auto event : events){
            // Pop all valid events from queue and take their maximum.
            while(pq.size() && pq.top().first<event[0]){
                mxVal = max(mxVal, pq.top().second);
                pq.pop();
            }
            mxSum = max(mxSum, mxVal+event[2]);
            pq.push({event[1], event[2]});
        }
        return mxSum;
    }
};