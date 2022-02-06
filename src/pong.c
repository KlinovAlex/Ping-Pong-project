# include <stdio.h>

# define KEY_P1_UP 97
# define KEY_P1_DOWN 122
# define KEY_P2_UP 107
# define KEY_P2_DOWN 109
# define RACKET_SIZE 2
# define BALL_SIZE 1
# define FIELD_WIDTH 79
# define FIELD_HEIGHT 24
# define FIELD_WIDTH_START 0
# define FIELD_HEIGHT_START 0
# define WIN_SCORE 21
# define PLAYER_1_MOVE 1
# define PLAYER_2_MOVE 2
# define INDENT 1
# define BALL_MOVEMENT_LEFT -1
# define BALL_MOVEMENT_RIGHT 1
# define BALL_MOVEMENT_UP -1
# define BALL_MOVEMENT_DOWN 1

# define RACKET_P1_MOVEMENT_LEFT -1
# define RACKET_P1_MOVEMENT_RIGHT 1
# define RACKET_P1_MOVEMENT_UP -1
# define RACKET_P1_MOVEMENT_DOWN 1

# define RACKET_P2_MOVEMENT_LEFT -1
# define RACKET_P2_MOVEMENT_RIGHT 1
# define RACKET_P2_MOVEMENT_UP -1
# define RACKET_P2_MOVEMENT_DOWN 1

#define RAND_MAX 1e-6

#define clear() printf("\033[H\033[J")

void game_end();
void draw_pole(int player1_racket_x, int player1_racket_y, int player2_racket_x,
            int player2_racket_y, int ball_cur_pos_x, int ball_cur_pos_y);

// Ball definitions
int ball_position();
int ball_move(int x, int y);
void checking_ball_racket_touching();
void draw_ball();

// Players definitions
int get_vertical_center_position();
int player_turn(int ball_cur_pos_x);
void get_move();

// Map, draw definations
void map();
void map_generation(int x, int y);
void clear_screen();
void draw_part_racket();
int checking_ball_wall_racket_touching();

// Structure of ball
int ball_cur_pos_x = 10;
int ball_cur_pos_y = 10;
int ball_direction_v = 1;
int ball_direction_h = 1;

// Structure of player 1
int player1_offset = FIELD_WIDTH_START + INDENT;
int player1_racket_x;
int player1_racket_y;
int player1_pressed_key;
int player1_score;
int player1_direction_v = BALL_MOVEMENT_UP;
int player1_direction_h = BALL_MOVEMENT_LEFT;


// Structure of player 2
int player2_offset = FIELD_WIDTH - INDENT;
int player2_score;
int player2_racket_x;
int player2_racket_y;
int player2_pressed_key;
int player2_score;
int player2_direction_v = BALL_MOVEMENT_DOWN;
int player2_direction_h = BALL_MOVEMENT_RIGHT;


int whos_turn = PLAYER_1_MOVE;

int main() {
    player2_racket_y = FIELD_HEIGHT/2-1;
    player1_racket_x = player1_offset;
    player2_racket_x = player2_offset;
    int ball_status;
    map();
    ball_move(0, 0);
    int player_winner = 1;
    while (player_winner < WIN_SCORE) {
        clear();
        map();
        get_move(60);

        ball_status = ball_move(ball_cur_pos_x, ball_cur_pos_y);

        if (ball_status == PLAYER_2_MOVE) {
            map();
            ball_move(FIELD_WIDTH-20, 21-player2_score);
        }
        if (ball_status == PLAYER_1_MOVE) {
            map();
            ball_move(FIELD_WIDTH_START+20, 21-player1_score);
        }
        if (player1_score >= WIN_SCORE) {
            player_winner = WIN_SCORE;
        }
        if (player2_score >= WIN_SCORE) {
            player_winner = WIN_SCORE;
        }
    }
    game_end();
    return 0;
}

void game_end() {
    // Function displayed congratulations of winner

    if (player1_score >= WIN_SCORE) {
        printf("%s\n %s", "Game over ", "Player 1 WIN !!!!");
    }
    if (player2_score >= WIN_SCORE) {
        printf("%s\n %s", "Game over ", "Player 2 WIN !!!!");
    }
}


void clear_screen() {
// Function nave to clean screen after move
}


int ball_move(int x, int y) {
    // The function checks for going beyond the field boundaries and
    // changes the coordinates of the ball according to the move

    ball_cur_pos_x = x;
    ball_cur_pos_y = y;

    if (ball_direction_v == BALL_MOVEMENT_UP) {
        ball_cur_pos_y+=BALL_MOVEMENT_UP;
    }
    if (ball_direction_v == BALL_MOVEMENT_DOWN) {
        ball_cur_pos_y+=BALL_MOVEMENT_DOWN;
    }
    if (ball_direction_h == BALL_MOVEMENT_LEFT) {
        ball_cur_pos_x+=BALL_MOVEMENT_LEFT;
    }
    if (ball_direction_h == BALL_MOVEMENT_RIGHT) {
        ball_cur_pos_x+=BALL_MOVEMENT_RIGHT;
    }

    if (ball_cur_pos_x < FIELD_WIDTH_START) {
        player2_score +=1;
        whos_turn = PLAYER_1_MOVE;
        ball_direction_h = BALL_MOVEMENT_RIGHT;
        ball_direction_v = BALL_MOVEMENT_DOWN;
        return PLAYER_1_MOVE;
    }
    if (ball_cur_pos_x > FIELD_WIDTH) {
        player1_score +=1;
        whos_turn = PLAYER_2_MOVE;
        ball_direction_h = BALL_MOVEMENT_LEFT;
        ball_direction_v = BALL_MOVEMENT_UP;
        return PLAYER_2_MOVE;
    }
    if (ball_cur_pos_y < FIELD_HEIGHT_START) {
        ball_cur_pos_y = FIELD_HEIGHT_START;
        ball_cur_pos_y += BALL_MOVEMENT_DOWN;
        ball_direction_v = BALL_MOVEMENT_DOWN;
    }
    if (ball_cur_pos_y > FIELD_HEIGHT) {
        ball_cur_pos_y = FIELD_HEIGHT;
        ball_cur_pos_y += BALL_MOVEMENT_UP;
        ball_direction_v = BALL_MOVEMENT_UP;
    }
    player_turn(ball_cur_pos_x);
    return 0;
}

void put_ball_position(int x, int y) {
// Put ball position
    ball_cur_pos_x = x;
    ball_cur_pos_y = y;
}


int checking_ball_wall_racket_touching() {
// The function checks the touch of the ball with the right and left walls.
// When touched, a point is scored for player1 if the ball touches the right
// wall, and player2 if the ball touches the left wall.
    if (ball_cur_pos_x > FIELD_WIDTH) {
        player1_score += player1_score;
        return 1;
    } else {
        if (ball_cur_pos_x < FIELD_WIDTH_START) {
            player2_score += player2_score;
            return 2;
        }
    }
    return 0;
}

void checking_ball_racket_touching() {
// The function checks for touching rackets.
// When touched, changes the coordinates of thea
// ball to the opposite.

    if (player1_racket_x == ball_cur_pos_x-1
            && (ball_cur_pos_y == player1_racket_y
            || ball_cur_pos_y == player1_racket_y+RACKET_SIZE-1
            || ball_cur_pos_y == player1_racket_y+RACKET_SIZE) ) {
        ball_direction_h = BALL_MOVEMENT_RIGHT;
        ball_direction_v = player1_direction_v;
        whos_turn = PLAYER_2_MOVE;
    }

    if (player2_racket_x == ball_cur_pos_x+1
            && (ball_cur_pos_y == player2_racket_y
            || ball_cur_pos_y == player2_racket_y+RACKET_SIZE-1
            || ball_cur_pos_y == player2_racket_y+RACKET_SIZE) ) {
        ball_direction_h = BALL_MOVEMENT_LEFT;
        ball_direction_v = player2_direction_v;
        whos_turn = PLAYER_1_MOVE;
    }
}

int get_vertical_center_position() {
// Function define center of field
    return FIELD_WIDTH/2;
}


int player_turn(int ball_cur_pos_x) {
// Function defines players turn.
// If function returns 1 - Player 1 turned
// If function returns 0 - Player 2 turned

    if (ball_cur_pos_x <= get_vertical_center_position()) {
        whos_turn = PLAYER_1_MOVE;
        return PLAYER_1_MOVE;
    } else {
        whos_turn = PLAYER_2_MOVE;
        return PLAYER_2_MOVE;
    }
}


void get_move() {
// Function waiting players move define who's turn and write players y position
    char key_pressed;
    key_pressed = getchar();

    if (whos_turn == PLAYER_1_MOVE) {
        if (key_pressed == KEY_P1_UP) {
            player1_racket_y--;
            player1_direction_v = RACKET_P1_MOVEMENT_UP;
            if (player1_racket_y < FIELD_HEIGHT_START) {
                player1_racket_y = FIELD_HEIGHT_START;
            }
        }
        if (key_pressed == KEY_P1_DOWN) {
            player1_racket_y++;
            player1_direction_v = RACKET_P1_MOVEMENT_DOWN;
            if (player1_racket_y + RACKET_SIZE >= FIELD_HEIGHT) {
                player1_racket_y -= RACKET_SIZE - 1;
            }
        }
    }
    if (whos_turn == PLAYER_2_MOVE) {
        if (key_pressed == KEY_P2_UP) {
            player2_racket_y--;
            player2_direction_v = RACKET_P2_MOVEMENT_UP;
            if (player2_racket_y < FIELD_HEIGHT_START) {
                player2_racket_y = FIELD_HEIGHT_START;
            }
        }
        if (key_pressed == KEY_P2_DOWN) {
            player2_racket_y++;
            player2_direction_v = RACKET_P2_MOVEMENT_DOWN;
            if (player2_racket_y + RACKET_SIZE >= FIELD_HEIGHT) {
                player2_racket_y -= RACKET_SIZE - 1;
            }
        }
    }
    checking_ball_racket_touching();
}


void map() {
    // Fuction drawing playing field with all wrintings
    int special_char = 0;
        for (int map_y = FIELD_HEIGHT_START; map_y <= FIELD_HEIGHT; map_y++) {
            for (int map_x = FIELD_WIDTH_START; map_x <= FIELD_WIDTH; map_x++) {
            special_char = 0;
            if (ball_cur_pos_x == map_x && ball_cur_pos_y == map_y) {
                draw_ball();
                special_char = 1;
            }
            if (player1_racket_x == map_x && player1_racket_y == map_y) {
                draw_part_racket();
                special_char = 1;
            }
            if (player1_racket_x == map_x && player1_racket_y + RACKET_SIZE - 1 == map_y) {
                draw_part_racket();
                special_char = 1;
            }
            if (player1_racket_x == map_x && player1_racket_y + RACKET_SIZE == map_y) {
                draw_part_racket();
                special_char = 1;
            }
            if (player2_racket_x == map_x && player2_racket_y == map_y) {
                draw_part_racket();
                special_char = 1;
            }
            if (player2_racket_x == map_x && player2_racket_y + RACKET_SIZE - 1 == map_y) {
                draw_part_racket();
                special_char = 1;
            }
            if (player2_racket_x == map_x && player2_racket_y + RACKET_SIZE == map_y) {
                draw_part_racket();
                special_char = 1;
            }

            if (map_x == FIELD_WIDTH/2) {
                draw_part_racket();
                special_char = 1;
            }
            if (map_x == FIELD_WIDTH/2-((FIELD_WIDTH/2/2)) && map_y == FIELD_HEIGHT/2) {
                printf("%d", player1_score/10);
                special_char = 1;
            }

            if (map_x == FIELD_WIDTH/2-((FIELD_WIDTH/2/2))+1 && map_y == FIELD_HEIGHT/2) {
                printf("%d", player1_score%10);
                special_char = 1;
            }
            if (map_x == FIELD_WIDTH-FIELD_WIDTH/4 && map_y == FIELD_HEIGHT/2) {
                printf("%d", player2_score/10);
                special_char = 1;
            }

            if (map_x == FIELD_WIDTH-FIELD_WIDTH/4+1 && map_y == FIELD_HEIGHT/2) {
                printf("%d", player2_score%10);
                special_char = 1;
            }

            if (special_char == 0) {
                if (map_x == FIELD_WIDTH) {
                    printf("%s\n", " ");
                } else {
                    printf("%s", " ");
                }
            }
        }
    }
}

void draw_part_racket() {
    printf("|");
}

void draw_ball() {
    printf("o");
}
