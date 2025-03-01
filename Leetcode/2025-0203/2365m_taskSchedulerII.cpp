// 2025/03/01 Saturday 09:50:51
// [中等] 2365. 任务调度器 II

#include <unordered_map>
#include <vector>


using namespace std;

class Solution
{
public:
  long long taskSchedulerII(vector<int>& tasks, int space)
  {
    std::unordered_map<int, long long> lastProcessedDay;
    long long day = 1;
    for (auto taskType : tasks) {
      if (lastProcessedDay.count(taskType) && (day - lastProcessedDay[taskType] <= space)) {
        day = lastProcessedDay[taskType] + space + 1;
      }
      lastProcessedDay[taskType] = day++;
    }
    return lastProcessedDay[tasks.back()];
  }
};