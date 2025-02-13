class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums) {
            if (num < k) pq.push(num);
        }
        
        int operations = 0;
        
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            operations++;
            
            if (pq.empty()) break;
            
            int y = pq.top(); pq.pop();
            long long newValue = 2LL * x + y;
            
            if (newValue < k) pq.push(static_cast<int>(newValue));
        }
        
        return operations;
    }
};
