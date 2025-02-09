class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        long long n = nums.size();
        long long totalp = (n*(n-1)) / 2;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(i < j && j - i == nums[j] - nums[i]){
                    count++;
                }
            }
        }
        return totalp-count;

    }
};