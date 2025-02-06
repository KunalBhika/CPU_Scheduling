#include "../include/scheduling.h"
#include <algorithm>
#include <queue>

bool CompareArrivalTime(Process &a, Process &b)
{
    return a.arrival_Time < b.arrival_Time;
}

class CompareProcesses
{
public:
    bool operator()(std::pair<Process, int> &a, std::pair<Process, int> &b)
    {
        if (a.first.priority != b.first.priority)
            return a.first.priority > b.first.priority; // if priority is same execute process which arrived first
        return a.first.arrival_Time > b.first.arrival_Time;
    }
};

std::vector<Process> priorityScheduling_P(std::vector<Process> &processes) {
    std::vector<Process> result;
    std::priority_queue<std::pair<Process, int>, std::vector<std::pair<Process, int>>, CompareProcesses> pq;
    sort(processes.begin(), processes.end(), CompareArrivalTime);

    int current_time = processes[0].arrival_Time;
    int index = 0;
    int completedProcess = 0;

    while(completedProcess < processes.size()) {
        while (index < processes.size() && processes[index].arrival_Time == current_time)
        {
            pq.push({processes[index], processes[index].burst_Time});
            index++;
        }

        if(pq.empty()) {
            current_time = processes[index].arrival_Time;
            continue;
        }

        std::pair<Process, int> smallestProc = pq.top();
        pq.pop();
        smallestProc.second--;
        current_time++;

        if (smallestProc.second != 0)
            pq.push(smallestProc);
        else
        {
            // mark completed
            completedProcess++;
            smallestProc.first.completion_Time = current_time;
            smallestProc.first.turnaround_Time = smallestProc.first.completion_Time - smallestProc.first.arrival_Time;
            smallestProc.first.wait_Time = smallestProc.first.turnaround_Time - smallestProc.first.burst_Time;
            result.push_back(smallestProc.first);
        }
    }

    std::sort(result.begin() , result.end() , CompareArrivalTime);

    return result;
}