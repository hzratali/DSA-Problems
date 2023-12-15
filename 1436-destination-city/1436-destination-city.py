class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> s = new HashSet();
        for(int i=0; i<paths.size(); i++) s.add(paths.get(i).get(0));
        for(int i=0; i<paths.size(); i++){
            String candi = paths.get(i).get(1);
            if(!s.contains(candi)) return candi;
        }
        return "";
    }
}