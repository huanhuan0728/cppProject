#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "SortLxh.h"

class QuickSort : public SortLxh
{
public:
    void sort(std::vector<int> &arr) override;

private:
    void quickSort(std::vector<int> &arr, int left, int right);
    int partition(std::vector<int> &arr, int left, int right);
};

#endif // QUICK_SORT_H