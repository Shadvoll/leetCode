class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> sorted_nums;
        int length = nums.size();
        int res_tmp = -1;
        vector<int> result;
        for (int i = 0; i < length; i++)
        {
            sorted_nums.push_back(pair<int, int>{nums[i], i});
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < length; i++)
        {
            res_tmp = binSearch(sorted_nums, target - sorted_nums[i].first);
            if (res_tmp != -1 && res_tmp != sorted_nums[i].second)
            {
                result.push_back(sorted_nums[i].second);
                result.push_back(res_tmp);
                break;
            }
        }
        return result;
    }
    int binSearch(vector<pair<int, int>> nums, int number)
    {
        int right = nums.size();
        int left = 0;
        int mid = (right + left) / 2;
        while (right - left > 1)
        {
            if (nums[mid].first == number)
            {
                return nums[mid].second;
            }
            if (number > nums[mid].first)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
            mid = (right + left) / 2;
        }
        if (nums[mid].first == number)
        {
            return nums[mid].second;
        }
        else
        {
            return -1;
        }
    }
};
