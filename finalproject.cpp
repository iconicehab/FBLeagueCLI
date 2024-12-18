#include <iostream>
#include <string>
using namespace std;


class Player {
public:
    int id;  
    string name;  
    int salary;  
    string teamName;  
    Player* next;  

    //consturctor of the player class
    Player(int id, string name, int salary, string teamName) {
        this->id = id;  
        this->name = name;  
        this->salary = salary;  
        this->teamName = teamName;  
        this->next = nullptr;  
    }
};


class Team {
public:
    int id;  
    string name;  
    string president;  
    Team* next;  

    
    Team(int id, string name, string president) {
        this->id = id;  
        this->name = name;  
        this->president = president;  
        this->next = nullptr; 
    }
};

//head pointers
Team* teamHead = nullptr;  
Player* playerHead = nullptr;  

//definition of functions
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
        cout << "Egyptian League Management System"<<endl;
        cout << "1. Add New Team"<< endl;
        cout << "2. Display Teams" << endl;
        cout << "3. Search Team by ID" << endl;
        cout << "4. Add New Player" << endl;
        cout << "5. Remove Player" << endl;
        cout << "6. Display Player Data" << endl;
        cout << "7. Search Player by Name" << endl;
        cout << "8. Update Team Information" << endl;
        cout << "9. Display Players of a Team" << endl;
        cout << "10. Remove Team" << endl;
        cout << "0. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

       //switch case for the functions
        switch (choice) {
        case 1:
            addNewTeam();  
            break;
        case 2:
            displayTeams();  
            break;
        case 3:
            searchTeamByID();  
            break;
        case 4:
            addNewPlayer();  
            break;
        case 5:
            removePlayer();  
            break;
        case 6:
            displayPlayerData();  
            break;
        case 7:
            searchPlayerByName();  
            break;
        case 8:
            updateTeamInfo();  
            break;
        case 9:
            displayPlayersBySalary();  
            break;
        case 10:
            removeTeam();  
            break;
        case 0:
            cout << "Exiting the program\n";  
            break;
        default:
            cout << "wrong choice. please enter another choice.\n";  
        }
    } while (choice != 0);  

    return 0;
}


void addNewTeam() {
    int id;
    string name, president;
    cout << "Enter Team ID: ";
    cin >> id;
    cout << "Enter Team Name: ";
    cin >> name;
    cout << "Enter Team President: ";
    cin >> president;

    Team* newTeam = new Team(id, name, president);  

   
    if (teamHead == nullptr) {
        teamHead = newTeam;
    }
    else {
        Team* temp1 = teamHead;
        
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        
        temp1->next = newTeam;
    }

    cout << "New Team added successfully\n";
}


void displayTeams() {
    
    if (teamHead == nullptr) {
        cout << "there is no teams to display.\n";
        return;
    }

    Team* temp1 = teamHead;
    
    while (temp1 != nullptr) {
        cout << "Team ID: " << temp1->id << "\n";
        cout << "Team Name: " << temp1->name << "\n";
        cout << "Team President: " << temp1->president << "\n";
        cout << "---------------------------\n";
        temp1 = temp1->next;
    }
}


void searchTeamByID() {
    int id;
    cout << "Enter Team ID to search: ";
    cin >> id;

    Team* temp1 = teamHead;
    
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            cout << "Team details are:\n";
            cout << "Team ID: " << temp1->id << "\n";
            cout << "Team Name: " << temp1->name << "\n";
            cout << "Team President: " << temp1->president << "\n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Team not found.\n";  
}


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

    Player* newPlayer = new Player(id, name, salary, teamName);  

    
    if (playerHead == nullptr) {
        playerHead = newPlayer;
    }
    else {
        Player* temp1 = playerHead;
        
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        
        temp1->next = newPlayer;
    }

    cout << "Player added \n";
}


void removePlayer() {
    int id;
    cout << "Enter Player ID to remove: ";
    cin >> id;

    
    if (playerHead == nullptr) {
        cout << "No players to remove.\n";
        return;
    }

    
    if (playerHead->id == id) {
        Player* temp1 = playerHead;
        playerHead = playerHead->next;  
        delete temp1;  
        cout << "Player removed successfully"<<endl;
        return;
    }

    Player* temp1 = playerHead;
    Player* temp2 = nullptr;
    
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            temp2->next = temp1->next;  
            delete temp1;  
            cout << "Player removed successfully\n";
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    cout << "Player not found.\n";  
}


void displayPlayerData() {
    
    if (playerHead == nullptr) {
        cout << "No players to display.\n";
        return;
    }

    Player* temp1 = playerHead;
    
    while (temp1 != nullptr) {
        cout << "Player ID: " << temp1->id << "\n";
        cout << "Player Name: " << temp1->name << "\n";
        cout << "Player Salary: " << temp1->salary << "\n";
        cout << "Team Name: " << temp1->teamName << "\n";
        cout << "---------------------------\n";
        temp1 = temp1->next;
    }
}


void searchPlayerByName() {
    string name;
    cout << "Enter Player Name to search: ";
    cin >> name;

    Player* temp1 = playerHead;
    
    while (temp1 != nullptr) {
        if (temp1->name == name) {
            cout << "Player Details are:\n";
            cout << "Player ID: " << temp1->id << "\n";
            cout << "Player Name: " << temp1->name << "\n";
            cout << "Player Salary: " << temp1->salary << "\n";
            cout << "Team Name: " << temp1->teamName << "\n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Player not found.\n";  
}


void updateTeamInfo() {
    int id;
    string name, president;
    cout << "Enter Team ID to update: ";
    cin >> id;

    Team* temp1 = teamHead;
    
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            cout << "Enter new Team Name: ";
            cin >> name;
            cout << "Enter new Team President: ";
            cin >> president;
            temp1->name = name;  
            temp1->president = president;  
            cout << "Team information updated \n";
            return;
        }
        temp1 = temp1->next;
    }

    cout << "Team not found.\n";  
}


void displayPlayersBySalary() {
    string teamName;
    cout << "Enter Team Name to display players: ";
    cin >> teamName;

    Player* temp1 = playerHead;
    bool found = false;
    
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
        cout << "No players found for the team.\n";  
    }
}


void removeTeam() {
    int id;
    cout << "Enter Team ID to remove: ";
    cin >> id;

    
    if (teamHead == nullptr) {
        cout << "No teams to remove.\n";
        return;
    }

    
    if (teamHead->id == id) {
        Team* temp1 = teamHead;
        teamHead = teamHead->next;  
        delete temp1;  
        cout << "Team removed \n";
        return;
    }

    Team* temp1 = teamHead;
    Team* temp2 = nullptr;
    
    while (temp1 != nullptr) {
        if (temp1->id == id) {
            temp2->next = temp1->next;  
            delete temp1;  
            cout << "Team removed "<<endl;
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    cout << "Team not found.\n"; 
}
