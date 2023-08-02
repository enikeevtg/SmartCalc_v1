#ifndef CREDITCALCWINDOW_H
#define CREDITCALCWINDOW_H

#include <QMainWindow>

extern "C" {
#include "../03_credit_calculator/credit_calculator.h"
}

namespace Ui {
class CreditCalcWindow;
}

class CreditCalcWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit CreditCalcWindow(QWidget *parent = nullptr);
  ~CreditCalcWindow();

 private slots:

  void on_pushButton_calculate_clicked();
  void print_result(struct credit_output *result);

 private:
  Ui::CreditCalcWindow *ui;
};

#endif  // CREDITCALCWINDOW_H
