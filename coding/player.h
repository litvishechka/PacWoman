class Player {
public:
	float frame = 0;
	int x = 9, y = 15;
	int new_x = 0, new_y = 0;
	int direction_movement = 1, delay = 0;
	int score = 0;

	void update();
};