class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        string ans = "";
        while(!pq.empty()){
            ans += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};