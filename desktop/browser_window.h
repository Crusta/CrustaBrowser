#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QTabBar>
#include <QToolBar>
#include <QToolButton>
#include <QWidget>

class CentralWidget;
class Tab;

class BrowserWindow : public QMainWindow
{
    CentralWidget *m_central_widget = nullptr;
    void setup_menubar();
public:
    explicit BrowserWindow(QWidget *parent = nullptr);
    Tab *add_new_tab();
    QList<Tab *> tabs() const;
};
