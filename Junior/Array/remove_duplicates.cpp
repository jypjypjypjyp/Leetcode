#include"main.h"

int RemoveDuplicates(std::vector<int> &nums)
{
    int i = !nums.empty();
    for (int n : nums)
        if (n > nums[i - 1])
            nums[i++] = n;
    return i;
}
