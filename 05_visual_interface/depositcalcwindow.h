#ifndef SMARTCALC_05_VISUAL_INTERFACE_DEPOSITCALCWINDOW_H_
#define SMARTCALC_05_VISUAL_INTERFACE_DEPOSITCALCWINDOW_H_

#include <QMainWindow>
#include <QTableWidget>

extern "C" {
#include "../04_deposit_calculator/deposit_calculator.h"
}

namespace Ui {
class DepositCalcWindow;
}

class DepositCalcWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit DepositCalcWindow(QWidget* parent = nullptr);
  ~DepositCalcWindow();

 private slots:
  void on_pushButton_calculate_clicked();

  void generateData(struct deposit_input* pdata);
  void clickedAddRow();
  void addNewRow(QTableWidget* table, int month, double amount);

  void clickedRemoveRow();

  void print_result(struct deposit_output* result);

 private:
  Ui::DepositCalcWindow* ui;
};

#endif  // SMARTCALC_05_VISUAL_INTERFACE_DEPOSITCALCWINDOW_H_
