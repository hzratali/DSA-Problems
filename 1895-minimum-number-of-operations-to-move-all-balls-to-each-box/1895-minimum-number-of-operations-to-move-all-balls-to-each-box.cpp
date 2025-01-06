class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        for(int currBox=0; currBox<boxes.size(); currBox++){
            if(boxes[currBox] == '1'){
                for(int newPos=0; newPos<boxes.size(); newPos++) ans[newPos] += abs(newPos-currBox);
            }
        }
        return ans;
    }
};