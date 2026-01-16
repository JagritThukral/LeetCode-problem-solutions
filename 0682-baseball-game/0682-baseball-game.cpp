#include <stack>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto op : operations) {
            if (op == "+") {
                int el1 = st.top();
                st.pop();
                int el2 = st.top();
                st.push(el1);
                st.push(el1 + el2);
            } else if (op == "D") {
                st.push(st.top() * 2);
            } else if (op == "C") {
                st.pop();
            } else {
                st.push(stoi(op));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        } 
        return sum;
    }
};