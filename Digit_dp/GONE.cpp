/*
Platform : SPOJ
Problem  : G-ONE Numbers

Statement:
A G-One number is a number whose sum of digits is a prime number.
Example:
12 -> 1 + 2 = 3
3 is prime, so 12 is a G-One number.
Given a range [f, t], count how many numbers in this range
(inclusive) are G-One numbers.
Input:
First line contains c, the number of test cases.
Each of the next c lines contains two integers:
f t
Output:
For each test case print the count of G-One numbers in [f, t].
Constraints:
1 <= c <= 100
0 <= f <= t <= 10^9
*/



#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long long dp[11][2][91];
bool prime[91];
void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= 90; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= 90; j += i)
                prime[j] = false;
        }
    }
}
long long usingmemo(string &s,unsigned int idx, int tight, int sum) {
    if(idx == s.length())
        return prime[sum];
    if(dp[idx][tight][sum] != -1)
        return dp[idx][tight][sum];
    int limit = (tight ? s[idx] - '0' : 9);
    long long ans = 0;
    for(int i = 0; i <= limit; i++) {
        ans += usingmemo(s,idx + 1,tight && (i == s[idx] - '0'),sum + i);
    }
    return dp[idx][tight][sum] = ans;
}
int main() {
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        string ri = to_string(r);
        memset(dp, -1, sizeof(dp));
        long long rightans = usingmemo(ri, 0, 1, 0);
        string li = to_string(l - 1);
        memset(dp, -1, sizeof(dp));
        long long leftans = usingmemo(li, 0, 1, 0);
        cout << rightans - leftans << endl;
    }
}

/*
Maximum digits = 10
Maximum digit sum = 10 * 9 = 90

Digit DP State:
dp[idx][tight][sum]

idx   -> current digit position
tight -> whether current prefix equals limit prefix
sum   -> digit sum accumulated so far

Base Case:
If idx == number_of_digits:
    return isPrime[sum]

Answer:
solve(t) - solve(f - 1)

Expected Complexity:
States  : 10 * 2 * 91
Transition per state : 10 digits

Time  : O(10 * 2 * 91 * 10)
Space : O(10 * 2 * 91)
*/
