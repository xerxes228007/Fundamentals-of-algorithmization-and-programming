#pragma once

#include <QTimer>
#include <qobject.h>
#include <qpoint.h>
#include <qtmetamacros.h>

class AnimTrans : public QObject {
  Q_OBJECT

public:
  AnimTrans();

  void setTargetX(float);
  void setTargetY(float);
  void setTargetRotation(float);
  void setTargetScale(float);

  void setTransX(float);
  void setTransY(float);

signals:
  void animationUpdate();

private slots:
  void timerTrig();

private:
  float targetX;
  float targetY;
  float targetRotation;
  float targetScale;

  float targetTransX;
  float targetTransY;

  QTimer animTimer;

public:
  float x;
  float y;
  float rotation;
  float scale; 

  float transX;
  float transY;
};