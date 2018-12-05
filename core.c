#include <stdio.h>
#include <stdlib.h>

void *go(int i, char *board);
int check_input(int num, char *board);
int check_draw(char *board);
int check_board(char *board);
void draw_board(char *board);
void menu();
void bot(char *board, int i);
 
void prompt();

int main (void) {
    menu(); 
    int i = 0;
    scanf("%d", &i); 
    char *board = malloc(40);
    if (0 < i && i < 3) { 
        go(i, board);
    } else { 
        printf("Exiting..\n"); 
        return 0; 
    } 
    if (i == 1) i = 'X';
    if (i == 2) i = 'O';
    int num = 0;
    while(!check_board(board) && !check_draw(board)) {
        draw_board(board);
        prompt();
        scanf("%d", &num);
        if (!check_input(num, board)) {
            system("clear");
            printf("Invalid\n");
            continue;
        }
        board[num - 1] = i;
        system("clear");
        bot(board, i); 
    }
    free(board);
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

int check_input(int num, char *board) 
{
    if (num < 0) return 0;
    if (num > 10) return 0;
    if (board[num - 1] != ' ') return 0;
    return 1;
}

void *go(int i, char *board) 
{
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void bot(char *board, int i)
{
    if (i == 'X') i = 'O';
    else if (i == 'O') i = 'X';
    for(int j = 0; j < 9; j++) {
        if (board[j] == ' ') {
            board[j] = i;
            return;
        }
    }
}

void prompt()
{
    printf("Enter a number 1..9\n");
}

int check_draw(char *board)
{
    for(int i = 0; i < 9; i++) {
        if (board[i] == ' ') return 0;
    }
    return 1;
}

int check_board(char *board)
{
    return 0;
}
void draw_board(char *board) 
{
    if (board == NULL) {
        printf("Error board == NULL\n");
        return;
    }
    printf("    |     |     \n");
    printf(" %c  |  %c  | %c  \n", board[0], board[1], board[2]);
    printf("    |     |     \n");
    printf("----------------\n");
    printf("    |     |     \n");
    printf(" %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("    |     |     \n");
    printf("----------------\n");
    printf("    |     |     \n");
    printf(" %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("    |     |     \n"); 
}
