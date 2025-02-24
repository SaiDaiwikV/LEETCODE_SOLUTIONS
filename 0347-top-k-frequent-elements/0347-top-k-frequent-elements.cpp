struct cmp{
    static bool operator()(pair<int,int> i,pair<int,int> j){
        return i.second < j.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; 

        for(auto i : mp){
            pq.push({i.first,i.second});
        }

        vector<int> ans;

        for(int i = 0;i<k;i++){
            ans.push_back((pq.top().first));
            pq.pop();
        }
 return ans;
    }
   
};