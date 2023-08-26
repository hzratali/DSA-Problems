class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 0, curr=INT_MIN;
        for(auto x : pairs){
            if(x[0] > curr){
                cnt++;
                curr = x[1];
            }
        }
        return cnt;
    }
};