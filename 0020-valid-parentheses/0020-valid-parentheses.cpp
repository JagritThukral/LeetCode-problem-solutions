#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        std::unordered_set<char> openBrackets = {'(','{','['};
        std::unordered_set<char> closedBrackets = {')','}',']'};
        std::unordered_map<char, char> bracketMap = {
            {'}','{'},
            {']','['},
            {')','('}
        };
        for (char c : s){
            if (openBrackets.count(c) != 0){
                st.push(c);
            } else if (closedBrackets.count(c) != 0) {
                if (st.empty()) return false;
                if (st.top() != bracketMap.at(c)) return false;
                st.pop();
            } else return false;
        }
        if (!st.empty()) return false;
        return  true;      
    }
};