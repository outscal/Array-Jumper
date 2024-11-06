#include "../../header/UI/GameOver/GameOverController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace UI
{
	namespace GameOverUI
    {
        using namespace Global;
        using namespace UIElement;
        using namespace Main;
        using namespace Graphics;
        using namespace Sound;

        GameOverController::GameOverController()
        {
            createText();
            createImage();
            createButtons();
        }

        GameOverController::~GameOverController()
        {
            destroy();
        }

        void GameOverController::createText()
        {
            title_text = new TextView();
			gameover_text = new TextView();
        }

        void GameOverController::createImage()
        {
            background_image = new ImageView();
        }

        void GameOverController::createButtons()
        {
            menu_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void GameOverController::initialize()
        {
            initializeText();
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void GameOverController::initializeText()
        {
            title_text->initialize(game_title, sf::Vector2f(0, text_top_offset), FontType::BUBBLE_BOBBLE, font_size, text_color);
			gameover_text->initialize(game_over_text, sf::Vector2f(0, text_top_offset + 150), FontType::BUBBLE_BOBBLE, font_size, text_color);
            title_text->setTextCentreAligned();
			gameover_text->setTextCentreAligned();
        }

        void GameOverController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void GameOverController::initializeButtons()
        {
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            menu_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void GameOverController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&GameOverController::menuButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&GameOverController::quitButtonCallback, this));
        }

        void GameOverController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void GameOverController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void GameOverController::update()
        {
            background_image->update();
            menu_button->update();
            quit_button->update();
            title_text->update();
			gameover_text->update();
        }

        void GameOverController::render()
        {
            background_image->render();
            menu_button->render();
            quit_button->render();
            title_text->render();
			gameover_text->render();
        }

        void GameOverController::show()
        {
            background_image->show();
            menu_button->show();
            quit_button->show();
            title_text->show();
			gameover_text->show();
        }

        void GameOverController::destroy()
        {
            delete (title_text);
			delete (gameover_text);
            delete (menu_button);
            delete (quit_button);
            delete (background_image);
        }
    }
}
