#ifndef GMEWINDOW_H
#define GMEWINDOW_H

#include "interface.h"

class MainWindow;
class GMEWindow : public GMEditorWindow
{

public:
    explicit GMEWindow();
    ~GMEWindow();

private:
    MainWindow* _mainwindow = nullptr;

public: //virtual
    virtual QString getAppVersion();
    virtual QMenuBar* getMenuBar();
    virtual QTextEdit* getOutputConsole();

};

#endif // GMEWINDOW_H
