class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int n = word1.length, m = word2.length;
        int i=0, j=0, x=0, y=0;
        while(i<n && j<m){
            if(word1[i].charAt(x++) != word2[j].charAt(y++)) return false;
            if(word1[i].length() == x){
                i++;
                x=0;
            }
            if(word2[j].length() == y){
                j++;
                y= 0;
            }
        }
        return i==n && j==m;
    }
}