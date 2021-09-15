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
            // ���� �ð��� �۾� �ð��� ���Ѵ�
            current_time += pq.top()[1];

            // �۾��� �Ϸ�� �ð����� ��û �ð��� ���ָ� �ҿ�ð�
            auto required = current_time - pq.top()[0];
            answer += required;
            pq.pop();
        }
        // ��û �ð��� ���� �ð����� �ʴٸ�
        // ���� �ð��� ��û �ð����� ����
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