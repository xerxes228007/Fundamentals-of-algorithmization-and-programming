# Построитель и анализатор графов

## Блок-схема алгоритма поиска в ширину

Применяется в: `graph.cpp` в функции `QVector<int> Graph:: BFS(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected1(int selectedVertexNumber)`.

![Algorithm scheme](Schemes/Scheme1.png)

## Блок-схема алгоритма поиска в глубину

Применяется в: `graph.cpp` в функции `QVector<int> Graph:: DFS(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected2(int selectedVertexNumber)`.

![Algorithm scheme](Schemes/Scheme2.png)

## Блок-схема алгоритма Дейкстры

Применяется в: `graph.cpp` в функциях `QVector<QVector<int>> Graph::Dijkstra(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected3_1(int selectedVertexNumber)`.

![Algorithm scheme](Schemes/Scheme3.png)

## Блок-схема алгоритма Прима

Применяется в: `graph.cpp` в функции `QVector<QPair<int, int>> Graph::primMST()`. Далее результат используется в `vvoid MainWindow::onButton4Clicked()`.

![Algorithm scheme](Schemes/Scheme4.png)

## Блок-схема алгоритма Тарьяна

Применяется в: `graph.cpp` в функции `QVector<QVector<int>> Graph::tarjanSCC()`. Далее результат используется в `void MainWindow::onButton5Clicked()`.

![Algorithm scheme](Schemes/Scheme5.png)
