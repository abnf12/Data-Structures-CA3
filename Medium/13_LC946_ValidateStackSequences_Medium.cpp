class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popIdx = 0;

        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && popIdx < static_cast<int>(popped.size()) && st.top() == popped[popIdx]) {
                st.pop();
                popIdx++;
            }
        }

        return st.empty();
    }
};
