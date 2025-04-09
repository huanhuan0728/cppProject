#ifndef SORTLXH_H
#define SORTLXH_H
#include <vector>

class SortLxh
{
public:
    virtual void sort(std::vector<int> &arr) = 0;
    virtual ~SortLxh() = default;
    // 纯虚析构函数
};

#endif