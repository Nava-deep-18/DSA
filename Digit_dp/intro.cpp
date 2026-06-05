/*
Platform : Custom / Learning Problem

Problem  : Count Occurrences of Digit 3 in a Range

Related Problems:
- LeetCode 233 : Number of Digit One

Topic:
Digit DP

Difficulty:
Easy-Medium

Statement:
Given two integers l and r, count the total number of occurrences
of digit 3 in all numbers from l to r (inclusive).

Example:
l = 1, r = 35

Numbers containing digit 3:
3, 13, 23, 30, 31, 32, 33, 34, 35

Occurrences:
3  -> 1
13 -> 1
23 -> 1
30 -> 1
31 -> 1
32 -> 1
33 -> 2
34 -> 1
35 -> 1

Answer = 10

Constraints:
Can be as large as:
0 <= l <= r <= 10^18

Hence brute force is impossible and Digit DP is used.
*/

#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int dp[20][2][20];
int usingmemo(string &s,int idx,int tight,int cnt){
    if(idx==s.length()) return cnt;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit=(tight==1?s[idx]-'0': 9);
    int ans=0;
    for(int i=0;i<=limit;i++){
        int newcnt = cnt+(i==3?1:0);
        ans+=usingmemo(s,idx+1,tight && (i == s[idx]-'0'),newcnt);
    }
    return dp[idx][tight][cnt]=ans;
}
int main(){ 
    int l,r;
    cout<<"enter l and r seperated by spaces : ";
    cin>>l>>r;
    string ri=to_string(r);
    memset(dp,-1,sizeof(dp));
    int rightans=usingmemo(ri,0,1,0);
    string li=to_string(l-1);
    memset(dp,-1,sizeof(dp));
    int leftans=usingmemo(li,0,1,0);
    cout<<"number of 3's in range l to r is "<<rightans-leftans;
}

/*
Maximum digits = 19
Maximum count of digit 3 = 19

Digit DP State:
dp[idx][tight][cnt]

idx   -> current digit position
tight -> whether current prefix equals limit prefix
cnt   -> number of digit 3s chosen so far

Base Case:
If idx == number_of_digits:
    return cnt

Answer:
solve(r) - solve(l - 1)

Expected Complexity:
States  : 19 * 2 * 20
Transition per state : 10 digits

Time  : O(19 * 2 * 20 * 10)
Space : O(19 * 2 * 20)
*/