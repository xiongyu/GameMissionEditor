#include "gmeditorwindow.h"
#include "mainwindow.h"

GMEWindow::GMEWindow()
    : GMEditorWindow()
{
    _mainwindow = new MainWindow;
    _mainwindow->show();
}

GMEWindow::~GMEWindow()
{
    delete _mainwindow;
}

QString GMEWindow::getAppVersion()
{
    return "(0, 0, 0)";
}

QMenuBar *GMEWindow::getMenuBar()
{
    return nullptr;
}

QTextEdit *GMEWindow::getOutputConsole()
{
    return nullptr;
}
