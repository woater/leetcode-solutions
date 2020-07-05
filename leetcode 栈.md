### 20. 有效的括号 

使用栈来保存前括号，当遇到后括号时，检查栈顶是否为对应的前括号，若是，则将该前括号弹出，否则匹配失败；

循环结束后检查栈是否为空，若为空，则匹配失败（即有多余前括号）。

~~~ c++
class Solution {
public:
    bool isValid(string s) {
        char popor;
		std::stack<char> st;
        std::set<char> left = {'(', '[', '{'};
        std::map<char,char> right = {   {')', '('},
                                        {']', '['},
                                        {'}', '{'}  };
        for (auto c : s) {
            if (left.find(c) != left.end()) {
                st.push(c);
            }
            else if (right.find(c) != right.end()) {
                if ((st.size() == 0) || (st.top() != right.find(c)->second)) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            else {
                //do nothing
            }
        }
        if (st.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
~~~

