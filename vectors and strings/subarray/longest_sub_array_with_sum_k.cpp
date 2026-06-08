/*
=========================================================
Longest Subarray with Sum K
=========================================================

Problem:
Given an array arr[] containing positive, negative, and zero values,
find the length of the longest subarray whose sum is exactly K.

Example 1:
Input:
arr = {10, 5, 2, 7, 1, 9}
k = 15

Output:
4

Explanation:
Subarray {5, 2, 7, 1} has sum = 15 and length = 4.

---------------------------------------------------------

Example 2:
Input:
arr = {-1, 2, 3}
k = 6

Output:
0

Explanation:
No subarray exists with sum = 6.

---------------------------------------------------------

Approach (Prefix Sum + Hash Map)

Let:
prefixSum[i] = sum of elements from index 0 to i.

For a subarray (l ... r) to have sum K:

prefixSum[r] - prefixSum[l-1] = K

=> prefixSum[l-1] = prefixSum[r] - K

So for every current prefix sum, we check whether
(currentSum - K) appeared earlier.

Store the FIRST occurrence of every prefix sum because
it gives the maximum possible subarray length.

=========================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<long long, int> mp;

        long long sum = 0;
        int maxi = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            // If prefix sum itself equals k
            if (sum == k) {
                maxi = i + 1;
            }

            long long rem = sum - k;

            // Check if (sum - k) existed before
            if (mp.find(rem) != mp.end()) {
                maxi = max(maxi, i - mp[rem]);
            }

            // Store first occurrence only
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxi;
    }
};

int main() {

    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    Solution obj;

    cout << "Length of longest subarray = "
         << obj.longestSubarray(arr, k) << endl;

    return 0;
}

/*
=========================================================
Dry Run

arr = {10, 5, 2, 7, 1, 9}
k = 15

i=0
sum=10
store 10 -> 0

i=1
sum=15
sum==k
maxi=2
store 15 -> 1

i=2
sum=17
rem=2 (not found)
store 17 -> 2

i=3
sum=24
rem=9 (not found)
store 24 -> 3

i=4
sum=25
rem=10 found at index 0
length = 4 - 0 = 4
maxi = 4

i=5
sum=34
rem=19 not found

Answer = 4

=========================================================

Time Complexity:
O(N)

Each element is processed once and each hash map
operation takes O(1) average time.

Space Complexity:
O(N)

Hash map may store up to N prefix sums.

=========================================================
*/