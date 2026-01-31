//DATA STRUCTURE : Practical no.05
#include <iostream>
using namespace std;
struct Term {
 int coeff;
 int expo;
};
class Polynomial {
 Term terms[100];
 int n; // number of terms
public:
 Polynomial() {
 n = 0;
 }
 void read() {
 cout << "Enter number of terms: ";
 cin >> n;
 cout << "Enter terms in descending order of exponents:\n";
 for (int i = 0; i < n; i++) {
 cout << "Coefficient of term " << i + 1 << ": ";
 cin >> terms[i].coeff;
 cout << "Exponent of term " << i + 1 << ": ";
 cin >> terms[i].expo;
 }
 }
 void display() {
 if (n == 0) {
 cout << "0\n";
 return;
 }
 for (int i = 0; i < n; i++) {
 if (terms[i].coeff == 0) continue;
 if (i > 0 && terms[i].coeff > 0) cout << " + ";
 if (terms[i].expo == 0)
 cout << terms[i].coeff;
 else if (terms[i].expo == 1) {
 if (terms[i].coeff == 1)
 cout << "x";
 else if (terms[i].coeff == -1)
 cout << "-x";
 else
 cout << terms[i].coeff << "x";
 } else {
 if (terms[i].coeff == 1)
 cout << "x^" << terms[i].expo;
 else if (terms[i].coeff == -1)
 cout << "-x^" << terms[i].expo;
 else
 cout << terms[i].coeff << "x^" << terms[i].expo;
 }
 }
 cout << endl;
 }
 //Add two polynomials p1 and p2 and return the result polynomial
 static Polynomial add(const Polynomial& p1, const Polynomial& p2) {
 Polynomial result;
 int i = 0, j = 0, k = 0;
 while (i < p1.n && j < p2.n) {
 if (p1.terms[i].expo > p2.terms[j].expo) {
 result.terms[k++] = p1.terms[i++];
 } else if (p1.terms[i].expo < p2.terms[j].expo) {
 result.terms[k++] = p2.terms[j++];
 } else {
 //Same exponent: add coefficients
 int sumCoeff = p1.terms[i].coeff + p2.terms[j].coeff;
 if (sumCoeff != 0) {
 result.terms[k].coeff = sumCoeff;
 result.terms[k].expo = p1.terms[i].expo;
 k++;
 }
 i++; j++;
 }
 }
 //Copy remaining terms of p1
 while (i < p1.n) {
 result.terms[k++] = p1.terms[i++];
 }
 // Copy remaining terms of p2
 while (j < p2.n) {
 result.terms[k++] = p2.terms[j++];
 }
 result.n = k;
 return result;
 }
};
int main() {
 Polynomial p1, p2, p3;
 int choice;
 do {
 cout << "\nPolynomial Operations Menu:\n";
 cout << "1. Read Polynomial 1\n";
 cout << "2. Read Polynomial 2\n";
 cout << "3. Display Polynomial 1\n";
 cout << "4. Display Polynomial 2\n";
 cout << "5. Add Polynomial 1 and Polynomial 2\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter Polynomial 1:\n";
 p1.read();
 break;
 case 2:
 cout << "Enter Polynomial 2:\n";
 p2.read();
 break;
 case 3:
 cout << "Polynomial 1: ";
 p1.display();
 break;
 case 4:
 cout << "Polynomial 2: ";
 p2.display();
 break;
 case 5:
 p3 = Polynomial::add(p1, p2);
 cout << "Sum of Polynomial 1 and 2: ";
 p3.display();
 break;
 case 6:
 cout << "Exiting program.\n";
 break;
 default:
 cout << "Invalid choice! Try again.\n";
 }
 } while (choice != 6);
 return 0;
}