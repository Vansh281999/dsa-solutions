/*
Problem: Maximum Manhattan Distance After All Moves
Link: https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/description/
Contest: Weekly Contest 507
Difficulty: Medium
Approach: Linear Search, maths
Time Complexity: O(n)
Note:
    
*/
class Solution {
public:
    int distance(vector<int>& a, vector<int>& b){
        int dist = abs( a[0]-b[0] ) + abs( a[1]-b[1] );
        return dist;
    }
    int maxDistance(string moves) {
        int x=0,y=0,w=0;
        for(char c :moves){
            if(c=='U'){x++;}
            else if(c=='D'){x--;}
            else if(c=='L'){y--;}
            else if(c=='R'){y++;}
            else w++;
        }
               
        return abs(x)+abs(y)+w;
    }
};
