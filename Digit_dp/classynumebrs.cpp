/*
Platform : Codeforces
Problem  : 1036C - Classy Numbers

Related Problems:
- SPOJ G-ONE Numbers
- LeetCode 902 : Numbers At Most N Given Digit Set
- LeetCode 2719 : Count of Integers

Topic:
Digit DP

Difficulty:
Medium

Statement:
A number is called Classy if it contains at most
3 non-zero digits.

Given q queries, each containing l and r,
count how many Classy Numbers exist in the range
[l, r].

Examples:
1002  -> Classy (2 non-zero digits)
70009 -> Classy (2 non-zero digits)
1234  -> Not Classy (4 non-zero digits)

Constraints:
1 <= q <= 10^4
1 <= l <= r <= 10^18

Brute force is impossible because the range can
contain up to 10^18 numbers.

Hence Digit DP is required.
*/

#include <iostream>
#include<string>
#include<cstring>
using namespace std;
long long dp[20][2][20];
long long usingmemo(string &s,int idx,int tight,int cnt){
    if(cnt>3) return 0;
    if(idx==s.length()) return cnt<=3;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit=(tight==1?s[idx]-'0': 9);
    long long ans=0;
    for(int i=0;i<=limit;i++){
        int newcnt = cnt+(i!=0?1:0);
        ans+=usingmemo(s,idx+1,tight && (i == s[idx]-'0'),newcnt);
    }
    return dp[idx][tight][cnt]=ans;
}
int main(){ 
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        string ri=to_string(r);
        memset(dp,-1,sizeof(dp));
        long long rightans=usingmemo(ri,0,1,0);
        string li=to_string(l-1);
        memset(dp,-1,sizeof(dp));
        long long leftans=usingmemo(li,0,1,0);
        cout<<rightans-leftans<<endl;
    }
}

/*
Maximum digits = 19

Digit DP State:
dp[idx][tight][cnt]

idx   -> current digit position
tight -> whether current prefix equals limit prefix
cnt   -> number of non-zero digits used so far

Pruning:
If cnt > 3:
    return 0

Base Case:
If idx == number_of_digits:
    return 1

Answer:
solve(r) - solve(l - 1)

Expected Complexity:

States:
19 * 2 * 4

Transition per state:
10 digits

Time:
O(19 * 2 * 4 * 10)

Space:
O(19 * 2 * 4)

Observation:
Only cnt = 0,1,2,3 are useful because
cnt > 3 is immediately discarded.
*/