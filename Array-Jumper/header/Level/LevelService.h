#pragma once
namespace Level
{
	class LevelController;
	class LevelService
	{
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

	private:
		LevelController* level_controller;
	};

}