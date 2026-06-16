/*
Problem: Check Good Integer
Link: https://leetcode.com/problems/check-good-integer/description/
Contest: Weekly Contest 506
Difficulty: Easy
Approach: Math
Time Complexity: O(log n)
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
};