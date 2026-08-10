class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int result = 1;
        if (nums.size() == 0) return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 0) continue;
            else if (nums[i] - nums[i - 1] ==  1) {
                count++;
            } else {
                count = 1;
            }
            result = max(result, count);
        }
        return result;
    }
};