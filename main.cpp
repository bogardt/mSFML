//
// mSFML
//

# include "mSFML_Window.hpp"
# include "AnimatedSprite.hpp"

int		main(int, char *[])
{
  IGui		*gui = new mSFML_Window("msfml test window", 800, 600);

  // test for animated sprite patern
  AnimatedSprite ship(*gui, "./animatedSprites/r-typesheet42.gif",     0, 5,  1000, 166, 0,  17);
  AnimatedSprite monsterA(*gui, "./animatedSprites/r-typesheet17.gif", 0, 8,  1000, 522, 0,  132);
  AnimatedSprite monsterB(*gui, "./animatedSprites/r-typesheet17.gif", 0, 8,  1000, 522, 0,  132);
  AnimatedSprite fire1(*gui, "./animatedSprites/r-typesheet3.gif",     0, 12, 500, 205,  0,  18);
  AnimatedSprite fire2(*gui, "./animatedSprites/r-typesheet1.gif",     4, 16, 1000, 532, 20, 30, 8);
  AnimatedSprite enemyShip(*gui, "./animatedSprites/r-typesheet5.gif", 8, 16, 2000, 533, 0,  36, 16);

  // test for fun
  bool fireBallIsLaunch = false;

  monsterA.setX(100).setY(100);
  monsterB.setX(300).setY(300);
  fire1.setX(400).setY(400);
  fire2.setX(200).setY(200);
  enemyShip.setX(500).setY(500);

  while (gui->isAlive())
    {
      gui->clear();
      gui->handleEvents();
      if (fireBallIsLaunch)
        {
          fire1.setX(fire1.getX() + 0.2);
          fire1.setY(fire1.getY());
          if (fire1.getX() >= 800)
            fireBallIsLaunch = false;
        }
      if (gui->getKey() == IGui::Key::DOWN && ship.getY() < 580)
        ship.setY(ship.getY() + 0.2);
      if (gui->getKey() == IGui::Key::UP && ship.getY() >= 0)
        ship.setY(ship.getY() - 0.2);

      if (gui->getKey() == IGui::Key::SPACE)
        {
          fire1.setX(ship.getX()).setY(ship.getY());
          fireBallIsLaunch = true;
        }


      ship.update();
      monsterA.update();
      monsterB.update();
      enemyShip.update();
      fire1.update();
      fire2.update();






      gui->display();
    }
  return (0);
}
