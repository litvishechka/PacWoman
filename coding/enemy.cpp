#include "enemy.h"
#include "map.h"
void Enemy::update() {
	if (restart_enemy) {
			for (int i = 0; i < 4; i++)
				TileMap[y[i]][x[i]] = ' ';

			x[0] = 8; x[1] = 9; x[2] = 10; x[3] = 9;
			y[0] = 9; y[1] = 9; y[2] = 9; y[3] = 8;

			TileMap[y[0]][x[0]] = '1';
			TileMap[y[1]][x[1]] = '2';
			TileMap[y[2]][x[2]] = '3';
			TileMap[y[3]][x[3]] = '4';

			for (int i = 0; i < 4; i++) {
				new_x[i] = x[i];
				new_y[i] = y[i];
			}

			restart_enemy = false;
	}
	else {
		delay++;

		if (delay >= 300) {
			for (int i = 0; i < 4; i++) {
				direction_movement[i] = rand() % 4 + 1;

				new_x[i] = x[i];
				new_y[i] = y[i];

				switch (direction_movement[i])
				{
				case 1:
					if (TileMap[y[i]][new_x[i] + 1] != 'A')
						new_x[i] += 1;
					break;
				case 2:
					if (TileMap[y[i]][new_x[i] - 1] != 'A')
						new_x[i] -= 1;
					break;
				case 3:
					if (TileMap[new_y[i] - 1][x[i]] != 'A')
						new_y[i] -= 1;
					break;
				case 4:
					if (TileMap[new_y[i] + 1][x[i]] != 'A')
						new_y[i] += 1;
					break;
				}
			}

			delay = 0;
		}

		for (int i = 0; i < 4; i++) {
			if (TileMap[new_y[i]][new_x[i]] == ' ' || TileMap[new_y[i]][new_x[i]] == 'B' || TileMap[new_y[i]][new_x[i]] == 'C') {
				if (TileMap[new_y[i]][new_x[i]] == 'B')
					TileMap[y[i]][x[i]] = 'B';
				else if (TileMap[new_y[i]][new_x[i]] == ' ')
						TileMap[y[i]][x[i]] = ' ';
				else if (TileMap[new_y[i]][new_x[i]] == 'C')
						life = false;

				if (i == 0)
					TileMap[new_y[i]][new_x[i]] = '1';
				if (i == 1)
					TileMap[new_y[i]][new_x[i]] = '2';
				if (i == 2)
					TileMap[new_y[i]][new_x[i]] = '3';
				if (i == 3)
					TileMap[new_y[i]][new_x[i]] = '4';

				x[i] = new_x[i];
				y[i] = new_y[i];
			}

			if (new_y[i] == 9 && (new_x[i] == 0 || new_x[i] == 18)) {
				if (new_x[i] == 0)
					new_x[i] = 17;
				else
					new_x[i] = 1;

				TileMap[y[i]][x[i]] = 'B';
				
				if (i == 0)
					TileMap[new_y[i]][new_x[i]] = '1';
				if (i == 1)
					TileMap[new_y[i]][new_x[i]] = '2';
				if (i == 2)
					TileMap[new_y[i]][new_x[i]] = '3';
				if (i == 3)
					TileMap[new_y[i]][new_x[i]] = '4';

				x[i] = new_x[i];
				y[i] = new_y[i];
			}
		}
	}
}
