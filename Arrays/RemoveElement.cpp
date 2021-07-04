/* In-place means that the algorithm does not use extra space for manipulating the input
    but may require a small constant extra space may be used for variables.
    Given an array of integers and a target value, shift all occurrences of that value to the end of the array
    - does not matter what the end is, just shift the other values to the first part - return (size - occurrences)
    Approach - Maintain two pointers - if one of them equals target value, keep moving it, when it isnt,
    switch up the values of the two pointers till exit condition
*/
//My Solution - 
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = nums.size();
        if (count == 0)
            return 0;
        else if (count == 1)
        {
            if (nums[0] == val)
                return 0;
            else
                return 1;
        }
        auto start = nums.begin();
        auto end = nums.end() - 1;
        int buf;

        while (start != end)
        {
            if (*start == val)
            {
                if (*end == val)
                {
                    end--;
                    count--;
                    continue;
                }
                buf = *start;
                *start = *end;
                *end = buf;
                end--;

                if (start == end)
                {
                    count--;
                    break;
                }
                start++;
                count--;
            }
            else
                start++;
        }
        if (start == end && *start == val)
            count--;
        return count;
    }
};

//LC Solution
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for (; j < n; j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};