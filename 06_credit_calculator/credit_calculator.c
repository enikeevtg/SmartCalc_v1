#include "credit_calculator.h"

struct credit_output credit_calculation(struct credit_input* pdata, int credit_type) {
  struct credit_output result = {0};

  double total = pdata->total_ammount;
  double month_rate = pdata->rate / (100.0 * 12.0);
  double term = (double)(pdata->term);

  if (credit_type == ANNUITY) {
      result.first_month_payment =
          (total * month_rate) / (1 - pow(1.0 + month_rate, -term));
      result.total_payment = result.first_month_payment * term;
      result.overpayment = result.total_payment - pdata->total_ammount;
  } else {
      result.first_month_payment = 0.0;
      for (int month = 1; month <= (int)term; month++) {
        result.last_month_payment =
            total / term + (total - (month - 1) * (total / term)) * month_rate;
        if (result.first_month_payment == 0.0)
          result.first_month_payment = result.last_month_payment;
        result.total_payment += result.last_month_payment;
      }
      result.overpayment = result.total_payment - pdata->total_ammount;
  }
  return result;
}
