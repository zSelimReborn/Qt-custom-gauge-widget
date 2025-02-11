#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class SwitchButton; }
QT_END_NAMESPACE

class SwitchButton : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchButton)

public:
  enum Style
  {
    YESNO,
    ONOFF,
    BOOL,
    EMPTY
  };

public:
    SwitchButton(QWidget *parent = nullptr, Style style = Style::ONOFF);
    ~SwitchButton();


  //-- QWidget methods
  void mousePressEvent(QMouseEvent *) override;
  void paintEvent(QPaintEvent* event) override;
  void setEnabled(bool);

  //-- Setters
  void setDuration(int);
  void setValue(bool);

  //-- Getters
  bool value() const;

signals:
  void valueChanged(bool newvalue);

private:
    Ui::SwitchButton *ui;


private:
  class SwitchCircle;
  class SwitchBackground;
  void _update();

private:
  bool _value;
  int  _duration;

  QLinearGradient _lg;
  QLinearGradient _lg2;
  QLinearGradient _lg_disabled;

  QColor _pencolor;
  QColor _offcolor;
  QColor _oncolor;
  int    _tol;
  int    _borderradius;

  // This order for definition is important (these widgets overlap)
  QLabel*           _labeloff;
  SwitchBackground* _background;
  QLabel*           _labelon;
  SwitchCircle*     _circle;

  bool _enabled=true;

  QPropertyAnimation* __btn_move;
  QPropertyAnimation* __back_move;


};

class SwitchButton::SwitchBackground : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchBackground)

public:
  explicit SwitchBackground(QWidget* parent = nullptr, QColor color = QColor(154, 205, 50), bool rect = false);
  ~SwitchBackground() override;

  //-- QWidget methods
  void paintEvent(QPaintEvent* event) override;
  void setEnabled(bool);

private:
  bool            _rect;
  int             _borderradius;
  QColor          _color;
  QColor          _pencolor;
  QLinearGradient _lg;
  QLinearGradient _lg_disabled;

  bool _enabled;
};


class SwitchButton::SwitchCircle : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchCircle)

public:
  explicit SwitchCircle(QWidget* parent = nullptr, QColor color = QColor(255, 255, 255), bool rect = false);
  ~SwitchCircle() override;

  //-- QWidget methods
  void paintEvent(QPaintEvent* event) override;
  void setEnabled(bool);

private:
  bool            _rect;
  int             _borderradius;
  QColor          _color;
  QColor          _pencolor;
  QRadialGradient _rg;
  QLinearGradient _lg;
  QLinearGradient _lg_disabled;

  bool _enabled;
};

#endif // SWITCHBUTTON_H
