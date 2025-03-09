class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;
        int i = 0,j = 1;

        while(j < (n+k-1)){
            if(colors[j % n] == colors[(j-1) % n]){
                i = j;
                j++;
                continue;
            }if(k == (j-i+1)){
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};