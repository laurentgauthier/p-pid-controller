#ifndef PID_H
#define PID_H

#include <vector>

class PID {
public:
  /*
  * Errors
  */
  double previous_input;
  double integral_input;

  std::vector<double> history;
  int history_size;
  int history_index;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  double Compute(double input);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
