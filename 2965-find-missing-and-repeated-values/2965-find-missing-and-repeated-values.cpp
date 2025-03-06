class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int m = -1,r = -1;

        for(vector<int> v : grid){
            for(int i : v){
                mp[i]++;
                if(mp[i] == 2){
                    r = i;
                }
            }
        }
        for(int i = 1;i<=(grid.size() * grid.size());i++){
            if(mp[i] == 0){
                m = i;
                break;
            }
        }
       return {r,m};
    }
};