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

> **排序算法的下界**
>
> 基于比较的排序方法（*在排序的最终结果中，各元素的次序依赖于它们之间的比较*）时间复杂度不会低于$\Omega(nlg~n~)$。

如果数据满足某种特殊的条件时，借助一些辅助空间可以将排序的时间复杂度在$O(n)$.
## 3.1. 计数排序
当$n$个输入均是在0~k区间内的整数时，可以用计数排序的方法在线性时间内进行排序。

首先定义一个k+1长的计数数组count，并将该数组每位都置零。然后对无序数组进行遍历，遍历到元素x时，将count[x]加一进行计数。然后再对count进行中非零的位置
```C++
// assume the number is between 0 and k
vector<int> countSort(const vector<int>& nums, int k) {
    vector<int> count(k+1, 0);
    for (int n : nums) count[n]++;
    // accumulate
    for (int i = 1; i < count.size(); ++i)  count[i] = count[i] + count[i-1];
    // put number in right position
    vector<int> sorted_num(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--) {
        sorted_num[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    return sorted_num;
}
```
计算完之后，对count进行累加，count[i]表示小于等于i的元素的数量。然后对原来的无序数组进行从末尾进行遍历，把元素放到正确的位置上，同时还保证了稳定性。

时间复杂度$O(k+n)$，空间复杂度为$O(k)$（不计输出数组所占用的空间），并且排序算法是**稳定**的。

## 3.2. 桶排序

桶排序假设输入数据服从[min, max]之间的均匀分布。
```C++
vector<double> bucketSort(vector<double> nums) {
    // find minimum and maximum number
    double M = DBL_MIN, N = DBL_MAX;
    vector<vector<double>> bucket(nums.size());
    for (double d : nums) {
        M = max(d, M);
        N = min(d, N);
    }
    // divide into n buckets
    for (double d : nums) {
        unsigned int index = (d - N) * nums.size() / (M - N);
        index = min(index, bucket.size() - 1);
        bucket[index].push_back(d);
    }
    // sort each buck with any CBA sort algorithm
    for (int i = 0; i < bucket.size(); ++i) sort(bucket[i].begin(), bucket[i].end());
    // output
    vector<double> sorted;
    for (int i = 0; i < bucket.size(); ++i)
        for (double d : bucket[i]) sorted.push_back(d);
    return sorted;
}
```
如果输入$n$个数据满足均匀分布，假设桶的数量为$m$个,平均每个桶中的数据个数为$\frac{n}{m}$。那么渐进时间复杂度为
$O(n + m\times(\frac{n}{m}lg(\frac{n}{m})))$,即$O(n + nlgn-nlgm)$，当桶的数量$m$接近数据量$n$时，时间复杂度$O(n)$。空间复杂度为$O(n)$.

应当指出，在最坏的情况下，数据分布极度集中，均分布在某一个桶中，那么时间复杂度为$\Theta(nlg~n~)$.
