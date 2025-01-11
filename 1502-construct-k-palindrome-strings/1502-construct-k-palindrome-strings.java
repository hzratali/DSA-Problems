class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        int oddCnt = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2==1) oddCnt++;
        }
        return oddCnt<=k;
    }
}