class Solution {
public:
    string convert(string s, int r) {
        vector<string> v;
        int n = s.length();
        string temp;
        
        if(r==1 || r>=n)
            return s;
        
        for(int i=0; i<n; ) {
            temp="";
            
            for(int j=0; j<r; j++){
                if(i+j>=n)
                    temp+="0";
                else    
                    temp+=s[i+j];  
            }
            
            i+=r-1;
            v.push_back(temp);
            
            if(i>=n)
                break;
            
            for(int k=1; k<r-1; k++) {
                temp="";
                if(i+k>=n)
                    break;
                for(int l=0; l<r; l++) {
                    if(l==k){
                        temp+=s[i+l];
                    } else {
                        temp+="0";
                    }
                }    
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
            }
            
            i+=r-1;
        }    
        
        string res="";
        int m=v.size();
        for(int i=0; i<r; i++)
            for(int j=0; j<m; j++)
                if(v[j][i]!='0')
                    res+=v[j][i];
        
        return res;
    }
};