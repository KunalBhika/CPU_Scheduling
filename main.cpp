#include <bits/stdc++.h>
#include "./include/scheduling.h"
using namespace std;

void printOutput(vector<Process> &inputProcesses)
{
    for (int i = 0; i < inputProcesses.size(); i++)
    {
        cout << inputProcesses[i].process_id << "\t";
        cout << inputProcesses[i].completion_Time << "\t";
        cout << inputProcesses[i].turnaround_Time << "\t";
        cout << inputProcesses[i].wait_Time << "\t";
        cout << endl;
    }
}

int main()
{
    vector<Process> inputProcesses = {
        {1, 0, 5, 3, 0, 0, 0}, // P1 (Priority 3)
        {2, 2, 3, 1, 0, 0, 0}, // P2 (Priority 1 - Highest)
        {3, 4, 1, 4, 0, 0, 0}, // P3 (Priority 4 - Lowest)
        {4, 6, 7, 2, 0, 0, 0}  // P4 (Priority 2)
    };

    inputProcesses = priorityScheduling_P(inputProcesses);
    printOutput(inputProcesses);

    // Just to see the output at the terminal and hold
    int a = 0;
    cin >> a;
    // *******

    return 0;
}