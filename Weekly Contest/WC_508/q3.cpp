/*
Problem: Maximum Subarray Sum After Multiplier
Link: https://leetcode.com/contest/weekly-contest-508/problems/maximum-subarray-sum-after-multiplier/description/
Contest: Weekly Contest 508
Difficulty: Medium
Approach: Dynamic Programming
Time Complexity: O(n)
Note:
    
*/
class Solution {
public:
    long long divideVal(long long x, int k) {
        if (x >= 0) return x / k;
        return -((-x) / k);
    }

    long long solve(vector<int>& nums, int k, bool multiply) {
        const long long NEG = -(1LL << 60);

        long long before = NEG;
        long long inside = NEG;
        long long after = NEG;
        long long ans = NEG;

        for (long long x : nums) {
            long long y = multiply ? x * 1LL * k : divideVal(x, k);

            long long newBefore = max(before + x, x);

            long long newInside = max({
                y,
                before == NEG ? NEG : before + y,
                inside == NEG ? NEG : inside + y
            });

            long long newAfter = max({
                inside == NEG ? NEG : inside + x,
                after == NEG ? NEG : after + x
            });

            before = newBefore;
            inside = newInside;
            after = newAfter;

            ans = max({ans, before, inside, after});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums, k, true), solve(nums, k, false));
    }
};