#include <stdio.h>
#include <stdlib.h>

char *go();
void start_game();
void check_draw();
void draw_board(int *board);
void player_first();
void menu();

int main (void) {
    menu(); 
    int i = 0;
    scanf("%d", &i);
    int *board = NULL;
    if (0 < i && i < 3) { 
        *board = go(i);
    } else { 
        printf("Exiting..\n"); 
        return 0; 
    }
    draw_board(board);
    return 0;
}

void menu()
{
    printf("---------MENU---------\n");
    printf("1 : Play with X\n");
    printf("2 : Play with O\n");
    printf("3 : Exit\n");
    printf("Enter your choice: \n");
}

char *go() 
{
    int *board = malloc(40);
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
    return board;
}

void start_game() 
{
}

void check_draw()
{
}

void draw_board(int *board) 
{
    if (board == NULL) {
        printf("Error board == NULL\n");
        return;
    }
    printf("    |     |     \n");
    printf("%c  | %c  | %c  \n", board[0], board[1], board[2]);
    printf("    |     |     \n");
    printf("----------------\n");
    printf("    |     |     \n");
    printf("%c  | %c  | %c  \n", board[3], board[4], board[5]);
    printf("    |     |     \n");
    printf("----------------\n");
    printf("    |     |     \n");
    printf("%c  | %c  | %c  \n", board[6], board[7], board[8]);
    printf("    |     |     \n"); 
}

void player_first()
{
}
