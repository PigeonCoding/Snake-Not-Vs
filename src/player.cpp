#include "../include/player.h"

void Player::PlayerInit(Vector2 startingPos, int cell) {
	Player::pos = startingPos;
	Player::PlayerLastPos.push_back(startingPos);
	Player::cellSize = cell;
}

void Player::direction(){
	if (IsKeyPressed(KEY_S)) {
        dir = -1;
    }
    if (IsKeyPressed(KEY_W)) {
        dir = 1;

    }
    if (IsKeyPressed(KEY_D)) {
        dir = -2;

    }
    if (IsKeyPressed(KEY_A)) {
        dir = 2;
    }
	 Vector2 direction = { 0, 0 };

    if (canMove) {
        if (dir == 1) {
            direction.y -= cellSize;
        }
        if (dir == -1) {
            direction.y += cellSize;
        }
        if (dir == -2) {
            direction.x += cellSize;
        }
        if (dir == 2) {
            direction.x -= cellSize;
        }

        addPos(direction);
    }

    if (pos.x == foodPosX && pos.y == foodPosY) {
        size++;
        PlaySound(fxWav);
        foodPosX = -100;
        foodPosY = -100;
        hasEaten = false;
    }

    if (pos.x > 0 && pos.x < GetScreenWidth() - cellSize && pos.y > 0 && pos.y < GetScreenHeight()) {}
    else {
        dir = 0;
        dead = true;
    }

    MoveTimer(10);
}

void Player::addPos(Vector2 poss) {

	Player::PlayerLastPos.push_back(Player::pos);
	Player::pos.x += poss.x;
	Player::pos.y += poss.y;
}

void Player::MoveTimer(int delay) {
	if (Player::frameTimer > delay)
	{
		Player::frameTimer = 0;
		Player::canMove = true;
	}
	else {
		Player::frameTimer++;
		Player::canMove = false;
	}
}

void Player::DrawPlayer() {
	PlayerLastActivePos.clear();
	for (int v = 1; v < Player::size; v++) {
		if (v <= Player::PlayerLastPos.size()) {
			PlayerLastActivePos.push_back(PlayerLastPos[Player::PlayerLastPos.size() - v]);
			DrawRectangle(Player::PlayerLastPos[Player::PlayerLastPos.size() - v].x, Player::PlayerLastPos[Player::PlayerLastPos.size() - v].y, cellSize, cellSize, WHITE);
		}
	}

	for (int f = 1; f < PlayerLastActivePos.size(); f++) {
		if (pos.x == PlayerLastActivePos[f].x && pos.y == PlayerLastActivePos[f].y) {
			Player::dead = true;
		}
	}
}

void Player::spawnFood() {
	int gudX = 0;
	int gudY = 0;

	bool isGood = false;

	gudX = (GetRandomValue(cellSize, GetScreenWidth() / cellSize)) * 10;
	gudY = (GetRandomValue(cellSize, GetScreenHeight() / cellSize)) * 10;


	if (gudX % cellSize == 0 && gudY % cellSize == 0) {

		for (int f = 0; f < PlayerLastActivePos.size(); f++) {
			if (gudX + (float)cellSize / 2 != PlayerLastActivePos[f].x && gudY + (float)cellSize / 2 != PlayerLastActivePos[f].y) {
				isGood = true;
			}
			else
			{
				isGood = false;
			}
		}
	}
	else if (gudX % cellSize != 0 && gudY % cellSize != 0) {
		gudX = (GetRandomValue(cellSize, GetScreenWidth() / cellSize)) * 10;
		gudY = (GetRandomValue(cellSize, GetScreenHeight() / cellSize)) * 10;
	}

	if (isGood)
	{
		foodPosX = gudX + cellSize / 2;
		foodPosY = gudY + cellSize / 2;

		hasEaten = true;
	}
}
