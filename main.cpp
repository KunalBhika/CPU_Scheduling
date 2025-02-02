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
        {1, 0, 5, 0, 0, 0, 0}, // P1
        {2, 2, 3, 0, 0, 0, 0}, // P2
        {3, 4, 1, 0, 0, 0, 0}, // P3
        {4, 6, 7, 0, 0, 0, 0}  // P4
    };

    inputProcesses = fcfs(inputProcesses);
    printOutput(inputProcesses);

    // Just to see the output at the terminal and hold
    int a = 0;
    cin >> a;
    // *******
    
    return 0;
}