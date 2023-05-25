class Enemy {
public:
	int x[4] = {8, 9, 10, 9}, y[4] = {9, 9, 9, 8};
	int new_x[4] = {0 , 0, 0, 0 }, new_y[4] = {0, 0, 0, 0};
	int direction_movement[4] = {1, 1, 1, 1}, delay = 0;

	void update();
};