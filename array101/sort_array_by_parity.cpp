#include <vector>

std::vector<int> sortArrayByParity(std::vector<int>& nums)
{
    //two pointer, one for even value pos, one for vector traverse
    decltype(nums.size()) even_pos = 0, curr = 0;
    while(curr != nums.size()){
        if(nums[curr]%2){ //odd value, move on to find even value
            ++curr;
        } else{ //even value, update 
            int inter = nums[even_pos];
            nums[even_pos] = nums[curr];
            nums[curr] = inter;
            ++even_pos;
            ++curr;
        }
    }
    return nums;
}

int main()
{
    std::vector<int> case1 = {3,1,2,4};
    

    //std::vector<int> &nums = case1;
    std::vector<int> result;
    result = sortArrayByParity(case1);
}