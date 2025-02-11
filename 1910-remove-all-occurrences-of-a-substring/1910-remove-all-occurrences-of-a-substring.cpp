class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = part.length();

        for(char ch : s){
            st.push(ch);

            if(st.size() >= n){
                string temp = "";
                for(int i = 0;i<n;i++){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(temp != part){
                    for(char c : temp){
                        st.push(c);
                    }
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};