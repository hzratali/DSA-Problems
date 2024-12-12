class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for(int i=0; i<k; i++){
            int richPileInd  = 0;
            for(int currInd=0; currInd<n; currInd++){
                if(gifts[richPileInd] < gifts[currInd]) richPileInd = currInd;
            }
            gifts[richPileInd] = sqrt(gifts[richPileInd]);
        }
        long long int ans = accumulate(gifts.begin(), gifts.end(), 0LL);
        return ans;
    }
};