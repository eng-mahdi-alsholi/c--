#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> vec = {
        {1, 0, 1, 0, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 0, 0, 1, 0, 1, 1}, {1, 1, 0, 0, 0, 1, 0, 1, 1, 0}};
    vec = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

    vec = {{1, 1, 1}, {1, 1, 1}, {1, 1, 0}};
    //
    //    vec = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
    //           {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    //           {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    //           {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    //           {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

    int n = (int)vec.size();
    int m = (int)vec[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<vector<int>> visited(n, vector<int>(m, 0));
            queue<pair<int, int>> qa;
            qa.push({i, j});
            visited[i][j] = 1;
            pair<int, int> top;

            while (!qa.empty())
            {
                top = qa.front();
                qa.pop();
                int iTop = top.first;
                int jTop = top.second;
                if (vec[iTop][jTop] == 0)
                {
                    vec[i][j] = abs(iTop - i) + abs(jTop - j);
                    break;
                }
                // top
                if (!(iTop + 1 >= n) && visited[iTop + 1][jTop] == 0)
                {
                    qa.push({iTop + 1, jTop});
                    visited[iTop + 1][jTop] = 1;
                }
                // bottom
                if (!(iTop - 1 < 0) && visited[iTop - 1][jTop] == 0)
                {
                    qa.push({iTop - 1, jTop});
                    visited[iTop - 1][jTop] = 1;
                }
                // right
                if (!(jTop + 1 >= m) && visited[iTop][jTop + 1] == 0)
                {
                    qa.push({iTop, jTop + 1});
                    visited[iTop][jTop + 1] = 1;
                }
                // left
                if (!(jTop - 1 < 0) && visited[iTop][jTop - 1] == 0)
                {
                    qa.push({iTop, jTop - 1});
                    visited[iTop][jTop - 1] = 1;
                }

            } // end while

        } // end for1
    } // end for2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

// 1011
// 1101
// 1001
