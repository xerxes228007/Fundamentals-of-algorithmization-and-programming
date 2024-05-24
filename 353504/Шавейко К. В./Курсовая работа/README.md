СОЗДАНИЕ ПРИЛОЖЕНИЯ ДЛЯ ИГРЫ В БИЛЬЯРД
Данная папка содержит разработанный курсовой проект с блок-схемами пяти алгоритмов,а также с ссылками на реализацию данных алгоритмов в программе.
Блок-схема алгоритма, реализующего расчёт столкновения шаров.
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/basegame.cpp в функции resolveBallCollision(Ball &b1, Ball &b2, QVector2D collisionVector) , результат работы обрабатывается в функции void BaseGame::update(float dtime).
Блок-схема алгоритма, реализующего отражение шара от края стола.
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/basegame.cpp в функции resolveTableCollision(Ball &b, QVector2D collisionVector), результат работы обрабатывается в функции  void BaseGame::update(float dtime).
Блок-схема алгоритма, реализующего совершение удара с помощью событий мыши.
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/cueballcontrolfeature.cpp в функции CueBallControlFeature() , результат работы обрабатывается в функции handleEvent(QMouseEvent* mouse).
Блок-схема алгоритма, реализующего взаимодействие шаров с лузами на столе.
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/pocketinteractionfeature.cpp в функции void PocketInteractionFeature::update(float dtime), результат работы обрабатывается в функции GameFeature::update(dtime).
Блок-схема алгоритма, реализующего визуализацию направления удара.
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/pocketinteractionfeature.cpp в функции void PocketInteractionFeature::draw(QPainter& painter), результат работы обрабатывается в функции GameFeature::draw(painter).
