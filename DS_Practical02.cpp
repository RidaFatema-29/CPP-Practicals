#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n, m;
    cout << "Enter room size (n m): ";
    cin >> n >> m;

    bool visited[100][100] = {false};   // track visited tiles
    int totalTiles = n * m;
    int visitedCount = 0;

    int x = n / 2;   // start in the middle
    int y = m / 2;

    visited[x][y] = true;
    visitedCount++;

    srand(time(0));

    int moves = 0;

    // All 8 directions
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    while (visitedCount < totalTiles) {

        int r = rand() % 8;      // pick any random direction
        int nx = x + dx[r];
        int ny = y + dy[r];

        // stay inside the room
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            x = nx;
            y = ny;
            moves++;

            if (!visited[x][y]) {
                visited[x][y] = true;
                visitedCount++;
            }

            // Draw the room
            system("cls");      // clear screen for animation
            cout << "Random Walk Simulation\n";
            cout << "Moves: " << moves << "\n\n";

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == x && j == y)
                        cout << " 🪳 ";    // cockroach
                    else if (visited[i][j])
                        cout << " ▓ ";     // visited tile
                    else
                        cout << " ░ ";     // unvisited
                }
                cout << endl;
            }
        }
    }

    cout << "\n\nTotal moves to visit all tiles = " << moves << endl;
    return 0;
}