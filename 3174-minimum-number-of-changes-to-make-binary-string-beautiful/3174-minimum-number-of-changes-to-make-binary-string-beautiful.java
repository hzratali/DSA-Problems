class Solution {
    public int minChanges(String s) {
        char currChar = s.charAt(0);
        int cnt = 0, ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == currChar){
                cnt++;
                continue;
            }
            if(cnt%2 == 0) cnt = 1;
            else{
                cnt = 0;
                ans++;
            }
            currChar = s.charAt(i);
        }
        return ans;
    }
}