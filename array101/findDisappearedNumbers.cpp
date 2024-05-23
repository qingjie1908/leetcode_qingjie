/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

 

Constraints:

    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n

 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

#include <vector>
#include <map>
#include <unordered_set>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    //time limit
    // //first sort
    // for(int i = 1; i <= (nums.size() - 1); ++i){
    //     for(int j = 0; j <= (nums.size() - i - 1); ++j){
    //         if(nums[j] > nums[j+1]){
    //             int inter = nums[j+1];
    //             nums[j+1] = nums[j];
    //             nums[j] = inter;
    //         }
    //     }
    // }

    // std::vector<int> result_vec;
    // for(int wanted_value = 1; wanted_value <= nums.size(); ++wanted_value){
    //     int i = 0;
    //     for(i = 0; i < nums.size(); ++i){
    //         if(nums[i] == wanted_value){
    //             break;
    //         }
    //     }
    //     if(i == nums.size()){
    //         result_vec.push_back(wanted_value);
    //     }
    // }


    // return result_vec;

    std::unordered_set<int> set_has;
    for(auto item : nums){
        set_has.insert(item);
    }

    std::vector<int> result_vec;
    for(int wanted_value = 1; wanted_value <= nums.size(); ++wanted_value){
        if(!set_has.count(wanted_value)){
            result_vec.push_back(wanted_value);
        }
    }
    return result_vec;
}

int main()
{
    std::vector<int> vec = {4,3,2,7,8,2,3,1};
    findDisappearedNumbers(vec);
}

/*
nums = [4,3,2,7,8,2,3,1]
1. '4' is present in nums. Mark as present by negating nums[4-1] = nums[3].  Thus, nums[3] = -7
   => nums = [4,3,2,-7,8,2,3,1]
	
2. '3' is present in nums. Mark as present by negating nums[3-1] = nums[2].  Thus, nums[2] = -2
   => nums = [4,3,-2,-7,8,2,3,1]

3. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,3,1]
   
4. '7' is present in nums. Thus, nums[6] = -3
   => nums = [4,-3,-2,-7,8,2,-3,1]

5. '8' is present in nums. Thus, nums[7] = -1
   => nums = [4,-3,-2,-7,8,2,-3,-1]
   
6. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,-3,-1]   
  
7. '3' is present in nums. Thus, nums[2] = -2
   => nums = [4,-3,-2,-7,8,2,-3,-1]   

7. '1' is present in nums. Thus, nums[0] = -4
   => nums = [-4,-3,-2,-7,8,2,-3,-1]   

Now, the only elements nums[i] which are positive are those where 'i+1' is not found in nums
These are => nums[4] and nums[5].
That means 5 and 6 an not present in the initial nums array

We need to take care that some elements may already be negated. Thus, to avoid negative indexing or converting a negative element back to positive, we use abs() to get the absolute value of elements.

C++

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto c : nums)
            nums[abs(c)-1] = -abs(nums[abs(c)-1]);   // mark c is present by negating nums[c-1]
        for(int i = 0; i < size(nums); i++) 
            if(nums[i] > 0) ans.push_back(i+1);      // nums[i] > 0 means i+1 isnt present in nums
        return ans;
    }
};

*/

