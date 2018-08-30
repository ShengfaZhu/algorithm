#include <iostream>
#include <vector>
#include <climits>
#define bigNum 1000000
using namespace std;

vector<int> min_path(const vector<vector<int>>& graph, int source) {
    int num_node = graph.size();
    vector<int> dist(num_node, bigNum);
    vector<int> status(num_node, 0);// 0-undiscovered, 1-determined
    dist[source] = 0;
    for (int i = 0; i < num_node; ++i) {
        // 找到所有未确定最短距离节点中数值最小的
        int min_temp = INT_MAX, min_id = -1;
        for (int i = 0; i < dist.size(); ++i) {
            if (status[i] == 0 && dist[i] < min_temp) {
                min_temp =  dist[i];
                min_id = i;
            }
        }
        cout << min_id << endl;
        if (min_id == -1) break;
        status[min_id] = 1;
        // 访问该节点的所有出边
        for (int j = 0; j < graph[min_id].size(); ++j) {
            if ((dist[min_id] + graph[min_id][j]) < dist[j])
                dist[j] = (dist[min_id] + graph[min_id][j]);
        }
    }
    return dist;
}

int main() {
    int num_node = 6;
    vector<vector<int>> graph(num_node, vector<int>(num_node, bigNum));
    graph[0][2] = 10;
    graph[0][4] = 30;
    graph[0][5] = 100;
    graph[1][2] = 5;
    graph[2][3] = 50;
    graph[3][5] = 10;
    graph[4][3] = 20;
    graph[4][5] = 60; 
    vector<int> dist =  min_path(graph, 0);
    for (int i : dist) cout << i << "\t";
    system("pause");
    return 0;
}