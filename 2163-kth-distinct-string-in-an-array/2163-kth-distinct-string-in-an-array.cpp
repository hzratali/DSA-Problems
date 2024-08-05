class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinctString;
        for(int i=0; i<n; i++){
            string curr = arr[i];
            bool isDist = true;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(arr[j] == curr){
                    isDist = false;
                    break;
                }
            }
            if(isDist) distinctString.push_back(curr);
        }
        if(distinctString.size() < k) return "";
        return distinctString[k-1];
    }
};