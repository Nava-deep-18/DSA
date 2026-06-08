/*
=========================================================
560. Subarray Sum Equals K
=========================================================

Problem:
Given an integer array nums and an integer k,
return the total number of continuous subarrays
whose sum equals k.

A subarray is a contiguous non-empty sequence
of elements within an array.

---------------------------------------------------------

Example 1:

Input:
nums = {1, 1, 1}
k = 2

Output:
2

Explanation:

Subarrays with sum = 2:

{1,1}  -> indices (0,1)
{1,1}  -> indices (1,2)

Answer = 2

---------------------------------------------------------

Example 2:

Input:
nums = {1, 2, 3}
k = 3

Output:
2

Explanation:

{1,2}
{3}

Answer = 2

---------------------------------------------------------

Approach (Prefix Sum + Hash Map)

Let:

prefixSum[i] =
sum of elements from index 0 to i

For a subarray (l ... r) to have sum k:

prefixSum[r] - prefixSum[l-1] = k

Therefore:

prefixSum[l-1] = prefixSum[r] - k

So while traversing:

1. Compute current prefix sum.
2. Check how many times (sum - k)
   appeared before.
3. Add that count to answer.
4. Store current prefix sum frequency.

Important:

Unlike "Longest Subarray Sum K",
here we store FREQUENCY of prefix sums,
not their first index.

=========================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int ans = 0;
        int sum = 0;

        // Empty prefix
        mp[0] = 1;

        for (int val : nums) {

            sum += val;

            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }

            mp[sum]++;
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution obj;

    cout << "Number of subarrays = "
         << obj.subarraySum(nums, k) << endl;

    return 0;
}

/*
=========================================================
Dry Run

nums = {1,1,1}
k = 2

Initially:

sum = 0
ans = 0

mp = {0 : 1}

------------------------------------------------

val = 1

sum = 1

sum-k = -1

Not found

Store:

mp[1]++

mp:
{
 0 : 1,
 1 : 1
}

------------------------------------------------

val = 1

sum = 2

sum-k = 0

Found:

mp[0] = 1

ans += 1

ans = 1

Store:

mp[2]++

mp:
{
 0 : 1,
 1 : 1,
 2 : 1
}

------------------------------------------------

val = 1

sum = 3

sum-k = 1

Found:

mp[1] = 1

ans += 1

ans = 2

Store:

mp[3]++

------------------------------------------------

Final Answer = 2

=========================================================

Why mp[0] = 1 ?

Consider:

nums = {3}
k = 3

sum = 3

sum-k = 0

We need one occurrence of prefix sum 0
before starting the array.

So:

mp[0] = 1

represents the empty prefix.

=========================================================

Time Complexity:
O(N)

Each element is processed once.

---------------------------------------------------------

Space Complexity:
O(N)

Hash map can store at most N distinct
prefix sums.

=========================================================
*/