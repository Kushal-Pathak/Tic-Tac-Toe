#include <iostream>
#define rows 3
#define cols 3
#define player1 'X'
#define player2 'O'
using namespace std;

char board[rows][cols];
char turn = player1;

void display_board();
char check_winner();
void change_turn();
void reset_board();
void how_to_play();

int main() {
	how_to_play();
	char play = 'y';
	while (play == 'y') {
		int game_over = 0;
		int step = 0;
		reset_board();
		while (!game_over) {
			display_board();
			if (step < 9) {
				cout << turn << "'s turn: ";
				int h, w;
				cin >> h >> w;
				if (h > 0 && h < 4 && w > 0 && w < 4 && board[h - 1][w - 1] == ' ') {
					board[h - 1][w - 1] = turn;
					step++;
				}
				else {
					continue;
				}
				char result = check_winner();
				if (result) {
					display_board();
					cout << result << " wins!";
					game_over = 1;
				}
				change_turn();
			}
			else {
				cout << "Draw!";
				game_over = 1;
			}
		}
		play = NULL;
		cout << endl << "Play again (y/n) ?" << endl;
		cin >> play;
	}
	return 0;
}

void display_board() {
	system("cls");
	cout << "-------------" << endl;
	for (int i = 0; i < rows; i++) {
		cout << "| ";
		for (int j = 0; j < cols; j++) {
			cout << board[i][j] <<" | ";
		}
		cout << endl << "-------------" << endl;
	}
}

char check_winner() {
	//checking rows
	for (int i = 0; i < rows; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return board[i][0];
	}

	//checking cols
	for (int j = 0; j < cols; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') return board[0][j];
	}

	//checking diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') return board[2][0];

	return NULL;
}

void change_turn() {
	if (turn == player1) turn = player2;
	else turn = player1;
}

void reset_board() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = ' ';
		}
	}
}

void how_to_play() {
	cout << "Enter vertical index and horizontal index seperated by a space to play a turn ";
	cout << "e.g (2 2).";
	cout << endl << "Press enter to play...";
	cin.get();
}