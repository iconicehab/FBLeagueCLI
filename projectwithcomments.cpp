#include <iostream>
#include <string>
using namespace std;

// Player class to hold player information
class Player {
public:
    int id;  // Unique identifier for the player
    string name;  // Name of the player
    int salary;  // Salary of the player
    string teamName;  // The team the player belongs to
    Player* next;  // Pointer to the next player in the list

    // Constructor to initialize a new player
    Player(int id, string name, int salary, string teamName) {
        this->id = id;  // Initialize player id
        this->name = name;  // Initialize player name
        this->salary = salary;  // Initialize player salary
        this->teamName = teamName;  // Initialize player team name
        this->next = nullptr;  // Set next pointer to nullptr (no next player)
    }
};

// Team class to hold team information
class Team {
public:
    int id;  // Unique identifier for the team
    string name;  // Name of the team
    string president;  // President of the team
    Team* next;  // Pointer to the next team in the list

    // Constructor to initialize a new team
    Team(int id, string name, string president) {
        this->id = id;  // Initialize team id
        this->name = name;  // Initialize team name
        this->president = president;  // Initialize team president
        this->next = nullptr;  // Set next pointer to nullptr (no next team)
    }
};

// Global pointers for the linked lists of teams and players
Team* teamHead = nullptr;  // Points to the first team
Player* playerHead = nullptr;  // Points to the first player

// Function prototypes for all operations
void addNewTeam();
void displayTeams();
void searchTeamByID();
void addNewPlayer();
void removePlayer();
void displayPlayerData();
void searchPlayerByName();
void updateTeamInfo();
void displayPlayersBySalary();
void removeTeam();

int main() {
    int choice;
    do {
        // Display menu options for the user
        cout << "\nEgyptian League Management System\n";
        cout << "1. Add New Team\n";
        cout << "2. Display Teams\n";
        cout << "3. Search Team by ID\n";
        cout << "4. Add New Player\n";
        cout << "5. Remove Player\n";
        cout << "6. Display Player Data\n";
        cout << "7. Search Player by Name\n";
        cout << "8. Update Team Information\n";
        cout << "9. Display Players of a Team\n";
        cout << "10. Remove Team\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch statement to perform actions based on the user choice
        switch (choice) {
            case 1:
                addNewTeam();  // Call to add a new team
                break;
            case 2:
                displayTeams();  // Call to display all teams
                break;
            case 3:
                searchTeamByID();  // Call to search team by ID
                break;
            case 4:
                addNewPlayer();  // Call to add a new player
                break;
            case 5:
                removePlayer();  // Call to remove a player
                break;
            case 6:
                displayPlayerData();  // Call to display player data
                break;
            case 7:
                searchPlayerByName();  // Call to search player by name
                break;
            case 8:
                updateTeamInfo();  // Call to update team information
                break;
            case 9:
                displayPlayersBySalary();  // Call to display players by salary
                break;
            case 10:
                removeTeam();  // Call to remove a team
                break;
            case 0:
                cout << "Exiting the program. Goodbye!\n";  // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again.\n";  // Invalid option message
        }
    } while (choice != 0);  // Continue the loop until the user chooses to exit

    return 0;
}

// Function to add a new team
void addNewTeam() {
    int id;
    string name, president;
    cout << "Enter Team ID: ";
    cin >> id;
    cout << "Enter Team Name: ";
    cin >> name;
    cout << "Enter Team President: ";
    cin >> president;

    Team* newTeam = new Team(id, name, president);  // Create a new team

    // If no teams exist, set the new team as the first team (head)
    if (teamHead == nullptr) {
        teamHead = newTeam;
    } else {
        Team* temp1 = teamHead;
        // Traverse to the last team in the list
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        // Set the last team's next pointer to the new team
        temp1->next = newTeam;
    }

    cout << "Team added successfully!\n";
}

// Function to display all teams
void displayTeams() {
    // If there are no teams, display a message and return
    if (teamHead == nullptr) {
        cout << "No teams to display.\n";
        return;
    }

    Team* temp1 = teamHead;
    // Traverse the list and display each team
    while (temp1 != nullptr) {
        cout << "Team ID: " << temp1->id << "\n";
        cout << "Team Name: " << temp1->name << "\n";
        cout << "Team President: " << temp1->president << "\n";
        cout << "---------------------------\n";
        temp1 = temp1->next;
    }
}

// Function to search for a team by its ID
void searchTeamByID() {
    int id;
    cout << "Enter Team ID to search: ";
    cin >> id;

    Team* temp1 = teamHead;
    // Traverse the list to find the team with the given ID
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            cout << "Team Found:\n";
            cout << "Team ID: " << temp1->id << "\n";
            cout << "Team Name: " << temp1->name << "\n";
            cout << "Team President: " << temp1->president << "\n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Team not found.\n";  // If the team is not found
}

// Function to add a new player
void addNewPlayer() {
    int id, salary;
    string name, teamName;
    cout << "Enter Player ID: ";
    cin >> id;
    cout << "Enter Player Name: ";
    cin >> name;
    cout << "Enter Player Salary: ";
    cin >> salary;
    cout << "Enter Team Name: ";
    cin >> teamName;

    Player* newPlayer = new Player(id, name, salary, teamName);  // Create a new player

    // If no players exist, set the new player as the first player (head)
    if (playerHead == nullptr) {
        playerHead = newPlayer;
    } else {
        Player* temp1 = playerHead;
        // Traverse to the last player in the list
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        // Set the last player's next pointer to the new player
        temp1->next = newPlayer;
    }

    cout << "Player added successfully!\n";
}

// Function to remove a player by ID
void removePlayer() {
    int id;
    cout << "Enter Player ID to remove: ";
    cin >> id;

    // If no players exist, display a message and return
    if (playerHead == nullptr) {
        cout << "No players to remove.\n";
        return;
    }

    // If the player to be removed is the first one
    if (playerHead->id == id) {
        Player* temp1 = playerHead;
        playerHead = playerHead->next;  // Set the head to the next player
        delete temp1;  // Delete the removed player
        cout << "Player removed successfully!\n";
        return;
    }

    Player* temp1 = playerHead;
    Player* temp2 = nullptr;
    // Traverse the list to find the player with the given ID
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            temp2->next = temp1->next;  // Bypass the player to remove it
            delete temp1;  // Delete the player
            cout << "Player removed successfully!\n";
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    cout << "Player not found.\n";  // If player is not found
}

// Function to display all player data
void displayPlayerData() {
    // If no players exist, display a message and return
    if (playerHead == nullptr) {
        cout << "No players to display.\n";
        return;
    }

    Player* temp1 = playerHead;
    // Traverse the list and display each player's data
    while (temp1 != nullptr) {
        cout << "Player ID: " << temp1->id << "\n";
        cout << "Player Name: " << temp1->name << "\n";
        cout << "Player Salary: " << temp1->salary << "\n";
        cout << "Team Name: " << temp1->teamName << "\n";
        cout << "---------------------------\n";
        temp1 = temp1->next;
    }
}

// Function to search for a player by name
void searchPlayerByName() {
    string name;
    cout << "Enter Player Name to search: ";
    cin >> name;

    Player* temp1 = playerHead;
    // Traverse the list to find the player with the given name
    while (temp1 != nullptr) {
        if (temp1->name == name) {
            cout << "Player Found:\n";
            cout << "Player ID: " << temp1->id << "\n";
            cout << "Player Name: " << temp1->name << "\n";
            cout << "Player Salary: " << temp1->salary << "\n";
            cout << "Team Name: " << temp1->teamName << "\n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Player not found.\n";  // If player is not found
}

// Function to update team information by ID
void updateTeamInfo() {
    int id;
    string name, president;
    cout << "Enter Team ID to update: ";
    cin >> id;

    Team* temp1 = teamHead;
    // Traverse the list to find the team with the given ID
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            cout << "Enter new Team Name: ";
            cin >> name;
            cout << "Enter new Team President: ";
            cin >> president;
            temp1->name = name;  // Update team name
            temp1->president = president;  // Update team president
            cout << "Team information updated successfully!\n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Team not found.\n";  // If team is not found
}

// Function to display players of a team by salary
void displayPlayersBySalary() {
    string teamName;
    cout << "Enter Team Name to display players: ";
    cin >> teamName;

    Player* temp1 = playerHead;
    bool found = false;
    // Traverse the player list to find players belonging to the given team
    while (temp1 != nullptr) {
        if (temp1->teamName == teamName) {
            found = true;
            cout << "Player ID: " << temp1->id << "\n";
            cout << "Player Name: " << temp1->name << "\n";
            cout << "Player Salary: " << temp1->salary << "\n";
            cout << "---------------------------\n";
        }
        temp1 = temp1->next;
    }

    if (!found) {
        cout << "No players found for the team.\n";  // If no players found
    }
}

// Function to remove a team by ID
void removeTeam() {
    int id;
    cout << "Enter Team ID to remove: ";
    cin >> id;

    // If no teams exist, display a message and return
    if (teamHead == nullptr) {
        cout << "No teams to remove.\n";
        return;
    }

    // If the team to be removed is the first one
    if (teamHead->id == id) {
        Team* temp1 = teamHead;
        teamHead = teamHead->next;  // Set the head to the next team
        delete temp1;  // Delete the removed team
        cout << "Team removed successfully!\n";
        return;
    }

    Team* temp1 = teamHead;
    Team* temp2 = nullptr;
    // Traverse the list to find the team with the given ID
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            temp2->next = temp1->next;  // Bypass the team to remove it
            delete temp1;  // Delete the team
            cout << "Team removed successfully!\n";
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    cout << "Team not found.\n";  // If team is not found
}
