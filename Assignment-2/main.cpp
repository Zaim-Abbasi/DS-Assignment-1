/*
Zaim Khan Abbasi
22I-2462
Section B
DS-Assigment-2
*/
#include "project.h"
int main()
{
    Project project;
    int choice;
    while (true)
    {
        cout << "1. Add Resources" << endl;
        cout << "2. Add Tasks" << endl;
        cout << "3. Set Task Duration" << endl;
        cout << "4. Set nth Task Duration" << endl;
        cout << "5. Print Task Dependency List" << endl;
        cout << "6. Calculate Basic Schedule" << endl;
        cout << "7. Print Critical Tasks" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            project.addResources();
            break;
        case 2:
            project.addTask();
            break;
        case 3:
            int newDuration;
            cout << "Enter new duration: ";
            cin >> newDuration;
            project.setTaskDuration(newDuration);
            break;
        case 4:
            int taskId;
            cout << "Enter task ID: ";
            cin >> taskId;
            cout << "Enter new duration: ";
            cin >> newDuration;
            if (taskId > project.numTasks || taskId < 1)
            {
                cout << "Invalid task ID!" << endl;
                break;
            }
            if (newDuration < 0)
            {
                cout << "Invalid duration!" << endl;
                break;
            }
            project.set_nth_TaskDuration(taskId, newDuration);
            break;
        case 5:
            project.printTaskDependencyList();
            break;
        case 6:
            project.calculateBasicSchedule();
            break;
        case 7:
            project.printCriticalTasks();
            break;
        case 8:
            project.Display();
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
