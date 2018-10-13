# 1. 动态规划与分治
动态规划(Dynamic Programming, DP)方法常常被用来寻找最优解。类似于分治策略，将原问题分解为子问题，然后对子问题进行求解，再子问题的解综合得到原问题的解。但是用递归的算法实现分治策略时，往往和大量重复求解子问题，导致了指数级的时间复杂度。有两种方法可以避免重复求解子问题，一是在递归求解的过程中，将子问题的解记录下来，后续遇到相同子问题时，在常数时间内取出该子问题的解即可；二是采用自底而上的求解，先求解最底层的子问题，逐步向上最后综合得到原问题的解答。两种方法都是以空间换时间(time memory trade-off)

> **斐波那契数列问题**
> 
> $$\begin{matrix}
f(n)= f(n-1)+f(n-2) \\
f(0)=1,~f(1)=1
\end{matrix}$$(1)


# 1.1 递归求解
```cpp
int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n-2);
}
```
![image](https://www.google.com.hk/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwi24bLIq4LeAhXOEXAKHTZ1A9cQjRx6BAgBEAU&url=https%3A%2F%2Fnews.ebc.net.tw%2Fnews.php%3Fnid%3D115302&psig=AOvVaw2TcfXafLZuiIeBQ_1dljp7&ust=1539483086621258)

# 1.2 带记忆的递归

# 1.2 动态规划 
> 动态规划两个特征：
> - **最优子结构**：所有子结构的最优解重合得到原问题的解一定是原问题的最优解
> - **重复子问题**：需要求解的子问题中存在大量的重复，动态规划记录了子问题的解，避免重复求解子问题