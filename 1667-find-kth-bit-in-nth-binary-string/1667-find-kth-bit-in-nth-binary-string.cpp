class Solution {
public:
    char findKthBit(int n, int k) {
        string seq = "0";
        for(int i=1; i<n && k>seq.length(); i++){
            seq += '1';
            string temp = seq;
            for(int j=temp.length()-2; j>=0 ; j--){
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                seq += invertedBit;
            }
        }
        return seq[k-1];
    }
};