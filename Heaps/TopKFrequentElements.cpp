/* 
Given an integer array - return the k most occurring elements -
Approach: Maintain a map of frequencies and then insert the pairs
into a max heap - then pop the first k elements
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(),i;
        priority_queue<pair<int,int>> pq;
        map<int,int> freq;
        vector<int> res;
        for(i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(auto it=freq.begin() ; it != freq.end() ; it++)
        {
            pq.push(make_pair(it->second,it->first));
        }
        for(i=1;i<=k;i++)
        {
            pair<int,int> lol = pq.top();
            pq.pop();
            res.push_back(lol.second);
        }
        return res;
    }
};