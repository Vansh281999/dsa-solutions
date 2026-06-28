/*
Problem: Maximum Total Sum of K Selected Elements
Link: https://leetcode.com/contest/weekly-contest-508/problems/maximum-total-sum-of-k-selected-elements/
Contest: Weekly Contest 508
Difficulty: Medium
Approach: Sorting, Greedy
Time Complexity: O(n log n)
Note:
    
*/
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        vector<long long> selec(k);
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=n-1;i>=0;i--){
            if(j<k){
                if(nums[i]>0){
                    selec[j]=nums[i];
                    j++;
                }
            }
        }
        long long max_sum=0;
        j=0;
        while(mul>0 && j<k){
            max_sum+=selec[j++]*mul--;
        }
        while(j<k){
            max_sum+=selec[j++];
        }
        return max_sum;
    }
};