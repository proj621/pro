#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
//user database
unordered_map<string, string> userDatabase;

//register a new user
void registerUser() {
    string username, password;

    cout << "Register a new account:\n";
    cout << "Enter username: ";
    cin >> username;

    //Check if the username is already taken
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "Username already exists. Please try another username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    //Save user credentials to the database
    userDatabase[username] = password;
    cout << "Registration successful!\n";
}

//for user login
void loginUser() {
    string username, password;

    cout << "Login:\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    //Check if the username exists and password matches
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        cout << "Login successful! Welcome " << username << "!\n";
    } else {
        cout << "Invalid username or password. Please try again.\n";
    }
}


void showMenu() {
    cout << "\nHealthcare Application - Main Menu\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    cout << "Welcome to the Healthcare Application\n";
    
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the application. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
