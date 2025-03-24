#include <stack>
#include <unordered_map>
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (char c : s)
        {
            // 如果是左括号
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;

                if (st.top() == '(')
                {
                    if (c == ')')
                        st.pop();
                    else
                        return false;
                }
                else if (st.top() == '{')
                {
                    if (c == '}')
                        st.pop();
                    else
                        return false;
                }
                else if (st.top() == '[')
                {
                    if (c == ']')
                        st.pop();
                    else
                        return false;
                }
            }
        }

        return st.empty();
    }
};