#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for Room
struct Room {
int roomNumber;
int isBooked; // 0 = available, 1 = booked
char type[20];
float price;
};
// Structure for Customer (Linke
struct Customer {
char name[50];
char phone[15];
int roomNumber;
struct Customer *next;
};
// Global Variables
struct Room rooms[20];int totalRooms = 0;
struct Customer *head = NULL;
// Function Prototypes
void addRoom();
void displayAvailableRooms();
void bookRoom();
void viewCustomers();
void cancelBooking();
void menu();
// Add Room Details
void addRoom() {
printf("\nEnter Room Number: ");
scanf("%d", &rooms[totalRooms].roomNumber);
printf("Enter Room Type (Single/Double/Suite): ");
scanf("%s", rooms[totalRooms].type);
printf("Enter Room Price: ");
scanf("%f", &rooms[totalRooms].price);
rooms[totalRooms].isBooked = 0; // initially available
totalRooms++;
printf("\nRoom added successfully!\n");
}
// Display All Available Rooms
void displayAvailableRooms() {
printf("\n--- Available Rooms ---\n");
int found = 0;
for (int i = 0; i < totalRooms; i++) {
if (rooms[i].isBooked == 0) {
printf("Room No: %d | Type: %s | Price: %.2f\n",
rooms[i].roomNumber, rooms[i].type, rooms[i].price);
found = 1;
}
}
if (!found)
printf("No rooms available!\n");
}
// Book a Room
void bookRoom() {
int rno, found = 0;
printf("\nEnter Room Number to Book: ");
scanf("%d", &rno);
for (int i = 0; i < totalRooms; i++) {
if (rooms[i].roomNumber == rno && rooms[i].isBooked == 0) {
    struct Customer *newCust = (struct Customer *)malloc(sizeof(struct Customer));
printf("Enter Customer Name: ");
scanf("%s", newCust->name);
printf("Enter Phone Number: ");
scanf("%s", newCust->phone);
newCust->roomNumber = rno;
newCust->next = head;
head = newCust;
rooms[i].isBooked = 1; // mark as booked
printf("\nRoom Booked Successfully!\n"); 
found = 1;
break;
}
}
if (!found)
printf("Room not available or invalid room number!\n");
}
// View All Booked Customers
void viewCustomers() {
struct Customer *temp = head;
if (temp == NULL) {
printf("\nNo Bookings Found!\n");
return;
}
printf("\n--- Booked Customers ---\n");
while (temp != NULL) {
    printf("Name: %s | Phone: %s | Room No: %d\n",
temp->name, temp->phone, temp->roomNumber);
temp = temp->next;
}
}
// Cancel Booking
void cancelBooking() {
int rno, found = 0;
struct Customer *temp = head, *prev = NULL;
printf("\nEnter Room Number to Cancel Booking: ");
scanf("%d", &rno);
while (temp != NULL) {
if (temp->roomNumber == rno) {
if (prev == NULL)
head = temp->next;
else
prev->next = temp->next;
free(temp);
found = 1;
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
printf("\nBooking cancelled successfully!\n");
} else {
printf("\nNo booking found for given room number!\n");
}
}
// Menu Function
void menu() {
int choice;
do {
printf("\n==== HOTEL ROOM BOOKING SYSTEM ====\n");
printf("1. Add Room\n");
printf("2. Display Available Rooms\n");
printf("3. Book Room\n");
printf("4. View Booked Customers\n");
printf("5. Cancel Booking\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: addRoom(); break;
case 2: displayAvailableRooms(); break;
case 3: bookRoom(); break;
case 4: viewCustomers(); break;
case 5: cancelBooking(); break;
case 6: printf("\nExiting... Thank you!\n"); break;
default: printf("\nInvalid choice! Try again.\n");
}
} while (choice != 6);
}
// Main Function
int main() {
menu();
return 0;
}
