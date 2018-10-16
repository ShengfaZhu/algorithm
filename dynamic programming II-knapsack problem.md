# 1. 一维背包问题

> **0-1背包问题**
> 
> 给定一个载重量为$C$的背包，有$n$个物品，每个物品的重量为$w_{i}$，每个物品的价值为$v_{i}$，如何往背包中装物品使得背包中的总价值最大化。
> 
> $$\begin{matrix}
& max ~~V = \Sigma{ v_{i}x_{i}} \\
& s.t.~~\Sigma{ w_{i}x_{i}} \le C\\
& ~~~~~~~~~~x_{i}={0~or ~1} \\
\end{matrix}$$

可以用动态规划的方法对该问题进行求解。
## 1.1. 递推表达式


用$~f(i,j)~$表示前$~i~$物品中选择物品放入背包使得总重量不超过$~j~$，背包的最大总价值。因此有如下所示的递推公式：

$$
f(i, j)= 
\begin{cases}
max~[f(i-1, ~j-w_{i})+v_{i}, f(i-1,~j)] \quad & j \ge w_{k}\\ 
f(i-1,~j)\quad & j < w_{k}
\end{cases} 
$$(1)
**解释**：

背包的最大总价值$~f(i,j)~$有两种情况可以达到，一是，不放第$~i~$件物品，前$~i-1~$件物品已经把背包填满了，放不下第$i$件物品了，那该值就是$~f(i-1,~j)~$；二是，放第$~i~$件物品，那么前$~i-1~$件物品所占的空间只能是$~j-w_{i}~$，那该值就是$~f(i-1, ~j-w_{i})+v_{i}~$。因此，$~f(i,j)~$就是这两个值中的较大值。

## 1.2. 动态规划实现
```cpp
int maxValue(const std::vector<int>& weights, const std::vector<int>& values, const int& C) {
    std::vector<std::vector<int> > dp(weights.size() + 1, std::vector<int>(C + 1, 0));
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (j >= weights[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
        }
    }
    return dp[weights.size()][C];
}
```
时间复杂度为$~O(nC)~$,空间复杂度也为$~O(nC)~$。

## 1.3. 降低空间复杂度

能不能降低空间复杂度呢？答案是肯定的。再观察式(1)，可以发现$f(i,j)$的值仅和$f(i-1,*)$有关。因此可以压缩这个维度，仅用一个一维数组表示。
```cpp
int maxValue(const std::vector<int>& weights, const std::vector<int>& values, const int& C) {
    std::vector<int> dp(C + 1, 0);
    for (int i = 1; i < weights.size(); ++i) {
        // reverse order
        for (int j = C; j >= 1; --j) {
            if (j >= weights[i-1])
                dp[j] = max(dp[j], dp[j - weights[i-1]] + values[i]);
        }
    }
    return dp[C];
}
```
注意在内层循环中使用倒序，因为在dp[j]的取值会影响其后面的取值，如果从前向后遍历，则前面的值已经刷新了，会影响后面的值，因此在遍历时要采用倒序。

# 2. 二维背包问题

> **[LeetCode 474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/description/)**
> 
> For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
> 
> Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
> 

## 2.1 递归公式

以$~f(i, j, k)~$表示在前$~i~$字符串中，0不超过$~j~$个，1不超过$~k~$个条件下，最多的字符串数量。

$$
f(i, j, k)= 
\begin{cases}
max~[f(i-1, ~j-zeros_{i},~k-ones_{i})+1, f(i-1,~j,~k)] \quad & j\ge zeros_{i},~k \ge ones_{i}\\ 
f(i-1,~j,~k)\quad & others
\end{cases} 
$$(2)

同样地，可以利用二维数组实现动态规划的算法以降低空间复杂度。

```cpp
int findMaxForm(vector<string>& strs, int m, int n) {
    if (strs.empty()|| m < 0 || n < 0) return 0; 
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // dynamic programming
    for (int i = 0; i < strs.size(); i++) {
        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            if (c == '1') ones++;
        }
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
            }
        }
    }
    return dp[m][n];
}
```






