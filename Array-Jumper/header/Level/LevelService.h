#pragma once
namespace Level
{
	struct BoxDimension;
	class LevelController;
	class LevelService
	{
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		BoxDimension getBoxDimension();

	private:
		LevelController* level_controller;
	};

}