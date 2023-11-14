class Solution {
    public int countPalindromicSubsequence(String s) {
        Set<Character> letters = new HashSet();
        for(Character c : s.toCharArray()) letters.add(c);
        int ans = 0;
        for(Character c : letters){
            int i=-1, j=0;
            for(int k=0; k<s.length(); k++){
                if(s.charAt(k) == c){
                    if(i == -1) i = k;
                    j = k;
                }
            }
            Set<Character> between = new HashSet();
            for(int k=i+1; k<j; k++) between.add(s.charAt(k));
            ans += between.size();
        }
        return ans;
    }
}