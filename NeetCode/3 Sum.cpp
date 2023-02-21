class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target = 0;
        set<vector<int>> a;
        vector<vector<int>> output;
        for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    a.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        for(auto i:a){
            output.push_back(i);
        }

        return output;
    }
};