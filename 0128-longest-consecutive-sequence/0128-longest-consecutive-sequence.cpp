class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0; 
        unordered_set<int> st;
        for (int num : nums){
            st.insert(num);
        }
        for (int el : st){
            if (st.find(el-1) == st.end()){
                int count = 0;
                while (st.find(el) != st.end()){
                    count ++;
                    el++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};