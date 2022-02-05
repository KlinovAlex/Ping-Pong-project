//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
# include <stdio.h>
# include <math.h>

# define KEY_P1_UP 97
# define KEY_P1_DOWN 122
# define KEY_P2_UP 107
# define KEY_P2_DOWN 109
# define RACKET_SIZE 3
# define BALL_SIZE 1
# define FIELD_WIDTH 80
# define FIELD_HEIGHT 25
# define FIELD_WIDTH_START 0
# define FIELD_HEIGHT_START 0
# define WIN_SCORE 21
# define PLAYER_1_MOVE 1
# define PLAYER_2_MOVE 0

void game_end();
void clear_screen();
void draw_pole(int player1_racket_x, int player1_racket_y, int player2_racket_x,
            int player2_racket_y, int ball_cur_pos_x, int ball_cur_pos_y);

int ball_position();
int get_vertical_center_position();
int player_turn(int ball_cur_pos_x);
void get_move(int ball_cur_pos_x);


//Structure of ball
int ball_cur_pos_x;
int ball_cur_pos_y;

//Structure of player 1
int player1_score ;
int player1_racket_x;
int player1_racket_y;
int player1_pressed_key;
int player1_score;

//Structure of player 1
int player2_score ;
int player2_racket_x;
int player2_racket_y;
int player2_pressed_key;
int player2_score;


int main() {
	while (player1_score < 21 || player2_score < 21){
		// draw_pole (0, 0, 0, 0, 20, 20);
		get_move(60);
		// printf("%d\n", player2_racket_y);
		// printf("%d\n", player1_racket_y);
    }
	game_end();
    return 0;
}

void game_end() {
	// Function displayed congratulations of winner
	printf("%s %s", "Game over", "What player");
}


void clear_screen() {
// Function nave to clean screen after move
}


void put_ball_position (int x, int y) {
	// Put ball position
	ball_cur_pos_x = x;
	ball_cur_pos_y = y;
}

int get_vertical_center_position() {
	return FIELD_WIDTH/2;
}

int player_turn(int ball_cur_pos_x) {
	// Function defines players turn.
	// If function returns 1 - Player 1 turned
	// If function returns 0 - Player 2 turned
	if (ball_cur_pos_x <= get_vertical_center_position()) {
		return PLAYER_1_MOVE;
	} else {
		return PLAYER_2_MOVE;
	}
}


void get_move(int ball_cur_pos_x){
	// Function waiting players move define who's turn and write players y position
	char key_pressed;
	key_pressed = getchar();

	if(player_turn(ball_cur_pos_x) == PLAYER_1_MOVE) {
		if (key_pressed == KEY_P1_UP) {
			player1_racket_y--;
			if (player1_racket_y < 0) {
				player1_racket_y=0;
			}
		}
		if (key_pressed == KEY_P1_DOWN) {
			player1_racket_y++;
			if (player1_racket_y+RACKET_SIZE >= FIELD_HEIGHT) {
				player1_racket_y-=RACKET_SIZE-1;
			}
		}
	}
	if(player_turn(ball_cur_pos_x) == PLAYER_2_MOVE) {
		if (key_pressed == KEY_P2_UP) {
			player2_racket_y--;
			if (player2_racket_y < 0) {
				player2_racket_y=0;
			}
		}
		if (key_pressed == KEY_P2_DOWN) {
			player2_racket_y++;
			if (player2_racket_y+RACKET_SIZE >= FIELD_HEIGHT) {
				player2_racket_y-=RACKET_SIZE-1;
			}
		}
	}
}

void 



void draw_pole(int player1_racket_x, int player1_racket_y, int player2_racket_x,
            int player2_racket_y, int ball_cur_pos_x, int ball_cur_pos_y) {
// Function drawing pole
    int x, y;
	player1_racket_x = 0;
	player1_racket_y = 0;
	player2_racket_x = 0;
	player2_racket_y = 0;
	ball_cur_pos_x = 0;
	ball_cur_pos_y = 0;
    for(y = 0 ; y < FIELD_HEIGHT ; y++) {
		if (x==FIELD_HEIGHT) {
			putchar(y);
		}
		puts("|");
        for(x = 0 ; x < FIELD_WIDTH ; x++) {
			printf("%10s", "a");
			if (ball_cur_pos_x == x) {
				if(ball_cur_pos_y == y) {
					puts("0");
				}
			}
			if (x == FIELD_WIDTH) {
				putchar(13);

			}
		}
	}
}


