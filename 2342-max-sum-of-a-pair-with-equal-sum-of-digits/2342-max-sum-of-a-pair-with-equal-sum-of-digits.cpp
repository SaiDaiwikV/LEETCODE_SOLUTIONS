class Solution {
public:
    int sumofdigits(int num){
        int s = 0;
        while(num){
            s = s + (num % 10);
            num = num / 10; 
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxsum = -1;
        for(int i = 0;i<nums.size();i++){
            int temp = sumofdigits(nums[i]);
            if(map.count(temp)){
                maxsum = max(maxsum, nums[i]+map[temp]);
                map[temp] = max(nums[i],map[temp]);
            }else{
            map[temp] = nums[i];
            }
        }
        return maxsum;
    }
};