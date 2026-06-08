/*
=========================================================
Maximum Sum Contiguous Subarray
(Return the Actual Subarray)
=========================================================

Problem:
Given an array arr[] containing positive, negative,
and zero values, return the contiguous subarray
having the maximum possible sum.

Unlike the previous problem, negative numbers
can be part of the chosen subarray.

---------------------------------------------------------

Example 1:

Input:
arr = {1, 2, 3, -2, 5}

Output:
{1, 2, 3, -2, 5}

Sum = 9

---------------------------------------------------------

Example 2:

Input:
arr = {-2,-3,4,-1,-2,1,5,-3}

Output:
{4,-1,-2,1,5}

Sum = 7

=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumSubarray(vector<int>& arr) {

        long long curSum = arr[0];
        long long maxSum = arr[0];

        int start = 0;      // temporary start
        int ansStart = 0;   // answer start
        int ansEnd = 0;     // answer end

        for (int i = 1; i < arr.size(); i++) {

            // Start new subarray
            if (arr[i] > curSum + arr[i]) {
                curSum = arr[i];
                start = i;
            }
            // Extend previous subarray
            else {
                curSum += arr[i];
            }

            if (curSum > maxSum) {
                maxSum = curSum;
                ansStart = start;
                ansEnd = i;
            }
        }

        vector<int> ans;

        for (int i = ansStart; i <= ansEnd; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};

int main() {

    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};

    Solution obj;

    vector<int> ans = obj.maxSumSubarray(arr);

    cout << "Maximum Sum Subarray: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

/*
=========================================================
Dry Run

arr = {-2,-3,4,-1,-2,1,5,-3}

Initially:

curSum = -2
maxSum = -2

--------------------------------

i=1 (-3)

max(-3,-5) = -3

curSum = -3
start = 1

maxSum remains -2

--------------------------------

i=2 (4)

max(4,1) = 4

curSum = 4
start = 2

maxSum = 4

ansStart = 2
ansEnd = 2

--------------------------------

i=3 (-1)

curSum = 3

--------------------------------

i=4 (-2)

curSum = 1

--------------------------------

i=5 (1)

curSum = 2

--------------------------------

i=6 (5)

curSum = 7

maxSum = 7

ansStart = 2
ansEnd = 6

--------------------------------

Answer:

Indices: 2 to 6

Subarray:
{4,-1,-2,1,5}

Sum = 7

=========================================================

Time Complexity:
O(N)

Space Complexity:
O(1)
(extra space excluding answer vector)

=========================================================
*/