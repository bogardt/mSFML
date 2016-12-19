# include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(IGui &gui,
                               const std::string &path,
                               const unsigned int initFrame,
                               const unsigned int nbFrames,
                               const unsigned int timerTotal,
                               const unsigned int WidthSprite,
                               const unsigned int StartHeight,
                               const unsigned int HeightSprite)
  : _gui(gui),
    _timer(),
    _path(path),
    _x(0), _y(0),
    _actualFrame(initFrame),
    _actualTile(initFrame),
    _initFrame(initFrame),
    _nbFrames(nbFrames),
    _timerTotal(timerTotal),
    _timerPart(timerTotal / nbFrames),
    _offsetX(WidthSprite / nbFrames),
    _offsetY(HeightSprite),
    _considerateFrame(nbFrames),
    _startHeight(StartHeight)
{
}

AnimatedSprite::AnimatedSprite(IGui &gui,
                               const std::string &path,
                               const unsigned int initFrame,
                               const unsigned int nbFrames,
                               const unsigned int timerTotal,
                               const unsigned int WidthSprite,
                               const unsigned int StartHeight,
                               const unsigned int HeightSprite,
                               const unsigned int considerateFrame)
  : _gui(gui),
    _timer(),
    _path(path),
    _x(0), _y(0),
    _actualFrame(initFrame),
    _actualTile(initFrame),
    _initFrame(initFrame),
    _nbFrames(nbFrames),
    _timerTotal(timerTotal),
    _timerPart(timerTotal / nbFrames),
    _offsetX(WidthSprite / nbFrames),
    _offsetY(HeightSprite),
    _considerateFrame(considerateFrame),
    _startHeight(StartHeight)

{
}

AnimatedSprite::~AnimatedSprite()
{}

float          AnimatedSprite::getX() const
{
  return _x;
}

float          AnimatedSprite::getY() const
{
  return _y;
}

AnimatedSprite &AnimatedSprite::setX(const float x)
{
  _x = x;
  return *this;
}

AnimatedSprite &AnimatedSprite::setY(const float y)
{
  _y = y;
  return *this;
}

AnimatedSprite &AnimatedSprite::setNbFrames(const unsigned int nbFrames)
{
  _nbFrames = nbFrames;
  return *this;
}

AnimatedSprite &AnimatedSprite::setInitFrame(const unsigned int initFrame)
{
  _initFrame = initFrame;
  return *this;
}

AnimatedSprite &AnimatedSprite::setConsiderateFrame(const unsigned int considerateFrame)
{
  _considerateFrame = considerateFrame;
  return *this;
}

void		AnimatedSprite::update(void)
{
  if (_timer.timerIn(_timerTotal))
    {
      if (_actualTile == _considerateFrame)
        {
          _actualTile = _initFrame;
          _actualFrame = _initFrame;
          _timer.reset();
          return ;
        }
      if ((_timer.timeLeft() % _timerPart) == 0 &&
          _timer.timeLeft() != _timerTotal &&
          _actualFrame != _timer.timeLeft() &&
          _actualTile < _considerateFrame)
        {
          _actualFrame = _timer.timeLeft();
          _actualTile++;
        }
      _gui.setTextureRecAt(_path, _x, _y, _offsetX * _actualTile, _startHeight, _offsetX, _offsetY);
    }
  else
    {
      _actualTile = _initFrame;
      _actualFrame = _initFrame;
      _timer.reset();
    }
}
