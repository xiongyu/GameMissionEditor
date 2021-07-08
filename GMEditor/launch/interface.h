#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtPlugin>
#include <QMenuBar>
#include <QTextEdit>

class GMEditorWindow;
class IPluginInterface
{
public:
    virtual ~IPluginInterface() = default;
    virtual void IEntry(GMEditorWindow* window)
    { Q_UNUSED(window); };
    virtual GMEditorWindow* IInitWindow() { return nullptr; }
};

class GMEditorWindow
{

public:
    GMEditorWindow() {}
    virtual ~GMEditorWindow() {}

    virtual QString getAppVersion() = 0;

    virtual QMenuBar* getMenuBar() = 0;
    virtual QTextEdit* getOutputConsole() = 0;
};

#define InterfacePlugin_iid "Test.Plugin.InterfacePlugin"   // identify flag

Q_DECLARE_INTERFACE(IPluginInterface, InterfacePlugin_iid)

#endif // INTERFACE_H
