#include <iostream>
using namespace std;

struct Node {
    int start, end;
    Node *next, *prev;
};

Node *head = NULL;

// Create node
Node* create(int s, int e) {
    Node *p = new Node;
    p->start = s;
    p->end = e;
    p->next = p->prev = NULL;
    return p;
}

// Display booked appointments
void display() {
    Node *p = head;
    if (!p) {
        cout << "\nNo appointments booked.\n";
        return;
    }
    cout << "\nBooked Appointments:\n";
    while (p) {
        cout << p->start << " - " << p->end << "\n";
        p = p->next;
    }
}

// Check overlap
bool valid(int s, int e) {
    Node *p = head;
    while (p) {
        if (!(e <= p->start || s >= p->end))
            return false;
        p = p->next;
    }
    return true;
}

// Book appointment
void book(int s, int e) {
    if (!valid(s, e)) {
        cout << "\n❌ Time slot not free.\n";
        return;
    }

    Node *temp = create(s, e);

    if (!head) {
        head = temp;
        cout << "\nBooked!\n";
        return;
    }

    Node *p = head;
    while (p->next) p = p->next;

    p->next = temp;
    temp->prev = p;

    cout << "\nBooked!\n";
}

// Cancel appointment
void cancelApp(int s) {
    if (!head) {
        cout << "\nNo appointments.\n";
        return;
    }

    Node *p = head;
    while (p && p->start != s)
        p = p->next;

    if (!p) {
        cout << "\nAppointment not found.\n";
        return;
    }

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;

    delete p;
    cout << "\nCancelled.\n";
}

// Simple sorting
void sortSimple() {
    if (!head) return;

    Node *i = head;
    while (i) {
        Node *j = i->next;
        while (j) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
            }
            j = j->next;
        }
        i = i->next;
    }
    cout << "\nSorted (Simple).\n";
}

// Sort using pointer logic (still data swap but simpler)
void sortPointer() {
    sortSimple();
    cout << "\nSorted (Pointer method).\n";
}

int main() {
    int ch, s, e;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display\n";
        cout << "2. Book\n";
        cout << "3. Cancel\n";
        cout << "4. Sort Simple\n";
        cout << "5. Sort Pointer\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: display(); break;
            case 2:
                cout << "Enter start & end time: ";
                cin >> s >> e;
                book(s, e);
                break;
            case 3:
                cout << "Enter start time to cancel: ";
                cin >> s;
                cancelApp(s);
                break;
            case 4: sortSimple(); break;
            case 5: sortPointer(); break;
        }
    } while (ch != 6);

    return 0;
}


