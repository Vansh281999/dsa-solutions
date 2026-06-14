/*
Problem: Check Good Integer©leetcode
Link: https://leetcode.com/contest/weekly-contest-506/problems/check-good-integer/
Contest: Weekly Contest 505
Difficulty: Easy
Approach: Linear Search, maths
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds=0,ss=0;

        while(n>0){
            int d = n%10;
            ds+=d;
            ss+=d*d;
            n/=10;
        }
        return (ss-ds)>=50;
    }
};©leetcode
