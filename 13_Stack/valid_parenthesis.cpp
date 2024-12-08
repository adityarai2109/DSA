#include <bits/stdc++.h>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto i : s)
        {
            // valid entry only -> start should enter
            if ((i == '(') or (i == '[') or (i == '{'))
                st.push(i);
            else
            {
                // check all invalid cases and return 0
                // otherwise valid hence should be popped
                if (st.empty() or
                    (i == ')' and st.top() != '(') or
                    (i == '}' and st.top() != '{') or
                    (i == ']' and st.top() != '['))
                    return 0;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    FAST_IO

    return 0;
}
