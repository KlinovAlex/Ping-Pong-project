void checking_ball_wall_racket_touching() {
	// The function checks the touch of the ball with the right and left walls.
	// When touched, a point is scored for player1 if the ball touches the right wall, and player2 if the ball touches the left wall.
	if(ball_cur_pos_x == FIELD_WIDTH) {
		player1_score += player1_score	
	}
	else (ball_cur_pos_x == FIELD_WIDTH_START) {
		player2_score += player2_score
	}
}