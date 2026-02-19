class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int j = 0,k = n;
        for (size_t i = 0; i < nums.size(); i++) {
           ans[i] = (i + 1) % 2 == 0 ? nums[k++] : nums[j++];
        }
        return ans;
    }
};