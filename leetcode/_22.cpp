#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backTrack(result, "", 0, 0, n);

        return result;
    }

    void backTrack(vector<string> &result, string cur, int open, int close, int max)
    {

        // 符合条件
        // if(close == open == max)
        if (cur.length() == max * 2)
        {
            result.push_back(cur);
            return;
        }
        if (open < max)
        {
            backTrack(result, cur + '(', open + 1, close, max);
        }
        if (close < open)
        {
            backTrack(result, cur + ')', open, close + 1, max);
        }
    }
};