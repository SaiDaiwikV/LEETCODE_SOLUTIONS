class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int sl = 1,sd = 1;
        int longest = 1;

        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i - 1]){
                sl++;
            }else{
                sl = 1;
            }
            if(nums[i] < nums[i - 1]){
                sd++;
            }else{
                sd = 1;
            }
            // if(longest > sd && longest > sl){
            //     longest = longest;
            // }else if(sd > longest && sd > sl){
            //     longest = sd;
            // }else{
            //     longest = sl;
            // }
            longest = max({longest,sd,sl});
        }


        return longest;
    }
};