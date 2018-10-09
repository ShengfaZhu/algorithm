<!-- TOC -->

- [1. $O(n^{2})$的排序方法](#1-on^2的排序方法)
    - [1.1. 冒泡排序](#11-冒泡排序)
    - [1.2. 选择排序](#12-选择排序)
- [2. $O(nlg(n))$的排序方法](#2-onlgn的排序方法)
    - [2.1 归并排序](#21-归并排序)
    - [2.2 快速排序](#22-快速排序)
- [3. 非比较的排序方法](#3-非比较的排序方法)
    - [3.1. 计数排序](#31-计数排序)
    - [3.2. 桶排序](#32-桶排序)

<!-- /TOC -->
一维数组的排序算法使用的场合很多，在许多面试中也经常被问到(虽然我还没有被问到过)。排序算法主要有插入排序、冒泡排序、归并排序和快速排序。下面介绍的算法均按升序排序。

> 排序算法还有**稳定性**的问题，稳定的排序算法指的是原无序数组中相同元素的相对次序在排序后一定保持不变。

# 1. $O(n^{2})$的排序方法
插入排序和冒泡排序在本科生的程序设计课程中都有提及，其空间复杂度都是$O(n^{2})$。

## 1.1. 冒泡排序
冒泡排序很简单，从数组的头部开始，依次两两比较，若前面的元素比后面的元素大则交换两元素。经过一趟排序之后，最大的元素一定位于数组的尾部。各趟排序进行到无元素发生交换则停止排序。经过n趟排序后，数组一定是有序的。
```C++
void bubbleSort(vector<int>& nums) {
    bool is_change = false;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size() - i - 1; ++j)
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j+1]);
                is_change = true;
            }
        if (is_change == false)
            return;
    }
}
```
时间复杂度为$O(n^{2})$，空间复杂度为$O(1)$，且为稳定排序算法。

## 1.2. 选择排序
选择排序也很简单，从数组的头部开始遍历整个数组，找到数组的最小元素，将其与数组头部元素交换。然后再从数组的第二个元素开始遍历整个数组，找到最小元素，同样将其与数组的第二个元素交换。当进行了n-1次之后，数组必然有序。
```C++
void selectSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        unsigned int index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[index]) index = j;
        }
        if (index != i) swap(nums[index], nums[i]);
    }
}
```
时间复杂度为$O(n^{2})$，空间复杂度为$O(1)$，但是为**不稳定排序**算法。

# 2. $O(nlg(n))$的排序方法
可以将排序的时间复杂度提升到$O(nlg(n))$，代表性的排序算法有归并排序和快速排序。
## 2.1 归并排序
归并排序是一种典型的分治策略(Divide and Conquer). 算法可以分成两步:
- 分：将排序数组二分直至单个数组有序，即仅含一个元素
- 治：有有序的两个数组归并成一个有序的数组
```C++
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> L(nums.begin() + low, nums.begin() + mid + 1);
    int i = 0, j = mid + 1, k = low;
    while ((i < L.size() || j <= high) && k <= high) {
        int temp_i = INT_MAX, temp_j = INT_MAX;
        if (i < L.size()) temp_i = L[i];
        if (j <= high) temp_j = nums[j];
        if (temp_i < temp_j) {
            nums[k] = temp_i;
            k++;
            i++;
        }
        else {
            nums[k] = temp_j;
            k++;
            j++;
        }
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) >> 1;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
```
时间复杂度为$O(nlgn)$，采用了临时数组，空间复杂度为$O(n)$，但是为**稳定**排序算法。
## 2.2 快速排序

快速排序是最为强大的排序算法之一，C++ STL中的快速排序就是以快排为基础，再加上了诸多优化。

快速排序quicksort的核心是对无序向量进行快速划分，选取一个元素作为轴点(pivot)对向量进行划分，确保比轴点大的元素在轴点之后，比轴点小的元素在轴点之前，将原向量划分为两个子向量。

> **算法思想**：
> 1. 取一元素为轴点(pivot)，不妨取首元素为轴点，并将轴点的值备份；
> 2. 从向量的起始(low)和末尾(high)同时进行扫描；
> 3. 若nums[high] < pivot, 将其换到nums[low];若nums[low] > pivot,将其换到nums[high];
> 4. 当low与high位置重合后，将备份的pivot值填回nums[low].

```C++
int partition(vector<int>& nums, int low, int high) {
    // random select element as pivot
    int r = low + rand() % (high - low  + 1);
    swap(nums[r], nums[low]);
    int pivot = nums[low];// backup
    while (low < high) {
        while (low < high && pivot <= nums[high]) high--;
        nums[low] = nums[high];
        while (low < high && pivot >= nums[low]) low++;
        nums[high] = nums[low]; 
    }
    nums[low] = pivot;
    return low;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;
    int mid = partition(nums, low, high);
    quickSort(nums, low, mid);
    quickSort(nums, mid + 1, high);
}
```
时间复杂度为$O(nlgn)$，采用了临时数组，空间复杂度为$O(1)$，但是为**不稳定**排序算法。当所有元素均重复或者大量元素为重复时，上述算法会发生退化。轴点划分的两端极度不平衡，时间将退化为$O^{2}$.

# 3. 非比较的排序方法
## 3.1. 计数排序
## 3.2. 桶排序
