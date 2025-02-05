class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool res = false;
        int np = 0;
        if(s1 == s2){
            res = true;
        }else{
        for(int i = 0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                np++;
            }else{
                continue;
            }
        }
        }
        if(np == 2){
            res = true;
        }
        return res;
    }
};