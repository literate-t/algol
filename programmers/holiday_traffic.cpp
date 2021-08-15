#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) 
{
    int answer = 1;
    vector<pair<double, double>> new_lines;
    size_t size = lines.size();

    for (size_t i = 0; i < size; ++i)
    {
        string str = lines[i];
        int hh = stoi(str.substr(11, 2)) * 3600;
        int mm = stoi(str.substr(14, 2)) * 60;
        int ss = stoi(str.substr(17, 2));
        double mill = stoi(str.substr(20, 3)) / 1000.0;
        double end_time = hh + mm + ss + mill; // 응답완료 시간

        string temp = str.substr(24);
        double p_time = stod(temp.substr(0, temp.length() - 1));
        double start_time = end_time - p_time + 0.001;

        new_lines.push_back({ start_time, end_time });
    }

    for (size_t i = 0; i < size - 1; ++i)
    {
        int count = 1;
        double end = new_lines[i].second + 1;
        for (size_t j = i + 1; j < size; ++j)
        {
            double start = new_lines[j].first;
            if (start < end)
                ++count;
        }
        answer = answer < count ? count : answer;
    }

    return answer;
}
/*
* 완료시간 - 처리시간 + 0.001 -> 시작시간
* 1. 로그 시간 시간 중 2016-09-15가 포함된 것만 뽑기
* 2. 시작 시간 구하기
* 3. 시작 시간 ~ 완료 시간으로 배열 새로 만들기
* 4. 1s 동안 가장 많이 걸쳐져 있는 갯수 찾기. 차이가 999인 것.
* 
* 문자열을 숫자
* "2016-09-15 01:00:04.002 2.0s"
* 20:59:57.421 - 205957421
*/

int main()
{
    auto res = solution({
      "2016-09-15 01:00:04.001 2.0s",
      "2016-09-15 01:00:07.000 2s"
        });
    printf("%d\n", res);

    res = solution({
          "2016-09-15 01:00:04.002 2.0s",
          "2016-09-15 01:00:07.000 2s"
        });
    printf("%d\n", res);

    res = solution({
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s" 
        });
    printf("%d\n", res);
}