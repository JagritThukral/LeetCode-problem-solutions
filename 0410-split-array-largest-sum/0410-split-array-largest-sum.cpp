class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        long long high = 0;
        
        for (int num : nums) {
            low = max(low, num);
            high += num;
        }
        
        int ans = low;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }

private:
    bool isPossible(const vector<int>& nums, int k, long long maxSum) {
        int subarrays = 1;
        long long currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = num;
                if (subarrays > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        
        return true;
    }
};