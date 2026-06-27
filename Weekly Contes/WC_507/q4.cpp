/*
Problem: Maximum Total Value
Link: https://leetcode.com/problems/maximum-total-value/description/
Contest: Weekly Contest 507
Difficulty: Hard
Approach: Binary Search
Time Complexity: O(n log M)
Note:
    
*/
class Solution {
public:
    static const long long mod = 1000000007;

    int maxTotalValue(vector<int>& nums, vector<int>& diff, int k) {
        int sz = nums.size();

        auto countTerms = [&](long long limit) {
            __int128 total = 0;

            for (int i = 0; i < sz; i++) {
                if (nums[i] < limit) continue;
                total += (nums[i] - limit) / diff[i] + 1;
            }

            return total;
        };

        __int128 totalCount = 0, totalSum = 0;

        for (int i = 0; i < sz; i++) {
            long long terms = (nums[i] - 1) / diff[i] + 1;

            totalCount += terms;
            totalSum += (__int128)terms *
                        (2LL * nums[i] - (terms - 1) * diff[i]) / 2;
        }

        if (totalCount <= k) {
            return (long long)(totalSum % mod);
        }

        long long left = 1, right = 1000000000;

        while (left < right) {
            long long mid = (left + right + 1) >> 1;

            if (countTerms(mid) >= k)
                left = mid;
            else
                right = mid - 1;
        }

        long long threshold = left;

        __int128 pickedCount = 0, pickedSum = 0;

        for (int i = 0; i < sz; i++) {
            if (nums[i] <= threshold) continue;

            long long terms = (nums[i] - threshold - 1) / diff[i] + 1;

            pickedCount += terms;
            pickedSum += (__int128)terms *
                         (2LL * nums[i] - (terms - 1) * diff[i]) / 2;
        }

        __int128 result = pickedSum + (__int128)(k - pickedCount) * threshold;

        return (long long)(result % mod);
    }
};