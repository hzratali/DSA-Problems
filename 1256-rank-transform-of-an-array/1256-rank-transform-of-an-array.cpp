class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 1;
        for(int i=0; i<sortedArr.size(); i++){
            if(i>0 && sortedArr[i] > sortedArr[i-1]) rank++;
            mp[sortedArr[i]] = rank;
        }
        for(int i=0; i<arr.size(); i++) arr[i] = mp[arr[i]];
        return arr;
    }
};