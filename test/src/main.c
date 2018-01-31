
#include <stdio.h>
#include <stdlib.h>

int win(const int board[9]) {
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int board[9], int player) {
    int winner = win(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = player;
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}

int computerMove(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    return move;
}


void playerMove(int board[9]) {
int move = 0;
do {
start:
printf("\nInput move ([0..8]): ");
scanf("%d", &move);
if(board[move] != 0) {
printf("Its Already Occupied !");
goto start;
}
printf("\n");
} while (move >= 9 || move < 0 || board[move] != 0);
board[move] = -1;
}


int* get_board_state(char* string)
{
int *temp = (int*) malloc (sizeof(int) * 9);
if (NULL == temp)
  return NULL;

for (int i = 0;i < 9;i++)
  {
  if ('1' == string[i])
  temp[i] = 1;
  else if ('2' ==  string[i])
    temp[i] = -1;
    else
      temp[i] = 0;
}
return temp;
}

int main(int argc, char* args[]) {
 
 if(argc < 2)
 {
    return 4;
  }
 int *board =  get_board_state(args[1]);
  if (NULL == board)
    return 4;
  
            printf ("%d",computerMove(board));

}
