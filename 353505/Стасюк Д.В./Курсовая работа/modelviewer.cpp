#include "modelviewer.h"
#include "ui_modelviewer.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>
#include <QtQuick3D/qquick3d.h>

ModelViewer::ModelViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModelViewer)
{
    ui->setupUi(this);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("modelUrl", QUrl::fromLocalFile(""));
    engine.load(QUrl(QStringLiteral("qrc:/mainQuat.qml")));
}

ModelViewer::~ModelViewer()
{
    delete ui;
}
