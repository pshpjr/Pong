#pragma once

class Player;
class Breakout;
class Client;

enum GameState
{
	PLAYING,
	INIT,
	MATCHING,
	GAMEREADY,
	LOBBY,
	WIN,
	DEAD,
};

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};
using pt = glm::vec2;
using PlayerRef = shared_ptr<Player>;

template <typename T>
void wrap(T& OUT data, T low, T high)
{
	ASSERT_CRASH(low < high);
	const T n = (data - low) % (high - low);
	data = (n >= 0) ? (n + low) : (n + high);
}
