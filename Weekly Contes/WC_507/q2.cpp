/*
Problem: Valid Subarrays With Matching Sum Digits I
Link: https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
Contest: Weekly Contest 507
Difficulty: Easy
Approach: Brute Force, Prefix Sum
Time Complexity: O(n^2)
Note:
    
*/
class Solution {
public:
    int first_d(long long x)
    {
        long long a=x;
        while(a>=10){
            a/=10;
        }
        return a;
    }    
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long sum = pref[j+1]-pref[i];
                if(sum%10==x && first_d(sum)==x){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};