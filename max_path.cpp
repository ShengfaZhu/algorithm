// number of max_path
#include <iostream>
#include <vector>
using namespace std;

int count(vector<vector<int>> matrix, int n, vector<int>& path) {
    if (path[n] != -1) return path[n];
    int num = 0;
    for (int i = 0; i < matrix[n].size(); ++i) {
        if (matrix[n][i] != 0) {
            num += count(matrix, i, path) + 1;
        }
    }
    path[n] = num;
    return num;
}

int maxpath(int node, vector<vector<int>> edge){
    vector<int> path(node, -1);
    vector<vector<int>> matrix(node, vector<int>(node, 0));
    for (int i = 0; i < edge.size(); ++i) {
        matrix[edge[i][0]][edge[i][1]] = 1;
    }
    int ans = 0;
    for (int i = 0; i < node; ++i) {
        int temp = count(matrix, i, path);
        cout << temp << "\t";
        ans = max(temp, ans);
    }
    return ans;
}

int main()
{
    // int node, row, col;
    // cin >> node >> row >> col;
    // vector<vector<int>> edge(row, vector<int>(col, 0));
    // for (int i = 0; i < row; ++i) {
    //     for (int j = 0; j < col; ++j) {
    //         cin >> edge[i][j];
    //     }
    // }
    int node = 4;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {2, 1}, {3, 2}};
    cout << maxpath(node, edge);
    system("pause");
    return 0;
}
