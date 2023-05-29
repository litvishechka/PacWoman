#include "player.h"
#include "map.h"

void Player::update() {
	if (player_restart) {
		TileMap[y][x] = ' ';

		x = 9;
		y = 15;

		TileMap[y][x] = 'C';

		new_x = x;
		new_y = y;

		player_restart = false;
	}
	else {
		frame += 0.005;
		if (frame > 5) frame -= 5;
		delay++;
		if (delay >= 300) {
			switch (direction_movement) {
			case 1:
				if (TileMap[y][new_x + 1] != 'A') new_x += 1;
				break;
			case 2:
				if (TileMap[y][new_x - 1] != 'A') new_x -= 1;
				break;
			case 3:
				if (TileMap[new_y - 1][x] != 'A') new_y -= 1;
				break;
			case 4:
				if (TileMap[new_y + 1][x] != 'A') new_y += 1;
				break;
			}

			delay = 0;
		}

		if (TileMap[new_y][new_x] == ' ' || TileMap[new_y][new_x] == 'B') {
			if (TileMap[new_y][new_x] == ' ') {
				score++;
			}

			TileMap[y][x] = 'B';
			TileMap[new_y][new_x] = 'C';

			x = new_x;
			y = new_y;
		}

		if (TileMap[y][x] == '1' || TileMap[y][x] == '2' 
			|| TileMap[y][x] == '3' || TileMap[y][x] == '4') life = false;
		

		if (new_y == 9 && (new_x == 0 || new_x == 18)) {
			if (new_x == 0)
				new_x = 17;
			else
				new_x = 1;

			TileMap[y][x] = 'B';
			TileMap[new_y][new_x] = 'C';

			x = new_x;
			y = new_y;
		}
	}
}