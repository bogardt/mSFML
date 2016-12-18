#ifndef         __ANIMATED_SPRITE_HPP__
# define        __ANIMATED_SPRITE_HPP__

# include       <string>
# include       "IGui.hpp"
# include       "Timer.hpp"

class		AnimatedSprite
{
public:

  explicit AnimatedSprite(IGui &gui,
        		  const std::string &path,
        		  const unsigned int initFrame,
        		  const unsigned int nbFrames,
        		  const unsigned int timerTotal,
        		  const unsigned int WidthSprite,
        		  const unsigned int HeightSprite);

  explicit AnimatedSprite(IGui &gui,
			  const std::string &path,
			  const unsigned int initFrame,
			  const unsigned int nbFrames,
			  const unsigned int timerTotal,
			  const unsigned int WidthSprite,
			  const unsigned int HeightSprite,
			  const unsigned int considerateFrame);

  ~AnimatedSprite();

  AnimatedSprite &setX(const float x);
  AnimatedSprite &setY(const float y);
  float  getX() const {return _x;}
  float  getY() const {return _y;}
  void		update();

private:
  IGui		&_gui;
  Timer		_timer;
  const std::string _path;
  float         _x;
  float         _y;
  unsigned int	_initFrame;
  unsigned int	_nbFrames;
  unsigned int	_timerTotal;
  unsigned int	_timerPart;
  unsigned int	_offsetX;
  unsigned int	_offsetY;
  unsigned int	_actualTile;
  unsigned int	_actualFrame;
  unsigned int	_considerateFrame;

};

#endif          // __ANIMATED_SPRITE_HPP__
