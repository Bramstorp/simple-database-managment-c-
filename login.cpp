#include <iostream>
#include <sqlite3.h>
#include <limits>

using namespace std;

void managementMenu(sqlite3 *db);
bool createDatabase(sqlite3 *db);
int userMenu();

int main()
{
    if (userMenu() == 1)
    {
        sqlite3 *db = nullptr;
        int exit = sqlite3_open("example.db", &db);
        if (exit)
        {
            cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
            return 1;
        }
        else
        {
            cout << "Opened database successfully." << endl;
            if (!createDatabase(db))
            {
                cerr << "Failed to create database." << endl;
                sqlite3_close(db);
                return 1;
            }
            managementMenu(db);
            sqlite3_close(db);
        }
    }

    return 0;
}

int userMenu()
{
    string userName;
    string password;
    int loginAttempt = 0;
    const int maxLoginAttempt = 3;

    while (loginAttempt < maxLoginAttempt)
    {
        cout << "Enter your username: ";
        cin >> userName;
        cout << "Enter your password: ";
        cin >> password;

        if (userName == "admin" && password == "admin")
        {
            return 1; // Return 1 on successful login as admin
        }
        else
        {
            cout << "Invalid username or password. Please try again." << endl;
            loginAttempt++;
        }
    }

    if (loginAttempt == maxLoginAttempt)
    {
        cout << "Too many login attempts. The program will now exit." << endl;
    }

    return 0;

    void managementMenu(sqlite3 * db)
    {
        int choice;
        while (true)
        {
            cout << "\nManagement Menu:\n";
            cout << "1. Option 1\n";
            cout << "2. Option 2\n";
            cout << "3. Option 3\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            switch (choice)
            {
            case 1:
                cout << "Option 1 selected.\n";
                // Add functionality for Option 1
                break;
            case 2:
                cout << "Option 2 selected.\n";
                // Add functionality for Option 2
                break;
            case 3:
                cout << "Option 3 selected.\n";
                // Add functionality for Option 3
                break;
            case 4:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    bool createDatabase(sqlite3 * db)
    {
        char *errMsg = nullptr;
        const char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT NOT NULL, password TEXT NOT NULL);";

        int exit = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (exit != SQLITE_OK)
        {
            cerr << "SQL error: " << errMsg << endl;
            sqlite3_free(errMsg);
            return false;
        }
        else
        {
            cout << "User table created successfully." << endl;
            return true;
        }
    }
