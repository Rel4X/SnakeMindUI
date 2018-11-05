#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->p_ngen = 0;
    this->p_maxscore = 0;
    this->p_evolving = false;

    QObject::connect(this->ui->pushButton_training_go, SIGNAL(clicked()), this, SLOT(Go()));
    QObject::connect(this->ui->pushButton_training_stop, SIGNAL(clicked()), this, SLOT(Stop()));
    QObject::connect(this->ui->pushButton_training_save, SIGNAL(clicked()), this, SLOT(Save()));
    QObject::connect(this->ui->pushButton_playing_play, SIGNAL(clicked()), this, SLOT(Play()));
    QObject::connect(this->ui->pushButton_playing_playlast, SIGNAL(clicked()), this, SLOT(PlayLast()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void        MainWindow::Go()
{
    int     g = 0;
    int     genmax = 0;
    bool    infinite = false;

    try
    {
        genmax = std::stoi(this->ui->lineEdit_training_generation->text().toStdString());
    }
    catch (...)
    {
        genmax = 0;
    }

    if (this->ui->checkBox_training_infinite->isChecked())
        infinite = true;

    this->p_evolving = true;
    while ((g < genmax || infinite) && this->p_evolving)
    {
        this->p_sq.Darwin(1);
        ++this->p_ngen;
        this->ui->lcdNumber_gencount->display(this->p_ngen);
        this->ui->lcdNumber_score->display((int)this->p_sq.GetDude(0)->GetScore());
        if ((int)this->p_sq.GetDude(0)->GetScore() > this->p_maxscore)
        {
            this->p_maxscore = this->p_sq.GetDude(0)->GetScore();
            this->ui->lcdNumber_max_score->display((int)this->p_maxscore);
        }
        QCoreApplication::processEvents();
        ++g;
    }
}

void        MainWindow::Stop()
{
    this->p_evolving = false;
    QCoreApplication::processEvents();
}

void        MainWindow::Save()
{
    if (this->ui->lineEdit_training_filename->text().size() > 0)
    {
        this->p_bm.Memorize(this->ui->lineEdit_training_filename->text().toStdString().c_str(), *this->p_sq.GetDude(0));
    }
    else
    {
        this->p_bm.Memorize("Brain.save", *this->p_sq.GetDude(0));
    }
}

void        MainWindow::Play()
{
    SnakeBrain  brain;

    if (this->ui->lineEdit_playing_filename->text().size() > 0)
    {
        if (this->p_bm.Remember(this->ui->lineEdit_playing_filename->text().toStdString().c_str(), brain))
            this->p_sv.Play(brain);
    }
}

void        MainWindow::PlayLast()
{
    this->p_sv.Play(*this->p_sq.GetDude(0));
}

void        MainWindow::closeEvent(QCloseEvent* event)
{
    this->p_evolving = false;
    QWidget::closeEvent(event);
}
