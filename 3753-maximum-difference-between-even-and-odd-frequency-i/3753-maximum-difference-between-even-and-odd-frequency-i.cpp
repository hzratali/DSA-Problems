class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(char ch : s) mp[ch]++;
        int maxOdd = 1, minEven = s.size();
        for(auto& [_, value] : mp){
            if(value % 2 == 1) maxOdd = max(maxOdd, value);
            else minEven = min(minEven, value);
        }
        return maxOdd - minEven;
    }
};