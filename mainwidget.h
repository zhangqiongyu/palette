#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "paintarea.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>
#include <QColor>
#include <QColorDialog>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    PaintArea *paintArea;

    QLabel *shapeLabel;
    QComboBox *shapeCombobox;
    QLabel *penWidthLabel;
    QSpinBox *penWidthSpinBox;
    QLabel *penColorLabel;
    QFrame *penColorFrame;
    QPushButton *penColorBtn;
    QLabel *penStyleLabel;
    QComboBox *penStyleComboBox;
    QLabel *penCapLabel;
    QComboBox *penCapComboBox;
    QLabel *penJoinLabel;
    QComboBox *penJoinComboBox;
    QLabel *fillRuleLabel;
    QComboBox *fillRuleComboBox;
    QLabel *spreadLabel;
    QComboBox *spreadComboBox;
    QGradient::Spread spread;
    QLabel *brushStyleLabel;
    QComboBox *brushStyleComboBox;
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QPushButton *brushColorBtn;

    QGridLayout *rightLayout;

protected slots:
    void showShape(int);
    void showPenWidth(int);
    void showPenColor();
    void showPenStyle(int);
    void showPenCap(int);
    void showPenJoin(int);
    void showSpreadStyle();
    void showFillRule();
    void showBrushColor();
    void showBrush(int);
};

#endif // MAINWIDGET_H
