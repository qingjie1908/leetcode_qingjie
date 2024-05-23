/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
*/
#include <vector>
int thirdMax(std::vector<int>& nums){

    //fisrt sort
    for(int i = 1; i <= (nums.size()-1); ++i){
        for(int j = 0; j <= (nums.size() - i - 1); ++j){
            if(nums[j] > nums[j+1]){
                int inter = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = inter;
            }
        }
        
    }

    //second find unique store them
    std::vector<int> vec_u = {nums[0]};
    for(int pos_u = 0, curr = 0; curr != nums.size(); ++curr){
        if(nums[pos_u] != nums[curr]){
            pos_u = curr;
            vec_u.push_back(nums[pos_u]);
        }
    }
        
    if(vec_u.size() == 1){
        return vec_u[0];
    }
    
    if(vec_u.size() == 2){
        return vec_u[1];
    }
    
    return vec_u[vec_u.size()-3];

}

int main()
{
    std::vector<int> vec1 = {2,2,3,1};
    int result = thirdMax(vec1);
    return 0;
}
//best one forjava
/*
    public int thirdMax(int[] nums) {
        Integer max1 = null;
        Integer max2 = null;
        Integer max3 = null;
        for (Integer n : nums) {
            if (n.equals(max1) || n.equals(max2) || n.equals(max3)) continue;
            if (max1 == null || n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (max2 == null || n > max2) {
                max3 = max2;
                max2 = n;
            } else if (max3 == null || n > max3) {
                max3 = n;
            }
        }
        return max3 == null ? max1 : max3;
    }
*/