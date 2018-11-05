#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SnakeSquad.h"
#include "BrainMemory.h"
#include "SnakeView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    SnakeSquad      p_sq;
    BrainMemory     p_bm;
    SnakeView       p_sv;
    int             p_ngen;
    int             p_maxscore;
    bool            p_evolving;

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void        Go();
    void        Stop();
    void        Save();
    void        Play();
    void        PlayLast();
    void        closeEvent(QCloseEvent* event);

};

#endif // MAINWINDOW_H
