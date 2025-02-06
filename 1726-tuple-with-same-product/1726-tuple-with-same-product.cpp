class Solution {
    int nc2(int n){
        return (n*(n-1)/2);
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;

        for(int i = 0;i<n-1;i++){
            for(int j = i + 1;j<n;j++){
                freq[nums[i] * nums[j]]++;
            }
        }
        int c = 0;
        for(auto [product,frequency] : freq){
            c += 8 * nc2(frequency);
        }
        return c;
    }
};