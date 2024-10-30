#pragma once
namespace Level
{
	class LevelModel;
	class LevelView;
	class LevelController
	{
	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

	private:
		LevelModel* level_model;
		LevelView* level_view;
	};
}