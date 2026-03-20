#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Task {
public:
    string name;
    bool completed;

    Task(string n = "", bool c = false) {
        name = n;
        completed = c;
    }
};

vector<Task> tasks;

// Save tasks to file
void saveTasks() {
    ofstream file("tasks.txt");
    for (auto &task : tasks) {
        file << task.name << "|" << task.completed << endl;
    }
    file.close();
}

// Load tasks from file
void loadTasks() {
    ifstream file("tasks.txt");
    string n;
    bool c;

    while (getline(file, n, '|')) {
        file >> c;
        file.ignore();
        tasks.push_back(Task(n, c));
    }
    file.close();
}

// Add task
void addTask() {
    string n;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, n);
    tasks.push_back(Task(n));
    cout << "Task added!\n";
}

// View tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].completed ? "Done" : "Pending") << "]\n";
    }
}

// Mark task completed
void completeTask() {
    int num;
    cout << "Enter task number to mark completed: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Menu
int main() {
    int choice;
    loadTasks();

    do {
        cout << "\n--- TO-DO LIST ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: completeTask(); break;
            case 4: saveTasks(); cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
