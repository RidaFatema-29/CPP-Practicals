#include <iostream>
#include <string>
using namespace std;

// Structure for Room
struct Room {
    int roomNumber;
    int isBooked; // 0 = available, 1 = booked
    string type;
    float price;
};

// Structure for Customer (Linked List)
struct Customer {
    string name;
    string phone;
    int roomNumber;
    Customer* next;
};

// Global Variables
Room rooms[20];
int totalRooms = 0;
Customer* head = nullptr;

// Function Prototypes
void addRoom();
void displayAvailableRooms();
void bookRoom();
void viewCustomers();
void cancelBooking();
void menu();

// Add Room Details
void addRoom() {
    cout << "\nEnter Room Number: ";
    cin >> rooms[totalRooms].roomNumber;
    cout << "Enter Room Type (Single/Double/Suite): ";
    cin >> rooms[totalRooms].type;
    cout << "Enter Room Price: ";
    cin >> rooms[totalRooms].price;
    rooms[totalRooms].isBooked = 0; // initially available
    totalRooms++;
    cout << "\nRoom added successfully!\n";
}

// Display All Available Rooms
void displayAvailableRooms() {
    cout << "\n--- Available Rooms ---\n";
    bool found = false;
    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].isBooked == 0) {
            cout << "Room No: " << rooms[i].roomNumber
                 << " | Type: " << rooms[i].type
                 << " | Price: " << rooms[i].price << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No rooms available!\n";
}

// Book a Room
void bookRoom() {
    int rno;
    bool found = false;
    cout << "\nEnter Room Number to Book: ";
    cin >> rno;

    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].roomNumber == rno && rooms[i].isBooked == 0) {
            Customer* newCust = new Customer;
            cout << "Enter Customer Name: ";
            cin >> newCust->name;
            cout << "Enter Phone Number: ";
            cin >> newCust->phone;
            newCust->roomNumber = rno;
            newCust->next = head;
            head = newCust;
            rooms[i].isBooked = 1; // mark as booked
            cout << "\nRoom Booked Successfully!\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Room not available or invalid room number!\n";
}

// View All Booked Customers
void viewCustomers() {
    Customer* temp = head;
    if (temp == nullptr) {
        cout << "\nNo Bookings Found!\n";
        return;
    }
    cout << "\n--- Booked Customers ---\n";
    while (temp != nullptr) {
        cout << "Name: " << temp->name
             << " | Phone: " << temp->phone
             << " | Room No: " << temp->roomNumber << endl;
        temp = temp->next;
    }
}

// Cancel Booking
void cancelBooking() {
    int rno;
    bool found = false;
    Customer* temp = head;
    Customer* prev = nullptr;

    cout << "\nEnter Room Number to Cancel Booking: ";
    cin >> rno;

    while (temp != nullptr) {
        if (temp->roomNumber == rno) {
            if (prev == nullptr)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (found) {
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i].roomNumber == rno) {
                rooms[i].isBooked = 0;
                break;
            }
        }
        cout << "\nBooking cancelled successfully!\n";
    } else {
        cout << "\nNo booking found for given room number!\n";
    }
}

// Menu Function
void menu() {
    int choice;
    do {
        cout << "\n==== HOTEL ROOM BOOKING SYSTEM ====\n";
        cout << "1. Add Room\n";
        cout << "2. Display Available Rooms\n";
        cout << "3. Book Room\n";
        cout << "4. View Booked Customers\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRoom(); break;
            case 2: displayAvailableRooms(); break;
            case 3: bookRoom(); break;
            case 4: viewCustomers(); break;
            case 5: cancelBooking(); break;
            case 6: cout << "\nExiting... Thank you!\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);
}

// Main Function
int main() {
    menu();
    return 0;
}
