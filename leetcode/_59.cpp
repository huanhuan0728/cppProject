#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 起始的xy
        int startx = 0, starty = 0;
        // 循环的圈数
        int loop = n / 2;
        // 给数组赋值
        int count = 0;
        // 转圈后右边界减1
        int offset = 1;
        // 结果数组
        vector<vector<int>> res(n, vector<int>(n, 0));
        // 中间元素
        int mid = n / 2;

        while (loop--)
        {
            int i = startx, j = starty;
            // 左到右
            for (j; j < n - offset; j++)
            {
                res[i][j] = ++count;
            }

            // 上到下
            for (i; i < n - offset; i++)
            {
                res[i][j] = ++count;
            }

            // 右到左
            for (; j > startx; j--)
            {
                res[i][j] = ++count;
            }

            // 下到上
            for (; i > starty; i--)
            {
                res[i][j] = ++count;
            }

            startx++;
            starty++;
            offset++;
        }

        if (n % 2)
        {
            res[mid][mid] = n * n;
        }

        return res;
    }
};