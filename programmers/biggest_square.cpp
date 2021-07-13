#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int solution(vector<vector<int>> board)
//{
//    int answer = 0;
//    int height = board.size();
//    int width = board[0].size();
//    int total = height > width ? height : width;
//    for (int i = 0; i < total; ++i)
//    {
//        int line = i + 1;
//        int start = 0;
//        bool height_flag = false;
//        bool for_flag = false;
//        int height_count = 1;
//        for (int j = 0; j < height; ++j)
//        {       
//            if (height_flag)
//                ++height_count;
//            int width_count = 0;
//            for (int k = start; k < width; ++k)
//            {
//                if (board[j][k] == 0) continue;
//               
//                ++width_count;
//                if (line == width_count && width_count == height_count)
//                {
//                    answer = answer < width_count * width_count ? 
//                        width_count * width_count : answer;                    
//                    for_flag = true;
//                    break;
//                }               
//                if (width_count == line)
//                {
//                    width_count = 0;
//                    start = k - line + 1;
//                    height_flag = true;
//                    break;
//                }
//            }
//            if (for_flag) break;
//        }
//    }
//
//    return answer;
//}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int width_size = board[0].size();
    int height_size = board.size();
    if (width_size == 1 || height_size == 1)
    {
        for (int i = 0; i < height_size; ++i)
            for (int j = 0; j < width_size; ++j)
                if (board[i][j] == 1) return 1;
    }        
    else
    {
        for (int i = 1; i < height_size; ++i)
            for (int j = 1; j < width_size; ++j)
                if (board[i][j] == 1)
                {
                    board[i][j] = min({ board[i - 1][j - 1], board[i][j - 1], board[i - 1][j] }) + 1;
                    if (board[i][j] > answer) answer = board[i][j];
                }
    }
    return answer * answer;
}

int main()
{
    cout << solution({ {0,1,1,1}, {1, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1} }) << endl;
}