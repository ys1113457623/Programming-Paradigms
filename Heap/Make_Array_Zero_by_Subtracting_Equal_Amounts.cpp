//My Solution
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(auto it:nums){
            if(it==0)continue;
            s.insert(it);
        }
        return s.size();
        // return 0;
    }
};

//Optimized
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            pq.push(nums[i]);
        }
        int move=0,curr=-1,sum=0;
        while(!pq.empty())
        {
            if(pq.top()!=curr)
            {
                move++;
                sum+=pq.top();
                curr=pq.top();
            }
            pq.pop();
        }
        return move;
    }
};