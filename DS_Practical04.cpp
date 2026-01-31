#include <iostream>
using namespace std;

class Sparse {
public:
    int sp[20][3];     // (row, col, value)
    int n;             // total non-zero values

    // Read matrix in sparse form
    void read() {
        cout << "\nEnter number of rows, columns and non-zero elements: ";
        cin >> sp[0][0] >> sp[0][1] >> sp[0][2];
        n = sp[0][2];

        cout << "Enter row, column and value:\n";
        for (int i = 1; i <= n; i++)
            cin >> sp[i][0] >> sp[i][1] >> sp[i][2];
    }

    // Display sparse matrix
    void display() {
        cout << "\nRow  Col  Val\n";
        for (int i = 0; i <= n; i++)
            cout << sp[i][0] << "   " << sp[i][1] << "   " << sp[i][2] << endl;
    }

    // Simple transpose
    Sparse simpleTranspose() {
        Sparse t;
        t.sp[0][0] = sp[0][1];
        t.sp[0][1] = sp[0][0];
        t.sp[0][2] = sp[0][2];

        int k = 1;
        for (int col = 0; col < sp[0][1]; col++) {
            for (int i = 1; i <= sp[0][2]; i++) {
                if (sp[i][1] == col) {
                    t.sp[k][0] = sp[i][1];
                    t.sp[k][1] = sp[i][0];
                    t.sp[k][2] = sp[i][2];
                    k++;
                }
            }
        }
        t.n = t.sp[0][2];
        return t;
    }

    // Fast transpose
    Sparse fastTranspose() {
        Sparse t;
        int row = sp[0][0], col = sp[0][1], nz = sp[0][2];

        t.sp[0][0] = col;
        t.sp[0][1] = row;
        t.sp[0][2] = nz;

        int count[20] = {0}, index[20] = {0};

        for (int i = 1; i <= nz; i++)
            count[sp[i][1]]++;

        index[0] = 1;
        for (int i = 1; i < col; i++)
            index[i] = index[i - 1] + count[i - 1];

        for (int i = 1; i <= nz; i++) {
            int pos = index[sp[i][1]]++;
            t.sp[pos][0] = sp[i][1];
            t.sp[pos][1] = sp[i][0];
            t.sp[pos][2] = sp[i][2];
        }
        t.n = nz;
        return t;
    }

    // Add two sparse matrices
    Sparse add(Sparse s2) {
        Sparse sum;
        if (sp[0][0] != s2.sp[0][0] || sp[0][1] != s2.sp[0][1]) {
            cout << "\nMatrix sizes do not match!";
            sum.n = 0;
            return sum;
        }

        sum.sp[0][0] = sp[0][0];
        sum.sp[0][1] = sp[0][1];

        int i = 1, j = 1, k = 1;
        while (i <= sp[0][2] && j <= s2.sp[0][2]) {
            if (sp[i][0] < s2.sp[j][0] ||
               (sp[i][0] == s2.sp[j][0] && sp[i][1] < s2.sp[j][1])) {
                sum.sp[k][0] = sp[i][0];
                sum.sp[k][1] = sp[i][1];
                sum.sp[k][2] = sp[i][2];
                i++; k++;
            }
            else if (sp[i][0] == s2.sp[j][0] && sp[i][1] == s2.sp[j][1]) {
                sum.sp[k][0] = sp[i][0];
                sum.sp[k][1] = sp[i][1];
                sum.sp[k][2] = sp[i][2] + s2.sp[j][2];
                i++; j++; k++;
            }
            else {
                sum.sp[k][0] = s2.sp[j][0];
                sum.sp[k][1] = s2.sp[j][1];
                sum.sp[k][2] = s2.sp[j][2];
                j++; k++;
            }
        }

        while (i <= sp[0][2]) sum.sp[k][0] = sp[i][0], sum.sp[k][1] = sp[i][1], sum.sp[k][2] = sp[i][2], i++, k++;
        while (j <= s2.sp[0][2]) sum.sp[k][0] = s2.sp[j][0], sum.sp[k][1] = s2.sp[j][1], sum.sp[k][2] = s2.sp[j][2], j++, k++;

        sum.sp[0][2] = k - 1;
        sum.n = k - 1;
        return sum;
    }
};

int main() {
    Sparse s1, s2, t1, t2, addm;
    int ch;

    while (1) {
        cout << "\n--- Sparse Matrix Menu ---\n";
        cout << "1. Read Matrix\n2. Display\n3. Simple Transpose\n4. Fast Transpose\n5. Add Two Matrices\n6. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: s1.read(); break;
            case 2: s1.display(); break;
            case 3: t1 = s1.simpleTranspose(); t1.display(); break;
            case 4: t2 = s1.fastTranspose(); t2.display(); break;
            case 5:
                cout << "\nEnter second matrix:\n";
                s2.read();
                addm = s1.add(s2);
                addm.display();
                break;
            case 6: return 0;
        }
    }
}