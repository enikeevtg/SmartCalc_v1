#ifndef SMARTCALC_04_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_
#define SMARTCALC_04_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_

#include <math.h>
#include <stdlib.h>

enum { SIMPLE, COMPOUND };

#define VALID_ACCOUNT_BALANCE 0
#define INVALID_ACCOUNT_BALANCE 1

struct deposit_input {
  int term;
  int periodicity;
  double total_begin;
  double deposit_rate;  // in percentages
  double tax_rate;
  double* replenishments;
  double* withdrawals;
};

struct deposit_output {
  double accrued_interest;
  double tax_amount;
  double total_end;
};

int deposit_calculation(struct deposit_input* pdata,
                        struct deposit_output* presult, int deposit_type);

#endif  // SMARTCALC_04_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_
