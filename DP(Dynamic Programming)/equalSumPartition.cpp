//MY SOLUTION
https://leetcode.com/problems/partition-equal-subset-sum/submissions/868591457/

class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        bool subset[arr.size()+1][sum+1];
        
        for(int i=0;i<=arr.size();i++){
            subset[i][0] = true;
        }
        for(int j=1;j<=sum;j++){
            subset[0][j] = false;
        }
        
        
        
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=sum;j++){
                if(j >= arr[i-1]){
                    subset[i][j] = subset[i-1][j-arr[i-1]] || subset[i-1][j];
                }
                else{
                    subset[i][j] = subset[i-1][j];
                }
            }
        }
        
        return subset[arr.size()][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        if(sum%2!=0){
            return false;
        }
        else if(sum%2==0){
            return isSubsetSum(nums,sum/2);
        }

        return false;
    }
};

//OPTIMAL SOLUTION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        constexpr int sz = 200*100+1;
        bitset<sz> bits(1);
        int sum = 0;
        for(int n:nums){
            sum+=n;
            bits |= bits<<n;
        }
        return sum%2==0&&bits[sum/2];
    }
};