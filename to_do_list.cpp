#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold task information
struct Task {
    string description;
    bool completed;
};

// Function to add a new task
void addTask(vector<Task> &tasks, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false; // New tasks are not completed by default
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to remove a task by its description
void removeTask(vector<Task> &tasks, const string &description) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->description == description) {
            cout << "Removing task: " << it->description << endl;
            tasks.erase(it);
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Function to mark a task as completed
void completeTask(vector<Task> &tasks, const string &description) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->description == description) {
            it->completed = true;
            cout << "Task completed: " << description << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Function to edit a task's description
void editTask(vector<Task> &tasks, const string &oldDescription, const string &newDescription) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->description == oldDescription) {
            it->description = newDescription;
            cout << "Task description updated to: " << newDescription << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Function to search for a task by description
void searchTask(const vector<Task> &tasks, const string &description) {
    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->description == description) {
            cout << "Task found: " << description << ", Completed: " << (it->completed ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Function to list all tasks
void listTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }
    cout << "To-Do List:" << endl;
    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        cout << (it->completed ? "[X] " : "[ ] ") << it->description << endl;
    }
}

// Function to list only completed tasks
void listCompletedTasks(const vector<Task> &tasks) {
    bool found = false;
    cout << "Completed Tasks:" << endl;
    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->completed) {
            cout << it->description << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No completed tasks." << endl;
    }
}

// Function to list only pending tasks
void listPendingTasks(const vector<Task> &tasks) {
    bool found = false;
    cout << "Pending Tasks:" << endl;
    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (!it->completed) {
            cout << it->description << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No pending tasks." << endl;
    }
}

int main() {
    vector<Task> tasks;
    string description, newDescription;
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. Remove Task\n3. Complete Task\n4. Edit Task\n5. Search Task\n6. List Tasks\n7. List Completed Tasks\n8. List Pending Tasks\n9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();  // To ignore the leftover newline character in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                cout << "Enter task description to remove: ";
                getline(cin, description);
                removeTask(tasks, description);
                break;
            case 3:
                cout << "Enter task description to mark as completed: ";
                getline(cin, description);
                completeTask(tasks, description);
                break;
            case 4:
                cout << "Enter old task description: ";
                getline(cin, description);
                cout << "Enter new task description: ";
                getline(cin, newDescription);
                editTask(tasks, description, newDescription);
                break;
            case 5:
                cout << "Enter task description to search: ";
                getline(cin, description);
                searchTask(tasks, description);
                break;
            case 6:
                listTasks(tasks);
                break;
            case 7:
                listCompletedTasks(tasks);
                break;
            case 8:
                listPendingTasks(tasks);
                break;
            case 9:
                cout << "Exiting. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

