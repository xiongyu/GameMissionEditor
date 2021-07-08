#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QObject>
#include <QtPlugin>
#include "interface.h"

class PluginInterface
        : public QObject
        , public IPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.axiscode.PluginLib.CoreInterface" FILE "core.json")
    Q_INTERFACES(IPluginInterface)

public:
    explicit PluginInterface(QObject *parent = nullptr);
    ~PluginInterface();
    virtual GMEditorWindow* IInitWindow();

private:
    GMEditorWindow* _window = nullptr;

};

#endif // PLUGININTERFACE_H
