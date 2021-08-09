#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

//void dfs(int h, int w, vector<vector<int>>& maps)
//{
//    int w_dir[4] = { 0, 1, 0, -1 };
//    int h_dir[4] = { 1, 0, -1, 0 };
//    ++answer;    
//    visited[h][w] = true;
//    if (width - 1 == w && height - 1 == h)
//    {
//        flag = true;
//        return;
//    };
//    for (int i = 0; i < 4; ++i)
//    {
//        auto ww = w + w_dir[i];
//        auto hh = h + h_dir[i];
//        if (ww < 0 || ww >= width || hh < 0 || hh >= height) continue;            
//
//        if (false == visited[hh][ww] && maps[hh][ww])
//        {
//            dfs(hh, ww, maps);
//            //if (flag) return;
//            if (!flag) --answer;
//            else return;
//        }
//    }
//}
/*
* 1 1 1 1 1 1
* 1 0 1 0 0 1
* 1 1 1 1 0 1  
*/

//void bfs(int w, int h, vector<vector<int>>& maps)
//{
//    bool visited[100][100] = { false };
//    int answer[100][100] = { 0 };
//    int w_dir[4] = { 0, 1, 0, -1 };
//    int h_dir[4] = { 1, 0, -1, 0 };
//    answer[h][w] = 1;
//    queue<pair<int, int>> q;
//    q.push({ w, h });
//    while (!q.empty())
//    {
//        auto [cur_x, cur_y] = q.front();
//        q.pop();
//        visited[cur_y][cur_x] = true;
//        for (int i = 0; i < 4; ++i)
//        {
//            auto ww = cur_x + w_dir[i];
//            auto hh = cur_y + h_dir[i];
//            if (ww < 0 || ww >= width || hh < 0 || hh >= height) continue;            
//
//            if (false == visited[hh][ww] && maps[hh][ww])
//            {
//                answer[hh][ww] = answer[cur_y][cur_x] + 1;
//                q.push({ ww, hh });
//            }
//        }
//    }
//}

int solution(vector<vector<int> > maps)
{
    const int height = maps.size();
    const int width = maps[0].size();
    vector<vector<int>> answer(height, vector<int>(width));
    vector<vector<bool>> visited(height, vector<bool>(width));
    //int answer[100][100] = {0};
    //bool visited[100][100] = {false};
    int w_dir[4] = { 0, 1, 0, -1 };
    int h_dir[4] = { 1, 0, -1, 0 };
    answer[0][0] = 1;
    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    while (!q.empty())
    {
        auto [cur_x, cur_y] = q.front();
        q.pop();
        //visited[cur_y][cur_x] = true;
        for (int i = 0; i < 4; ++i)
        {
            auto ww = cur_x + w_dir[i];
            auto hh = cur_y + h_dir[i];
            if (ww < 0 || ww >= width || hh < 0 || hh >= height) continue;

            if (false == visited[hh][ww] && maps[hh][ww])
            {
                answer[hh][ww] = answer[cur_y][cur_x] + 1;
                visited[hh][ww] = true;
                q.push({ ww, hh });
            }
        }
    }
    if (!visited[height - 1][width - 1]) return -1;
    else return answer[height - 1][width - 1];
}

int main()
{
    auto now = chrono::high_resolution_clock::now();
    cout << solution({ {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} }) << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds result = chrono::duration_cast<chrono::nanoseconds>(end - now);
    cout << result.count() << endl;
}