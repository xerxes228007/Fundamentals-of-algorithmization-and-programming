# РАЗРАБОТКА ПРОГРАММЫ НА ЯЗЫКЕ С++, С ИСПОЛЬЗОВАНИЕМ ФРЕЙМВОРКА QT, РЕАЛИЗУЮЩАЯ ИГРУ МОРСКОЙ БОЙ

## Функциональная схема программы

![Algorithm scheme](schemes/1.png)

## Блок-схема алгоритма, реализующая авторассановку кораблей

Применяется в `src/effects/Utils.h` в функции `Utils::ef_fft`.

![Algorithm scheme](schemes/2.png)

## Блок-схема алгоритма, реализующая проверку на корректное расположение кораблей

Применяется в `src/effects/FFTProcessor.cpp` в функции `FFTProcessor::_process`.

![Algorithm scheme](schemes/3.png)

## Блок-схема алгоритма, реализующая алгоритм стрельбы для бота

Применяется в `src/effects/Reverb.cpp` в функции `Reverb::_process`.

![Algorithm scheme](schemes/4.png)

## Блок-схема алгоритма, реализующая проверку на целостность корабля

Применяется в `src/effects/TimePitch.cpp` в функции `TimePitch::_process`.

![Algorithm scheme](schemes/5.png)

## Блок-схема алгоритма, реализующая статистику побед и поражений в игре

Применяется в `src/effects/Pitch.cpp` в функции `Pitch::processFftChunk`.

![Algorithm scheme](schemes/6.png)
