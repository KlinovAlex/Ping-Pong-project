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
# define POLE_WIDTH 80
# define POLE_HEIGHT 25
# define WIN_SCORE 21

void game_end();
void clear_screen();

//Structure of ball
struct ball {
    int pos_x ;
    int pos_y ;
}ball;

//Structure of player
struct player {
    int score ;
	int racket_x;
	int racket_y;
	int pressed_key;
	int score;
}player1, player2;

int main() {
	struct player1 *p1;
	struct player2 *p2;
    if (p1->score < 21 || p2->score < 21)

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

void draw_pole() {
// Function drawing pole
}
