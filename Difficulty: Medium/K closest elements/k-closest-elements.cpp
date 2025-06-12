class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        vector<pair<int , int>> temp ;
        for(auto i : arr){
            if(i==x){
                continue ;
            }
            temp.push_back({abs(i-x) , i});
        }
        sort(temp.begin() , temp.end() , comp);
        vector<int> ans ;
        int i = 0 ;
        while(k--){
            ans.push_back(temp[i].second);
            i++;
        }
        return ans ;
    }
    static bool comp(pair<int , int> &a , pair<int , int> &b){
        if(a.first == b.first){
            return a.second > b.second ;
        }
        return a.first < b.first ;
    }
};