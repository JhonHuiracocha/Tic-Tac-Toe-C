#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int player = 1, attemps = 9;

// All possible combinations to win a game
char combinations[][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'}, 
    {'7', '8', '9'}, 
    {'1', '4', '7'}, 
    {'2', '5', '8'},
    {'3', '6', '9'},
    {'1', '5', '9'},
    {'3', '5', '7'}
};

void update();
void initTable(char board[]);
int checkWinner(char board[]);
void updateTable(char board[]);
void enterPosition(char board[]);
bool checkPosition(char board[], char position);
void enterPositionOnBoard(char board[], char position, char mark);

int main(){
	
	update();
	
	return 0;
}

void update() {
	int winner = 0;
	char board[9] = "";
	
	initTable(board);
	
	while(winner == 0 && attemps > 0) {
		updateTable(board);
		enterPosition(board);
		winner = checkWinner(board);
	}
	
	updateTable(board);
	
	switch(winner) {
		case 0:
			printf("\n\nTie\n\n");
			break;
			
		case 1:
			printf("\n\nPlayer 1 has won the game\n\n");
			break;
			
		case 2:
			printf("\n\nPlayer 2 has won the game\n\n");
			break;
	}
	
	system("pause");	
}

void initTable(char board[]) {
	int i = 0;
	char aux = '1';
	
	while(i < 9) 
		board[i++] = aux++;
}

void updateTable(char board[]) {
	system("cls");
	printf("Player1 (X) - Player2 (O)\n\n");
	printf(" %c | %c | %c \n", board[0], board[1], board[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[3], board[4], board[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c ", board[6], board[7], board[8]);
}

void enterPosition(char board[]) {
	char position = ' ', mark = ' ';
	
	do{
		player = (player % 2 != 0) ? 1 : 2;
		
		printf("\n\nPlayer %i, enter a position: ", player);
		scanf("%c", &position);
		fflush(stdin);
		
		if(!checkPosition(board, position)) {
			system("cls");
			printf("\nOccupied position, enter a position again\n\n");
			system("pause");
			updateTable(board);
		}
		
	} while(!checkPosition(board, position));
	
	attemps--;
	mark = (player == 1) ? 'X' : 'O';
	enterPositionOnBoard(board, position, mark);

	player++;
}

bool checkPosition(char board[], char position) {
	int i = position - '0';
	return board[i - 1] == position;
}

void enterPositionOnBoard(char board[], char position, char mark) {
	int i = position - '0';
	board[i - 1] = mark;
}

int checkWinner(char board[]) {
	int i;
	
	for(i = 0; i < 9; i++) {
		if(board[combinations[i][0] - '1'] == 'X' && board[combinations[i][1] - '1'] == 'X' && board[combinations[i][2] - '1'] == 'X')
			return 1;
		
		if(board[combinations[i][0] - '1'] == 'O' && board[combinations[i][1] - '1'] == 'O' && board[combinations[i][2] - '1'] == 'O')
			return 2;
	}
	
	return 0;
}
