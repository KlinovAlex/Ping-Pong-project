//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
# include <stdio.h>
# include <math.h>

# define KEY_P1_UP a
# define KEY_P1_DOWN z
# define KEY_P2_UP k
# define KEY_P2_DOWN m
# define RACKET_SIZE 3
# define BALL_SIZE 1
# define FIELD_WIDTH 80
# define FIELD_HEIGHT 25
# define FIELD_WIDTH_START 0
# define FIELD_HEIGHT_START 0
# define WIN_SCORE 21

void game_end();
void clear_screen();
void draw_pole(int player1_racket_x, int player1_racket_y, int player2_racket_x,
            int player2_racket_y, int ball_cur_pos_x, int ball_cur_pos_y);
//Structure of ball



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
    if (player1_score < 21 || player2_score < 21) {
		draw_pole (0, 0, 0, 0, 20, 20);
    } else {
		game_end();
	}
    return 0;
}

void game_end() {
	// Function displayed congratulations of winner
	printf("%s %s", "Game over", "What player");
}


void clear_screen() {
// Function nave to clean screen after move
}

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
