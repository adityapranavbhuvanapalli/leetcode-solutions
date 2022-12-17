class Solution {
    public String reverseWords(String s) {
        String[] l = s.split(" ");
        s="";
        for(int i=0; i<l.length-1; i++) {
            if(l[l.length-1-i]!="")
                s+=(l[l.length-1-i]);
            if(l[l.length-2-i]!="")
                s+=" ";
        }
            
        
        if(l[0]!="")
            s+=(l[0]);
            
        return s;
    }
}