class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int mxElement = *max_element(nums.begin(), nums.end());
        vector<int> bucket(mxElement+1, 0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dis = abs(nums[i]-nums[j]);
                bucket[dis]++;
            }
        }
        for(int dist=0; dist<=mxElement; dist++){
            k -= bucket[dist];
            if(k <= 0) return dist;
        }
        return -1;
    }
};