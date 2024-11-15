class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int r = arr.size()-1;
        while(r>0 && arr[r] >= arr[r-1]) r--;
        int ans = r, l = 0;
        while(l<r && (l==0 || arr[l-1] <= arr[l])){
            //Find next valid number after arr[l]
            while(r<arr.size() && arr[l] > arr[r]) r++;
            //save length of removed subarray
            ans  = min(ans, r-l-1);
            l++;
        }
        return ans;
    }
};