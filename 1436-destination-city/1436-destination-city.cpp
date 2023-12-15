class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i=0; i<paths.size(); i++){
            string candi = paths[i][1];
            bool good = true;
            for(int j=0; j<paths.size(); j++){
                if(paths[j][0] == candi){
                    good = false;
                    break;
                }
            }
            if(good) return candi;
        }
        return "";
    }
};