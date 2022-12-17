class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"I", "V", "X", "L", "C", "D", "M"};
        string str=to_string(num), res="";
        int i=0, n=str.size();

        for(int k=n-1; k>=0; k--, i+=2) {
            if(str[k]=='1')
                res = roman[i] + res;
            else if(str[k]=='2')
                res = roman[i] + roman[i] + res;
            else if(str[k]=='3')
                res = roman[i] + roman[i] + roman[i] + res;
            else if(str[k]=='4')
                res = roman[i] + roman[i+1] + res;
            else if(str[k]=='5')
                res = roman[i+1] + res;
            else if(str[k]=='6')
                res = roman[i+1] + roman[i] + res;
            else if(str[k]=='7')
                res = roman[i+1] + roman[i] + roman[i] + res;
            else if(str[k]=='8')
                res = roman[i+1] + roman[i] + roman[i] + roman[i] + res;
            else if(str[k]=='9')
                res = roman[i] + roman[i+2] + res;
        }
        return res;
    }
};