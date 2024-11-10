#include <bits/stdc++.h>
using namespace std;

class Task
{
public:
    string description;
    int id;
    bool isCompleted;
    time_t createdAt;

    Task()
    {
        this->description = "";
        this->id = 0;
        this->createdAt = time(0);
        this->isCompleted = false;
    }

    Task(string description, bool is_completed = false)
    {
        this->description = description;
        this->id = rand();
        this->createdAt = time(0);
        this->isCompleted = is_completed;
    }
};

class ToDoList : public Task
{
private:
    vector<Task> tasks;

public:
    bool addTask(string description)
    {
        tasks.push_back(description);
        return true;
    }

    bool completeTask(int id)
    {
        for (auto task : tasks)
        {
            if (task.id == id)
            {
                task.isCompleted = true;
                return true;
            }
        }
        return false;
    }

    bool deleteTask(int id)
    {
        auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task &task)
                            { return task.id == id; });

        if (it == tasks.end())
        {
            return false;
        }
        tasks.erase(it, tasks.end());
        return true;
    }

    void displayTasks()
    {
        if (tasks.size() == 0)
        {
            cout << "Add task in todo list" << endl;
        }
        cout << endl;
        cout << "Todo list contents" << endl;
        for (auto task : tasks)
        {
            cout << endl;
            cout << "---------------" << endl;
            cout << "Task id: " << task.id << endl;
            cout << "Task description: " << task.description << endl;
            cout << "Task created at: " << ctime(&task.createdAt); // & because it accepts pointer to a time_t value
            cout << "Task completed: " << (task.isCompleted == 0 ? "Not completed" : "Completed") << endl;
            cout << "---------------" << endl;
            cout << endl;
        }
    }
};

int main()
{
    ToDoList todo;
    int choice;
    string description;
    int id;

    while (true)
    {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todo.addTask(description);
            break;
        case 2:
            cout << "Enter task ID to mark as complete: ";
            cin >> id;
            todo.completeTask(id);
            break;
        case 3:
            cout << "Enter task ID to delete: ";
            cin >> id;
            todo.deleteTask(id);
            break;
        case 4:
            todo.displayTasks();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}