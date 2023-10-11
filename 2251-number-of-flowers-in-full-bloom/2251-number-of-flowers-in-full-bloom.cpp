class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());
        sort(flowers.begin(), flowers.end());
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        for(int person : sortedPeople){
            while(i<flowers.size() && flowers[i][0] <= person){
                pq.push(flowers[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < person) pq.pop();
            mp[person] = pq.size();
        }
        vector<int> ans;
        for(int person : people) ans.push_back(mp[person]);
        return ans;
    }
};