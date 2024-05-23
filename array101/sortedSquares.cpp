/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

*/

#include <vector>
#include <functional>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    for(auto &item : nums){
        item *= item;
    }
    
    std::sort(nums.begin(), nums.end());
    
    return nums;
}

//best one
/*
Now, we can have two pointers l to left most element, r to most right element.
Create res result array same size as A.
Move from right to left in res and past max(abs(A[l]), abs(A[r])), move correspondingly l++ or r--.


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};
*/