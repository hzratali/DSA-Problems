class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for(int i=0; i<k; i++){
            int ele = pq.top(); pq.pop();
            pq.push(sqrt(ele));
        }
        long long ans = 0;
        while(!pq.empty()){
            int ele = pq.top(); pq.pop();
            ans += ele;
        }
        return ans;
    }
};