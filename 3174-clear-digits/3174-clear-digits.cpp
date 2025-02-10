// class Solution {
// public:
//     string clearDigits(string s) {
//         stack<char> st;
//         for(int i=0;i<s.length();i++){
//             if(!isdigit(s[i])){
//                 st.push(s[i]);
//             }
//             else{
//                 st.pop();
//             }
//         }
//         string ans="";
//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };

class Solution {
public:
    string clearDigits(string s) {
        string updatestr = "";
        for(int i = 0;i<s.length();i++){
            if(isdigit(s[i])){
                if(!updatestr.empty()){
                    updatestr.pop_back();
                }
            }else{
                updatestr.push_back(s[i]);
            }
        }
        return updatestr;
    }
};