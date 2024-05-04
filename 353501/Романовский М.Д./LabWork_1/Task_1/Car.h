#include "MovingRectangle.h"

class Car : public MovingRectangle {
public:
  Car();
  
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

public slots:
  void setLights(bool enabled);
  void setDoor(bool open);

private:
  bool lightEnabled;
  bool doorOpen;
  int doorAngle;
};