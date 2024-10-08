#include <iostream>
#include <fstream>
#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(std::string u, std::string p) : username(u), password(p) {}
};

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Check if user already exists
    std::ifstream infile("users.txt");
    std::string line;
    while (std::getline(infile, line)) {
        if (line == username) {
            std::cout << "Username already exists. Please try a different username.\n";
            return;
        }
    }
    infile.close();

    // Register user
    std::ofstream outfile("users.txt", std::ios::app);
    outfile << username << "\n" << password << "\n";
    outfile.close();
    std::cout << "Registration successful.\n";
}

void loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream infile("users.txt");
    std::string line;
    bool userFound = false;

    while (std::getline(infile, line)) {
        if (line == username) {
            std::getline(infile, line); // Get the password
            if (line == password) {
                userFound = true;
                break;
            } else {
                std::cout << "Incorrect password.\n";
                return;
            }
        }
    }
    infile.close();

    if (userFound) {
        std::cout << "Login successful!\n";
    } else {
        std::cout << "User not found.\n";
    }
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n1. Register\n2. Login\n3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}