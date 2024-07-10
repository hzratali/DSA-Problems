class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folderDepth = 0;
        for(auto x : logs){
            if(x == "../") folderDepth = max(0, folderDepth-1);
            else if(x != "./") folderDepth++;
        }
        return folderDepth;
    }
};