/*
Problem: Filter Occupied Intervals
Link: https://leetcode.com/contest/weekly-contest-508/problems/filter-occupied-intervals/description/
Contest: Weekly Contest 508
Difficulty: Medium
Approach: Sorting, Intervals
Time Complexity: O(n log n)
Note:
    
*/
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &it : occupiedIntervals) {
            if (merged.empty() || (long long)it[0] > (long long)merged.back()[1] + 1) {
                merged.push_back(it);
            } else {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &it : merged) {
            int l = it[0], r = it[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
                continue;
            }

            // Left remaining part
            if (l < freeStart)
                ans.push_back({l, freeStart - 1});

            // Right remaining part
            if (r > freeEnd)
                ans.push_back({freeEnd + 1, r});
        }

        return ans;
    }
};