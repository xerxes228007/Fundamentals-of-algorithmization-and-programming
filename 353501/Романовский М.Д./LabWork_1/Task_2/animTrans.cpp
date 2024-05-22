#include "animTrans.h"
#include <qdebug.h>

AnimTrans::AnimTrans() : animTimer(this) {
  connect(&animTimer, &QTimer::timeout, this,
          QOverload<>::of(&AnimTrans::timerTrig));
  animTimer.setInterval(20);

  targetX = 0;
  targetY = 0;
  targetRotation = 0;
  targetScale = 1;
  targetTransX = 0;
  targetTransY = 0;

  x = 0;
  y = 0;
  rotation = 0;
  scale = 1;
  transX = 0;
  transY = 0;
}

void AnimTrans::setTargetX(float value) {
  targetX = value;
  animTimer.start();
}

void AnimTrans::setTargetY(float value) {
  targetY = value;
  animTimer.start();
}

void AnimTrans::setTargetRotation(float value) {
  targetRotation = value;
  animTimer.start();
}

void AnimTrans::setTargetScale(float value) {
  targetScale = value;
  animTimer.start();
}


void AnimTrans::setTransX(float value) {
  targetTransX = value;
  animTimer.start();
}

void AnimTrans::setTransY(float value) {
  targetTransY = value;
  animTimer.start();
}

float limit(float v, float l) {
  if (v < -l)
    return -l;
  if (v > l)
    return l;
  return v;
}

void AnimTrans::timerTrig() {
  bool shouldUpdate = false;
  shouldUpdate |= fabs(targetX - x) > 0.001;
  shouldUpdate |= fabs(targetY - y) > 0.001;
  shouldUpdate |= fabs(targetRotation - rotation) > 0.001;
  shouldUpdate |= fabs(targetScale - scale) > 0.001;
  shouldUpdate |= fabs(targetTransX - transX) > 0.001;
  shouldUpdate |= fabs(targetTransY - transY) > 0.001;

  x += limit(targetX - x, 2);
  y += limit(targetY - y, 2);

  rotation += limit(targetRotation - rotation, 1);
  scale += limit(targetScale - scale, 0.05);


  transX += limit(targetTransX - transX, 2);
  transY += limit(targetTransY - transY, 2);

  if (shouldUpdate) {
    emit animationUpdate();
  } else {
    animTimer.stop();
  }
}