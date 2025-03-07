class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res;
        for(int i = left;i<=right;i++){
            if(i < 2) continue;
            bool isprime = true;
            for(int j = 2;j<=sqrt(i);j++){
                if(i % j == 0){
                    isprime = false;
                    break;
                }
            }
            if(isprime){
                res.push_back(i);
            }
        }

        if(res.size() < 2){
            return {-1,-1};
        }

        int mindiff = 100000;
        vector<int> result(2,-1);
        for(int i = 0;i<res.size() - 1;i++){
            int diff = res[i + 1] - res[i];
            if(diff < mindiff){
                mindiff = diff;
                result = {res[i],res[i+1]};
            }
        }
        return result;

    }
};