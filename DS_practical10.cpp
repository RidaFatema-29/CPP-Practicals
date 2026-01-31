#include <iostream>
#include <algorithm>
using namespace std;

float marks[100];
int n;

// ---------------- SELECTION SORT ----------------
void selectionSort() {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
            if (marks[j] < marks[minIndex])
                minIndex = j;
        swap(marks[i], marks[minIndex]);
    }
}

// ---------------- BUBBLE SORT ----------------
void bubbleSort() {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (marks[j] > marks[j+1])
                swap(marks[j], marks[j+1]);
}

// ---------------- INSERTION SORT ----------------
void insertionSort() {
    for (int i = 1; i < n; i++) {
        float key = marks[i];
        int j = i - 1;
        while (j >= 0 && marks[j] > key) {
            marks[j+1] = marks[j];
            j--;
        }
        marks[j+1] = key;
    }
}

// ---------------- SHELL SORT ----------------
void shellSort() {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = marks[i];
            int j;
            for (j = i; j >= gap && marks[j-gap] > temp; j -= gap)
                marks[j] = marks[j-gap];
            marks[j] = temp;
        }
    }
}

// ---------------- QUICK SORT ----------------
int partition(int low, int high) {
    float pivot = marks[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (marks[j] < pivot) {
            i++;
            swap(marks[i], marks[j]);
        }
    }
    swap(marks[i+1], marks[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// ---------------- RADIX SORT (for integer-like marks) ----------------
int getMax() {
    float mx = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] > mx)
            mx = marks[i];
    return (int)mx;
}

void countSort(int exp) {
    float output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(int(marks[i]/exp)%10)]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        output[count[(int(marks[i]/exp)%10)] - 1] = marks[i];
        count[(int(marks[i]/exp)%10)]--;
    }

    for (int i = 0; i < n; i++)
        marks[i] = output[i];
}

void radixSort() {
    int maxNum = getMax();
    for (int exp = 1; maxNum/exp > 0; exp *= 10)
        countSort(exp);
}

// ---------------- DISPLAY TOP FIVE ----------------
void displayTopFive() {
    cout << "\nTop Five Scores:\n";
    int start = max(0, n - 5);
    for (int i = n-1; i >= start; i--)
        cout << marks[i] << " ";
    cout << endl;
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "\n1. Enter marks manually\n2. Generate random marks\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter marks:\n";
        for (int i = 0; i < n; i++)
            cin >> marks[i];
    } else {
        for (int i = 0; i < n; i++)
            marks[i] = rand() % 101; // 0–100 random marks
    }

    cout << "\nSorting Options:\n";
    cout << "1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Shell Sort\n5. Quick Sort\n6. Radix Sort\n7. STL Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: selectionSort(); break;
        case 2: bubbleSort(); break;
        case 3: insertionSort(); break;
        case 4: shellSort(); break;
        case 5: quickSort(0, n-1); break;
        case 6: radixSort(); break;
        case 7: sort(marks, marks + n); break;
        default: cout << "Invalid choice!";
    }

    cout << "\nSorted Marks:\n";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    displayTopFive();

    return 0;
}