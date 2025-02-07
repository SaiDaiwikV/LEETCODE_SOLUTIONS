class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,int> bc;
        unordered_map<int,int> cf;
        vector<int> res(n);

        for(int i = 0;i<n;i++){
            int b = queries[i][0];
            int c = queries[i][1];
            if(bc.count(b)){
                cf[bc[b]]--;
                if(cf[bc[b]] == 0){
                    cf.erase(bc[b]);
                }
            }
            bc[b] = c;
            cf[c]++;

            res[i] = cf.size();
        }
        return res;
    }
};