class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;

        for(int i : nums){
            if(i < pivot){
                v1.push_back(i);
            }
        }

        for(int i : nums){
            if(i == pivot){
                v2.push_back(i);
            }
        }

        for(int i : nums){
            if(i > pivot){
                v3.push_back(i);
            }
        }
        
        for(int i : v2){
            v1.push_back(i);
        }
        for(int i : v3){
            v1.push_back(i);
        }

        return v1;

        
    }
};