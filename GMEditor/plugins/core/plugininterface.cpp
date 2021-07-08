#include "plugininterface.h"
#include <QFile>
#include <QApplication>
#include "gmeditorwindow.h"

PluginInterface::PluginInterface(QObject *parent)
    : QObject(parent)
{
    _window = new GMEWindow;
}

PluginInterface::~PluginInterface()
{
    delete _window;
}

GMEditorWindow *PluginInterface::IInitWindow()
{
    return _window;
}
