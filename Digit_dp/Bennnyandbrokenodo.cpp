/*
Platform : HackerEarth
Problem  : Benny and the Broken Odometer

Related Problems:
- LeetCode 233 : Number of Digit One
- Codeforces 1036C : Classy Numbers
- SPOJ G-ONE Numbers

Topic:
Digit DP

Difficulty:
Medium

Statement:
Digit 3 on Benny's odometer is broken.

Whenever a number contains digit 3, that number is skipped.

Examples:

Displayed Numbers:
0 1 2 4 5 6 7 8 9 10 ...

Notice that 3, 13, 23, 30, 31, ... are missing.

Given a displayed number N,
find the actual distance travelled.

Observation:
If x numbers in [0, N] contain digit 3,
then actual distance = N - x.

Therefore we only need to count numbers
containing at least one digit 3 in [0, N].
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long long dp[20][2][2];
long long usingmemo(string &s, int idx, int tight, int found) {
    if(idx == s.length())
        return found;
    if(dp[idx][tight][found] != -1)
        return dp[idx][tight][found];
    int limit = (tight ? s[idx] - '0' : 9);
    long long ans = 0;
    for(int digit = 0; digit <= limit; digit++) {
        int newfound = found || (digit == 3);
        ans += usingmemo(s,idx + 1,tight && (digit == s[idx] - '0'),newfound);
    }
    return dp[idx][tight][found] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        long long contain3 = usingmemo(num, 0, 1, 0);
        long long actualDistance = n - contain3;
        cout << actualDistance << endl;
    }
    return 0;
}

/*
Maximum digits = 19

Digit DP State:
dp[idx][tight][found]

idx   -> current digit position
tight -> whether current prefix equals limit prefix
found -> have we seen digit 3 already?

found:
0 -> No digit 3 seen yet
1 -> Digit 3 already seen

Base Case:
If idx == number_of_digits:
    return found

Transition:
newFound = found || (digit == 3)

Answer:
contain3 = solve(N)

actualDistance = N - contain3

Expected Complexity:

States:
19 * 2 * 2

Transition per state:
10 digits

Time:
O(19 * 2 * 2 * 10)

Space:
O(19 * 2 * 2)
*/