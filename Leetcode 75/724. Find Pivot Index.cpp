class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for(int idx=0;idx<nums.size();idx++){
            rightSum -= nums[idx];
            if(leftSum == rightSum){
                return idx;
            }
            leftSum += nums[idx];
        }
        return -1;
    }
};