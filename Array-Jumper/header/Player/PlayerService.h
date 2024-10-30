#pragma once
namespace Player
{
	class PlayerController;
	class PlayerService
	{
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

	private:
		PlayerController* player_conroller;
	};


}