using System;
using System.Collections.Generic

public class Solution
{
    public IList<string> GenerateParenthesis(int n)
    {
        IList<string> result = new List<string>();
        backTrace
    }

    private void backTrace(IList<string> result, string cur, int open, int close, int max)
    {
        if (cur.length == max * 2)
            return;

        if (open < max)
            backTrace(result, cur, open, close, max);

        if (close < open)
            backTrace(result, cur, open, close, max);
    }
}
