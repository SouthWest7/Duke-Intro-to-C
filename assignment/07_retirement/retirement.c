#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculator(int age, double balance, retire_info r) {
  printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
  return r.contribution + balance * (1 + r.rate_of_return / 100 / 12);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  int retireAge = startAge + working.months;
  int deadAge = retireAge + retired.months;
  for (int i = startAge; i < retireAge; i++) {
    initial = calculator(i, initial, working);
  }
  for (int i = retireAge; i < deadAge; i++) {
    initial = calculator(i, initial, retired);
  }
}


int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000.0;
  working.rate_of_return = 4.5;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 1.0;

  retirement(327, 21345.0, working, retired);

  return 0;
}
