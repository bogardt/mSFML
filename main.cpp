//
// mSFML
//

# include "mSFML_Window.hpp"
# include "Timer.hpp"


int             main(int, char *[])
{
  IGui          *gui = new mSFML_Window("msfml test window", 800, 600);
  // Timer         timerDragon;
  // unsigned int  timerTotal = 1000;
  // unsigned int  timerPart = 1000 / 3;

  while (gui->isAlive())
    {
      gui->clear();


      // if (timer.timerIn(timerTotal))
      //   {
      //     if (timer.timeLeft() < timerPart)
      //       gui->setTextureRecAt("./sprites/dragon.png",
      //                            0, 0,
      //                            0, 0,
      //                            200, 200);
      //     else if (timer.timeLeft() < timerPart * 2)
      //       gui->setTextureRecAt("./sprites/dragon.png",
      //                            0, 0,
      //                            200, 0,
      //                            200, 200);
      //     else
      //       gui->setTextureRecAt("./sprites/dragon.png",
      //                            0, 0,
      //                            400, 0,
      //                            200, 200);
      //   }
      // else
      //   timer.resetState();



      gui->handleEvents();
      gui->display();
    }
  return (0);
}
