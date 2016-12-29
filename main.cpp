//
// mSFML
//

# include "Window.hpp"

int		main(int, char *[])
{
  IGui		*gui = new Window("msfml test window", 800, 600);

  Animation monster1 = gui->loadAnimation("./animatedSprites/r-typesheet3.gif");
  gui->addFrames(monster1, 12, 17, 0, 17, 17);
  // Animation *monsterAnimation1 = &monster1;
  AnimatedSprite animatedSprite1(0.05, true, false);

  Animation monster2 = gui->loadAnimation("./animatedSprites/r-typesheet17.gif");
  gui->addFrames(monster2, 8, 66, 0, 61, 132);
  // Animation *monsterAnimation2 = &monster2;
  AnimatedSprite animatedSprite2(0.1, true, false);

  // monster3 / 2 animations type
  Animation player = gui->loadAnimation("./animatedSprites/player.png");
  gui->addFrames(player, 3, 32, 0, 32, 32);
  gui->addFrame(player, 32, 0, 32, 32);
  static const unsigned int horizontalOffset = 5;
  static const unsigned int verticalOffset = 5;

  Animation monster3 = gui->loadAnimation("./animatedSprites/r-typesheet30.gif");
  // gui->addFrames(monster3, 7, )
  // gui->addFrame(monster3, 20,           209 + 5, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, 209 + 5, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, 209 + 5, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  209 + 5,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 2) + 10, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 2) + 10, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 2) + 10, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 2) + 10,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 3) + 15, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 3) + 15, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 3) + 15, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 3) + 15,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 4) + 20, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 4) + 20, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 4) + 20, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 4) + 20,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 5) + 25, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 5) + 25, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 5) + 25, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 5) + 25,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 6) + 30, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 6) + 30, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 6) + 30, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 6) + 30,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 7) + 35, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 7) + 35, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 7) + 35, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 7) + 35,  167, 209);

  // gui->addFrame(monster3, 20,           (209 * 8) + 35, 167, 209);
  // gui->addFrame(monster3, (167*1) + 15, (209 * 8) + 35, 167, 209);
  // gui->addFrame(monster3, (167*2) + 10, (209 * 8) + 35, 167, 209);
  // gui->addFrame(monster3, (167*3) + 5,  (209 * 8) + 35,  167, 209);

  Animation *monsterAnimation3 = &monster3;
  AnimatedSprite animatedSprite3(0.1, true, false);
  AnimatedSprite animatedSprite4(0.5, true, false);
  float x = 0.f;
  float y = 0.f;
  float speed = 80.f;
  unsigned int i = 0;
  animatedSprite1.setAnimation(monster1);
  while (gui->isAlive())
    {
      gui->clear();
      gui->handleEvents();
      // gui->updateAnimatedSprite(monster2, animatedSprite2, 200, 0);
      gui->updateAnimatedSprite(animatedSprite1, 210, 40);
      // gui->updateAnimatedSprite(monster1, animatedSprite1, 210, 40);
      // monsterAnimation3 = &monster3;
      // gui->updateAnimatedSprite(*monsterAnimation3, animatedSprite3, 400, 200);
      // gui->updateAnimatedSprite(player, animatedSprite4, 500, 300);
      // gui->setTextureAt("player.png", 300, 300, 1.);

      gui->update();
      gui->display();
    }
  return (0);
}
