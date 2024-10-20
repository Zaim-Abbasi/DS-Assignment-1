// Zaim Khan Abbasi_22I-2462_Assignment 3
#include "dirTree.h"
void Menu()
{
    DirectoryTree t;

    int choice = 0;

    while (choice != 10)
    {
        cout << "\nEnter your choice: " << endl;
        cout << "1. Create a Directory/File" << endl;
        cout << "2. Merge Directory" << endl;
        cout << "3. Delete a File" << endl;
        cout << "4. Delete a Folder" << endl;
        cout << "5. Search a Directory/File" << endl;
        cout << "6. Copy/Move Files" << endl;
        cout << "7. Export to File" << endl;
        cout << "8. Import from File" << endl;
        cout << "9. Display Directory Tree" << endl;
        cout << "10. Exit\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.Create();
            break;
        case 2:
            t.Merge();
            break;
        case 3:
            t.DeleteFile();
            break;
        case 4:
            t.DeleteFolder();
            break;
        case 5:
            t.Search();
            break;
        case 6:
            t.Copy_Move();
            break;
        case 7:
            t.ExportToFile();
            break;
        case 8:
            t.ImportFromFile();
            break;
        case 9:
            t.Display();
            break;
        case 10:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}