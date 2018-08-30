#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <utility>
using namespace std;

vector<pair<int, int> > dfs(const vector<list<int>>& graph, int source) {
    int t = 1, num_node = graph.size();
    vector<pair<int, int> > times(num_node, make_pair(0, 0));
    vector<int> status(num_node, 0);// 0- undiscovered, 1-discovered, 2-visited
    status[source] = 1;
    times[source].first = t++;
    stack<int> st;
    st.push(source);
    while(!st.empty()) {
        int curr = st.top();
        bool is_end = true;
        for (auto it = graph[curr].begin(); it != graph[curr].end(); it++) {
            if (status[*it] == 0) {
                status[*it] = 1;
                st.push(*it);
                times[*it].first = t++;
                is_end = false;
            }
        }
        if (is_end) {
            st.pop();
            times[curr].second = t++;
        }
    }
    return times;
}

int main() {
    // adjacent list
    vector<list<int>> graph = {{1, 3}, {4}, {4, 5}, {1}, {3}, {5}};
    // for (int i = 0; i < graph.size(); ++i ) {
    //     for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
    //         cout << *it << "\t";
    //     }
    //     cout << endl;
    // }
    vector<pair<int, int> > times = dfs(graph, 0);
    for (int i = 0; i < times.size(); ++i) {
        cout << times[i].first << ", " << times[i].second << endl;
    }
    system("pause");
    return 0;
}