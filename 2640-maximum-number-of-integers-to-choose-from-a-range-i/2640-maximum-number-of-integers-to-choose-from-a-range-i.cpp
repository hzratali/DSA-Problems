class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(binarySearch(i, banned)) continue;
            maxSum -= i;
            if(maxSum < 0) break;
            cnt++;
        }
        return cnt;
    }
    bool binarySearch(int target, vector<int> &arr){
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int m = (l+r) / 2;
            if(arr[m] == target) return true;
            if(arr[m] > target) r = m-1;
            else l = m+1;
        }
        return false;
    }
};