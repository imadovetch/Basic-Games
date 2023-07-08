#include <stdio.h>

char table[8][7] = {
    {'#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', 'P', ' ', 'B', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', 'L', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
};

char Location;
int LocationY = 0;
int LocationX = 0;
int LY = 0;
int LX = 0;
int Wall = 0;

void FindPerson() {
    LocationY = 0;
    LocationX = 0;
    for (int Ligne = 0; Ligne < 8; Ligne++) {
        for (int Col = 0; Col < 7; Col++) {
            if (table[Ligne][Col] == 'P') {
                LocationY = Ligne;
                LocationX = Col;
            }
        }
    }
}

void FindLoc() {
    for (int Ligne = 0; Ligne < 8; Ligne++) {
        for (int Col = 0; Col < 7; Col++) {
            if (table[Ligne][Col] == 'L') {
                LY = Ligne;
                LX = Col;
            }
        }
    }
}

void MoveRight() {
    if (table[LocationY][LocationX + 1] == '#') {
        printf("There is a (#) there!\n");
        Wall = 1;
    } else if (table[LocationY][LocationX + 1] == 'B') {
        if (table[LocationY][LocationX + 2] == '#') {
            printf("You can't move the box there!\n");
            Wall = 1;
        } else if (table[LocationY][LocationX + 2] == ' ' || table[LocationY][LocationX + 2] == 'L') {
            table[LocationY][LocationX] = ' ';
            table[LocationY][LocationX + 1] = 'P';
            table[LocationY][LocationX + 2] = 'B';
            CheckWinner(LocationY, LocationX + 2);
        }
    } else if (table[LocationY][LocationX + 1] == ' ') {
        table[LocationY][LocationX + 1] = 'P';
        table[LocationY][LocationX] = ' ';
    }
}

void MoveLeft() {
    if (table[LocationY][LocationX - 1] == '#') {
        printf("There is a (#) there!\n");
        Wall = 1;
    } else if (table[LocationY][LocationX - 1] == 'B') {
        if (table[LocationY][LocationX - 2] == '#') {
            printf("You can't move the box there!\n");
            Wall = 1;
        } else if (table[LocationY][LocationX - 2] == ' ' || table[LocationY][LocationX - 2] == 'L') {
            table[LocationY][LocationX] = ' ';
            table[LocationY][LocationX - 1] = 'P';
            table[LocationY][LocationX - 2] = 'B';
            CheckWinner(LocationY, LocationX - 2);
        }
    } else if (table[LocationY][LocationX - 1] == ' ') {
        table[LocationY][LocationX - 1] = 'P';
        table[LocationY][LocationX] = ' ';
    }
}

void MoveDown() {
    if (table[LocationY + 1][LocationX] == '#') {
        printf("There is a (#) there!\n");
        Wall = 1;
    } else if (table[LocationY + 1][LocationX] == 'B') {
        if (table[LocationY + 2][LocationX] == '#') {
            printf("You can't move the box there!\n");
            Wall = 1;
        } else if (table[LocationY + 2][LocationX] == ' ' || table[LocationY + 2][LocationX] == 'L') {
            table[LocationY][LocationX] = ' ';
            table[LocationY + 1][LocationX] = 'P';
            table[LocationY + 2][LocationX] = 'B';
            CheckWinner(LocationY + 2, LocationX);
        }
    } else if (table[LocationY + 1][LocationX] == ' ') {
        table[LocationY + 1][LocationX] = 'P';
        table[LocationY][LocationX] = ' ';
    }
}

void MoveUp() {
    if (table[LocationY - 1][LocationX] == '#') {
        printf("There is a (#) there!\n");
        Wall = 1;
    } else if (table[LocationY - 1][LocationX] == 'B') {
        if (table[LocationY - 2][LocationX] == '#') {
            printf("You can't move the box there!\n");
            Wall = 1;
        } else if (table[LocationY - 2][LocationX] == ' ' || table[LocationY - 2][LocationX] == 'L') {
            table[LocationY][LocationX] = ' ';
            table[LocationY - 1][LocationX] = 'P';
            table[LocationY - 2][LocationX] = 'B';
            CheckWinner(LocationY - 2, LocationX);
        }
    } else if (table[LocationY - 1][LocationX] == ' ') {
        table[LocationY - 1][LocationX] = 'P';
        table[LocationY][LocationX] = ' ';
    }
}

void CheckWinner(int LocBoxY, int LocBoxX) {
    if (LocBoxY == LY && LocBoxX == LX) {
        printf("You Win!\n");
        Wall = 1;
    }
}

void ShowTable() {
    for (int Ligne = 0; Ligne < 8; Ligne++) {
        for (int Col = 0; Col < 7; Col++) {
            printf("%c", table[Ligne][Col]);
            if (Col < 6) {
                printf("|");
            }
        }
        printf("\n");
    }
}

int main() {
   printf("************MOVE THE BOX (B) TO THE LOCATION (L)******************\n");
    FindLoc();
    ShowTable();
    
    while (!Wall) {
        scanf(" %c", &Location);
        FindPerson();
        switch (Location) {
            case 'd':
                MoveRight();
                break;
            case 'q':
                MoveLeft();
                break;
            case 's':
                MoveDown();
                break;
            case 'z':
                MoveUp();
                break;
            default:
                printf("Invalid input!\n");
        }
        ShowTable();
    }
    
    return 0;
}