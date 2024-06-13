#include <vector>
#include <iostream>

void sortColors(std::vector<int>& nums){
    size_t count_0 = 0, count_1 = 0, count_2 = 0;

    for(size_t curr = 0; curr != nums.size(); ++curr){
        switch (nums[curr])
        {
        case 0:
            ++count_0;
            break;
        case 1:
            ++count_1;
            break;
        case 2:
            ++count_2;
            break;
        default:
            break;
        }
    }

    for(size_t curr = 0; curr != nums.size(); ++curr){
        if (curr < count_0){
            nums[curr] = 0;
        } else if (curr >= count_0 && curr < count_0+count_1){
            nums[curr] = 1;
        } else {
            nums[curr] = 2;
        }
    }
}

//best one
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
