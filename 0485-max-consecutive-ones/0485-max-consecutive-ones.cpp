class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int current = 0;
        for (int x : nums) {
            if (x == 1) {
                current++;
            } else if (maxOnes) { // not already 0
                current=0;
            }
            maxOnes = std::max(maxOnes,current);
        }
        return maxOnes;
    }
};