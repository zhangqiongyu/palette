#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    paintArea = new PaintArea;

    shapeLabel = new QLabel(tr("形状:"));
    shapeCombobox = new QComboBox;
    shapeCombobox->addItem(tr("Line"), PaintArea::Line);
    shapeCombobox->addItem(tr("Rectangle"), PaintArea::Rectangle);
    shapeCombobox->addItem(tr("RoundedRect"), PaintArea::RoundRect);
    shapeCombobox->addItem(tr("Ellipse"), PaintArea::Ellipse);
    shapeCombobox->addItem(tr("Polygon"), PaintArea::Polygon);
    shapeCombobox->addItem(tr("Polyline"), PaintArea::Polyline);
    shapeCombobox->addItem(tr("Points"), PaintArea::Points);
    shapeCombobox->addItem(tr("Arc"), PaintArea::Arc);
    shapeCombobox->addItem(tr("Path"), PaintArea::Path);
    shapeCombobox->addItem(tr("Text"), PaintArea::Text);
    shapeCombobox->addItem(tr("PixMap"), PaintArea::PixMap);
    connect(shapeCombobox, SIGNAL(activated(int)), this, SLOT(showShape(int)));

    penColorLabel = new QLabel(tr("画笔颜色:"));
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(QPalette(Qt::blue));
    penColorBtn = new QPushButton(tr("更改"));
    connect(penColorBtn, SIGNAL(clicked(bool)), this, SLOT(showPenColor()));

    penWidthLabel = new QLabel(tr("画笔线宽:"));
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(showPenWidth(int)));

    penStyleLabel = new QLabel(tr("画笔风格:"));
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("SolidLine"));

    static_cast<int>(Qt::SolidLine);
    penStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(showPenStyle(int)));

    penCapLabel = new QLabel(tr("画笔顶帽:"));
    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
    penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
    penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
    connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(showPenCap(int)));

    penJoinLabel = new QLabel(tr("画笔连接:"));
    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
    connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(showPenJoin(int)));

    fillRuleLabel = new QLabel(tr("填充模式:"));
    fillRuleComboBox = new QComboBox;
    fillRuleComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);
    fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);
    connect(fillRuleComboBox, SIGNAL(activated(int)), this, SLOT(showFillRule()));

    spreadLabel = new QLabel(tr("铺展效果:"));
    spreadComboBox = new QComboBox;
    spreadComboBox->addItem(tr("PadSpread"), QGradient::PadSpread);
    spreadComboBox->addItem(tr("RepeatSpread"), QGradient::RepeatSpread);
    spreadComboBox->addItem(tr("ReflectSpread"), QGradient::ReflectSpread);
    connect(spreadComboBox, SIGNAL(activated(int)), this, SLOT(showSpreadStyle()));

    brushColorLabel = new QLabel(tr("画刷颜色:"));
    brushColorFrame = new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::green));
    brushColorBtn = new QPushButton(tr("更改"));
    connect(brushColorBtn, SIGNAL(clicked(bool)), this, SLOT(showBrushColor()));


    brushStyleLabel = new QLabel(tr("画刷风格:"));
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr(""), static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(showBrush(int)));

    rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel, 0, 0);
    rightLayout->addWidget(shapeCombobox, 0, 1);
    rightLayout->addWidget(penColorLabel, 1, 0);
    rightLayout->addWidget(penColorFrame, 1, 1);
    rightLayout->addWidget(penColorBtn, 1, 2);
    rightLayout->addWidget(penWidthLabel, 2, 0);
    rightLayout->addWidget(penWidthSpinBox, 2, 1);
    rightLayout->addWidget(penStyleLabel, 3, 0);
    rightLayout->addWidget(penStyleComboBox, 3, 1);
    rightLayout->addWidget(penCapLabel, 4, 0);
    rightLayout->addWidget(penCapComboBox, 4, 1);
    rightLayout->addWidget(penJoinLabel, 5, 0);
    rightLayout->addWidget(penJoinComboBox, 5, 1);
    rightLayout->addWidget(fillRuleLabel, 6, 0);
    rightLayout->addWidget(fillRuleComboBox, 6, 1);
    rightLayout->addWidget(spreadLabel, 7, 0);
    rightLayout->addWidget(spreadComboBox, 7, 1);
    rightLayout->addWidget(brushColorLabel, 8, 0);
    rightLayout->addWidget(brushColorFrame, 8, 1);
    rightLayout->addWidget(brushColorBtn, 8, 2);
    rightLayout->addWidget(brushStyleLabel, 9, 0);
    rightLayout->addWidget(brushStyleComboBox, 9, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout((rightLayout));
    mainLayout->setStretchFactor(paintArea, 1);
    mainLayout->setStretchFactor(rightLayout, 0);

    showShape(shapeCombobox->currentIndex());
}

void MainWidget::showShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(shapeCombobox->itemData(value, Qt::UserRole).toInt());
    paintArea->setShape(shape);
}

void MainWidget::showPenColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    penColorFrame->setPalette(QPalette(color));
    int value = penWidthSpinBox->value();

    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenWidth(int value)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenStyle(int styleValue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(styleValue, Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));

}

void MainWidget::showPenCap(int capValue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(capValue, Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenJoin(int joinValue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(joinValue, Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showFillRule()
{
    Qt::FillRule rule = Qt::FillRule(fillRuleComboBox->itemData(fillRuleComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setFillRule(rule);
}

void MainWidget::showSpreadStyle()
{
    spread = QGradient::Spread(spreadComboBox->itemData(spreadComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWidget::showBrushColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    brushColorFrame->setPalette(QPalette(color));
    showBrush(brushStyleComboBox->currentIndex());
}

void MainWidget::showBrush(int value)
{
    QColor color = brushColorFrame->palette().color(QPalette::Window);
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(value, Qt::UserRole).toInt());
    if (style == Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0, 0, 400, 400);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, color);
        linearGradient.setColorAt(1.0, Qt::black);
        linearGradient.setSpread(spread);
        paintArea->setBrush(linearGradient);
    }
    else if (style == Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200, 200, 150, 150, 100, 100);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, color);
        radialGradient.setColorAt(1.0, Qt::black);
        radialGradient.setSpread(spread);

        paintArea->setBrush(radialGradient);
    }
    else if (style == Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(100, 100, 30);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, color);
        conicalGradient.setColorAt(1.0, Qt::black);
        paintArea->setBrush(conicalGradient);
    }
    else if (style == Qt::TexturePattern)
    {
        paintArea->setBrush(QBrush(QPixmap("C:\\Users\\zhangqy\\Desktop\\Qttest\\PaintEx\\butterfly.png")));
    }
    else
    {
        paintArea->setBrush(QBrush(color, style));
    }
}

MainWidget::~MainWidget()
{

}
