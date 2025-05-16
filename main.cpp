#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
int ssssss = 0;
void dfs(vector<vector<int>> &vec, int i, int j, int n, int m, vector<vector<int>> &temp, int sum,
         priority_queue<int, vector<int>, greater<int>> &pq, map<string, int> &mapList)
{

    if (i < 0 || j < 0 || i >= n || j >= m || temp[i][j] == 1)
    {
        return;
    }
    ssssss++;
    string key = to_string(i) + "," + to_string(j);
    if (mapList.count(key))
    {
        pq.push(mapList[key] + sum);
        return;
    } 
    if (vec[i][j] == 0)
    {
        pq.push(sum);
        return;
    }

    temp[i][j] = 1;
    dfs(vec, i, j + 1, n, m, temp, sum + 1, pq, mapList);
    dfs(vec, i + 1, j, n, m, temp, sum + 1, pq, mapList);
    dfs(vec, i, j - 1, n, m, temp, sum + 1, pq, mapList);
    dfs(vec, i - 1, j, n, m, temp, sum + 1, pq, mapList);
    temp[i][j] = 0;
    return;
}
int main()
{
    vector<vector<int>> vec = {{1, 0, 1, 0, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 0, 0, 1, 0, 1, 1}, {1, 1, 0, 0, 0, 1, 0, 1, 1, 0}};
    // vec = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
    //  vector<vector<int>> vec = {{1, 1, 1},{1, 1, 1},{1, 1, 0}};
    int n = vec.size();
    int m = vec[0].size();
    map<string, int> mapList;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[i][j] == 1)
            {
                vector<vector<int>> temp(n, vector<int>(m, 0));
                priority_queue<int, vector<int>, greater<int>> pq;
                dfs(vec, i, j, n, m, temp, 0, pq, mapList);
                string key = to_string(i) + "," + to_string(j);
                mapList[key] = pq.top();
                vec[i][j] = pq.top();
            }
        }
    }

    for (auto it : vec)
    {
        for (auto itt : it)
        {
            cout << itt << " ";
        }
        cout << endl;
    }

    cout << ssssss;
    return 0;
}

// 1011
// 1101
// 1001
