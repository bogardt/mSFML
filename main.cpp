//
// mSFML
//

# include "mSFML_Window.hpp"
# include "Timer.hpp"


// exemple for a case A
class           A
{
public:
  A(IGui &gui,
    const std::string &path,
    const unsigned int nbFrames,
    const unsigned int timerTotal,
    const unsigned int WidthSprite,
    const unsigned int HeightSprite) : _gui(gui),
                                       _path(path),
                                       _timer(),
                                       _nbFrames(nbFrames),
                                       _timerTotal(timerTotal),
                                       _timerPart(timerTotal / nbFrames),
                                       _posX(WidthSprite / nbFrames),
                                       _posY(HeightSprite),
                                       _actualFrame(0)
  {
    _x = 0;
    _y = 0;
  }

  ~A()
  {}

  A&          setX(const unsigned int x) {_x = x;}
  A&          setY(const unsigned int y) {_y = y;}

  void          update()
  {
    if (_timer.timerIn(_timerTotal))
      {
        if ((_timer.timeLeft() % _timerPart) == 0 && _timer.timeLeft() != _timerTotal)
          if (_posX * _timer.timeLeft() / (_timerTotal / 10) < _posX * _nbFrames)
            _actualFrame = _timer.timeLeft() / (_timerTotal / 10);
        _gui.setTextureRecAt(_path, _x, _y, _posX * _actualFrame, 0, _posX, _posY);
      }
    else
      {
        _actualFrame = 0;
        _timer.reset();
      }

  }
private:
  IGui          &_gui;
  const std::string _path;
  unsigned int  _x;
  unsigned int  _y;
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
  A             ship(*gui, "./animatedSprites/r-typesheet42.gif", 5, 500, 166, 86);
  A             monsterA(*gui, "./animatedSprites/r-typesheet17.gif", 8, 1000, 522, 132);

  monsterA.setX(100).setY(100);
  while (gui->isAlive())
    {
      gui->clear();

      ship.update();
      monsterA.update();

      gui->handleEvents();
      gui->display();
    }
  return (0);
}
