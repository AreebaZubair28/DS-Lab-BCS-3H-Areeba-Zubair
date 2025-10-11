#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Process {
    int processID;
    int priority;
};

void enqueueProcess(queue<Process> &arrivalQueue, int id, int priority) {
    Process p;
    p.processID = id;
    p.priority = priority;
    arrivalQueue.push(p);
    cout << "Process ID " << id << " with priority " << priority << " added to Arrival Queue.\n";
}

void executeProcess(stack<Process> &executionStack) {
    if (executionStack.empty()) {
        cout << "No process to execute.\n";
        return;
    }

    Process p = executionStack.top();
    executionStack.pop();
    cout << "Executing Process ID " << p.processID << " (Priority " << p.priority << ")\n";
}

void scheduleJobs(queue<Process> &arrivalQueue) {
    stack<Process> executionStack;

    cout << "\n--- Job Scheduling Started ---\n";

    while (!arrivalQueue.empty()) {
        Process current = arrivalQueue.front();
        arrivalQueue.pop();
        cout << "Dequeued Process ID " << current.processID << " (Priority " << current.priority << ")\n";

        // If stack is empty or incoming process has higher or equal priority → push
        if (executionStack.empty() || current.priority >= executionStack.top().priority) {
            executionStack.push(current);
            cout << "Pushed to Execution Stack (LIFO)\n";
        } else {
            // Execute existing high-priority process first
            cout << "Current process has lower priority than stack top. Executing stack top first...\n";
            executeProcess(executionStack);
            executionStack.push(current);
            cout << "Pushed Process ID " << current.processID << " to Execution Stack.\n";
        }
    }

    // Execute remaining processes
    cout << "\n--- Executing Remaining Processes in Stack (LIFO) ---\n";
    while (!executionStack.empty()) {
        executeProcess(executionStack);
    }
    cout << "--- Job Scheduling Completed ---\n";
}

int main() {
    queue<Process> arrivalQueue;
    int choice, id, priority;

    do {
        cout << "\n--- Job Scheduling Menu ---\n";
        cout << "1. Add Process (Enqueue)\n";
        cout << "2. Start Scheduling\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Process ID: ";
            cin >> id;
            cout << "Enter Priority: ";
            cin >> priority;
            enqueueProcess(arrivalQueue, id, priority);
            break;

        case 2:
            scheduleJobs(arrivalQueue);
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
