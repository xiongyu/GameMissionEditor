#include <QApplication>
#include <QPluginLoader>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

#include "interface.h"

static inline
int loadPlugins()
{
    const QString pluginsdir = qApp->applicationDirPath() + "/plugins";
    const QString corpluginfilepath = pluginsdir + "/core.dll";

    // load core plugin first.
    QPluginLoader coreloader(corpluginfilepath);
    IPluginInterface *coreplugin = qobject_cast<IPluginInterface*>(coreloader.instance());
    if ( nullptr == coreplugin )
    {
        QMessageBox::critical(nullptr
                              , QObject::tr("Error")
                              , QObject::tr("Can not load core plugin, Please check."));
        return 1;
    }
    GMEditorWindow* window = coreplugin->IInitWindow();

    // load other plugin
    QDir pdir(pluginsdir);
    auto entrylist = pdir.entryList(QDir::Files);
    foreach (QString filename, entrylist)
    {
        //qDebug() << pdir.absoluteFilePath(filename) << "IEntry";

        QPluginLoader* pluginloader = new QPluginLoader(pdir.absoluteFilePath(filename));
        //qDebug() << pluginloader;
        if ( pluginloader->load() )
        {
            auto ins = pluginloader->instance();
            IPluginInterface *plugin = qobject_cast<IPluginInterface*>(ins);
            if( plugin )
            {
                plugin->IEntry(window);
            }
        }
    }

    return 0;
}

#include <Windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QCoreApplication::addLibraryPath("./plugins");
    SetDllDirectoryA("./plugins");

    int ret = loadPlugins();
    if ( ret ) return ret;
    return a.exec();
}
