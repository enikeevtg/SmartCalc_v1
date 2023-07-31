#ifndef SMARTCALC_06_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_
#define SMARTCALC_06_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_

#include <math.h>

enum { ANNUITY, DIFFER };

struct credit_input {
  double total_ammount;
  int term;
  double rate;  // in percentages
};

struct credit_output {
  double first_month_payment;
  double last_month_payment;
  double overpayment;
  double total_payment;
};

struct credit_output credit_calculation(struct credit_input* pdata, int credit_type);

#endif  // SMARTCALC_06_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_
