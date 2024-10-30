class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lisLen(n, 1);
        vector<int> ldsLen(n, 1);
        // Stores the length of longest increasing subsequence that ends at i.
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]) lisLen[i] = max(lisLen[i], lisLen[j]+1);
            }
        }
        // Stores the length of longest decreasing subsequence that starts at i.
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]) ldsLen[i] = max(ldsLen[i], ldsLen[j]+1);
            }
        }
        int mnRemovals = INT_MAX;
        for(int i=0; i<n; i++){
            if(lisLen[i] > 1 && ldsLen[i] > 1){
                mnRemovals = min(mnRemovals, n-lisLen[i]-ldsLen[i]+1);
            }
        }
        return mnRemovals;
    }
};