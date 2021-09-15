#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) 
{
    int answer = 0, current_time = 0;
    int job_idx = 0;
    auto cmp = [](vector<int> a, vector<int> b) { return a[1] > b[1]; };

    sort(begin(jobs), end(jobs));
    priority_queue < vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    while (job_idx < jobs.size() || !pq.empty())
    {
        if (job_idx < jobs.size() && jobs[job_idx][0] <= current_time)
        {
            pq.push(jobs[job_idx++]);
            continue;
        }
        else if (!pq.empty())
        {
            // 지금 시간에 작업 시간을 더한다
            current_time += pq.top()[1];

            // 작업이 완료된 시간에서 요청 시간을 빼주면 소요시간
            auto required = current_time - pq.top()[0];
            answer += required;
            pq.pop();
        }
        // 요청 시간이 현재 시간보다 늦다면
        // 현재 시간을 요청 시간으로 갱신
        else
            current_time = jobs[job_idx][0]; 
    }
    return answer / jobs.size();
}

void print(vector<vector<int>> jobs, int answer)
{
    int a = solution(jobs);
    if (a == answer)
        printf("correct\n");
    else
        printf("wrong\n");
}

int main()
{
    print({ {0, 3}, {1, 9}, {2, 6} }, 9);
}