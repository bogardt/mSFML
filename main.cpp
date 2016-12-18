//
// mSFML
//

# include "mSFML_Window.hpp"
# include "AnimatedSprite.hpp"

int		main(int, char *[])
{
  IGui		*gui = new mSFML_Window("msfml test window", 800, 600);
  // test for animated sprite patern
  AnimatedSprite ship(*gui, "./animatedSprites/r-typesheet42.gif", 0, 5, 1000, 166, 86);
  AnimatedSprite monsterA(*gui, "./animatedSprites/r-typesheet17.gif", 0, 8, 1000, 522, 132);
  AnimatedSprite monsterB(*gui, "./animatedSprites/r-typesheet17.gif", 0, 8, 1000, 522, 132);
  AnimatedSprite fire1(*gui, "./animatedSprites/r-typesheet3.gif", 0, 12, 500, 205, 18);
  AnimatedSprite fire2(*gui, "./animatedSprites/r-typesheet5.gif", 7, 16, 2000, 533, 36, 15);

  monsterA.setX(100).setY(100);
  monsterB.setX(300).setY(300);
  fire1.setX(400).setY(400);
  fire2.setX(500).setY(500);

  while (gui->isAlive())
    {
      gui->clear();

      ship.update();
      monsterA.update();
      monsterB.update();
      fire1.update();
      fire2.update();

      gui->handleEvents();
      gui->display();
    }
  return (0);
}
