class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    static int comp(int a, int b){
        if(__builtin_popcount(a) == __builtin_popcount(b)) return a < b;
        return __builtin_popcount(a) < __builtin_popcount(b);
    }
};