//
// mSFML
//

# include "mSFML_Window.hpp"

int		main(int, char *[])
{
  IGui		*gui = new mSFML_Window("msfml test window", 800, 600);

  Animation monster1 = gui->loadAnimation("./animatedSprites/r-typesheet3.gif");
  gui->addFrames(monster1, 12, 17, 0, 17, 17);
  Animation *monsterAnimation1 = &monster1;
  AnimatedSprite animatedSprite1(0.05, true, false);
  animatedSprite1.setPosition(800 / 2, 600 / 2);

  Animation monster2 = gui->loadAnimation("./animatedSprites/r-typesheet17.gif");
  gui->addFrames(monster2, 8, 66, 0, 61, 132);
  Animation *monsterAnimation2 = &monster2;
  AnimatedSprite animatedSprite2(0.1, true, false);
  animatedSprite2.setPosition(800 / 2 + 200, 600 / 2);


  float x = 0.f;
  float y = 0.f;
  float speed = 80.f;

  while (gui->isAlive())
    {
      gui->clear();
      gui->handleEvents();

      gui->updateAnimatedSprite(*monsterAnimation1, animatedSprite1, x, y);
      gui->updateAnimatedSprite(*monsterAnimation2, animatedSprite2, x, y);

      gui->update();
      gui->display();
    }
  return (0);
}
