//
// mSFML
//

# include "mSFML_Window.hpp"
# include "Timer.hpp"

class           A
{
public:
  A(IGui &gui,
    const unsigned int nbFrames,
    const unsigned int timerTotal,
    const unsigned int WidthSprite,
    const unsigned int HeightSprite) : _gui(gui),
                                       _timer(),
                                       _nbFrames(nbFrames),
                                       _timerTotal(timerTotal),
                                       _timerPart(timerTotal / nbFrames),
                                       _posX(WidthSprite / nbFrames),
                                       _posY(HeightSprite),
                                       _actualFrame(0)
  {}

  ~A()
  {}

  void          update()
  {
    if (_timer.timerIn(_timerTotal))
      {
        if ((_timer.timeLeft() % _timerPart) == 0 && _timer.timeLeft() != _timerTotal)
          if (_posX * _timer.timeLeft() / (_timerTotal / 10) < _posX * _nbFrames)
            _actualFrame = _timer.timeLeft() / (_timerTotal / 10);
        _gui.setTextureRecAt("./animatedSprites/r-typesheet42.gif",
                             0, 0, _posX * _actualFrame, 0, _posX, _posY);
      }
    else
      {
        _actualFrame = 0;
        _timer.reset();
      }

  }
private:
  IGui          &_gui;
  Timer         _timer;
  unsigned int  _nbFrames;
  unsigned int  _timerTotal;
  unsigned int  _timerPart;
  int           _actualFrame;
  int           _posX;
  int           _posY;

};

int             main(int, char *[])
{
  IGui          *gui = new mSFML_Window("msfml test window", 800, 600);
  A             ship(*gui, 5, 400, 166, 86);

  while (gui->isAlive())
    {
      gui->clear();

      ship.update();

      gui->handleEvents();
      gui->display();
    }
  return (0);
}
