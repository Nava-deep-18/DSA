/*
=========================================================
Largest Sum Contiguous Subarray of Non-Negative Numbers
=========================================================

Problem:
Given an array arr[] consisting of positive, negative,
and zero values, find the contiguous subarray containing
only non-negative numbers that has the maximum sum.

If there are multiple such subarrays:

1. Choose the one with the maximum sum.
2. If sums are equal, choose the longer subarray.
3. If still tied, choose the one that appears first.

If no non-negative number exists, return {-1}.

---------------------------------------------------------

Example 1:
Input:
arr = {1, 2, 5, -7, 2, 3}

Output:
{1, 2, 5}

Explanation:
Subarrays containing only non-negative numbers:

{1, 2, 5} -> Sum = 8
{2, 3}    -> Sum = 5

Maximum sum is 8.

---------------------------------------------------------

Example 2:
Input:
arr = {10, 20, -30, 40, 50}

Output:
{40, 50}

Explanation:

{10,20} -> Sum = 30
{40,50} -> Sum = 90

Maximum sum is 90.

---------------------------------------------------------

Example 3:
Input:
arr = {-1, -2, -3}

Output:
{-1}

Explanation:
No non-negative subarray exists.

---------------------------------------------------------

Approach

Maintain:

cur     -> Current non-negative subarray
sum     -> Sum of current subarray

ans     -> Best subarray found so far
bestSum -> Maximum sum found so far

Whenever a negative element appears:

1. Compare current subarray with best answer.
2. Update answer if:
   - Current sum is larger
   - OR sums are equal and current length is larger
3. Reset current subarray.

After loop ends, check the last segment as well.

=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubarray(vector<int>& arr) {

        vector<int> ans;
        vector<int> cur;

        long long sum = 0;
        long long bestSum = -1;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] >= 0) {
                sum += arr[i];
                cur.push_back(arr[i]);
            }
            else {

                if (sum > bestSum ||
                   (sum == bestSum && cur.size() > ans.size())) {
                    bestSum = sum;
                    ans = cur;
                }

                cur.clear();
                sum = 0;
            }
        }

        // Check last segment
        if (sum > bestSum ||
           (sum == bestSum && cur.size() > ans.size())) {
            bestSum = sum;
            ans = cur;
        }

        if (ans.empty())
            return {-1};

        return ans;
    }
};

int main() {

    vector<int> arr = {1, 2, 5, -7, 2, 3};

    Solution obj;

    vector<int> ans = obj.findSubarray(arr);

    cout << "Answer: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

/*
=========================================================
Dry Run

arr = {1, 2, 5, -7, 2, 3}

Initially:
sum = 0
bestSum = -1

i=0
1 >= 0
sum = 1
cur = {1}

i=1
2 >= 0
sum = 3
cur = {1,2}

i=2
5 >= 0
sum = 8
cur = {1,2,5}

i=3
-7 < 0

sum = 8 > bestSum(-1)

bestSum = 8
ans = {1,2,5}

Reset:
sum = 0
cur = {}

i=4
2 >= 0
sum = 2
cur = {2}

i=5
3 >= 0
sum = 5
cur = {2,3}

Loop Ends

Last segment:
sum = 5

5 > 8 ? No

Answer:
{1,2,5}

=========================================================

Time Complexity:
O(N)

Each element is visited exactly once.

---------------------------------------------------------

Space Complexity:
O(N)

In the worst case, answer/current subarray may
store all elements.

=========================================================
*/