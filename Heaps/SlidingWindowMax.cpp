/*
Given an integer array and the size of the sliding window - return the maximum element
in the every possible window of that size.
Approach: Maintain a max heap and every iteration, remove all max elements that are not
in the window, add the element and store the max.
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        int i,n;
        n = nums.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(i=0;i<k;i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        
        for(i=0;i<(n-k);i++)
        {
        pair<int,int> top = pq.top();
            while(top.second < (i))
            {
                pq.pop();
                top = pq.top();
            }
            res.push_back(top.first);
            pq.push(make_pair(nums[i+k],i+k));
        }
        pair<int,int> top = pq.top();
        while(top.second < (i))
            {
                pq.pop();
                top = pq.top();
            }
        res.push_back(top.first);
        return res;
    }
};