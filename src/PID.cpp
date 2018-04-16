#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    previous_input = 0.0;
    integral_input = 0.0;
    history_size = 100;
    history_index = 0;
}

double PID::Compute(double input) {
    double delta = input - previous_input;
    double output = -input * Kp - delta * Kd - integral_input * Ki;
    previous_input = input;
    // Keep a sliding window of the integral term.
    if (history.size() < history_size) {
        history.push_back(input);
        integral_input = integral_input + input;
    } else {
        integral_input = integral_input + input - history[history_index];
        history[history_index++] = input;
        if (history_index = history_size) history_index = 0;
    }
    // output is constrained to the [-1, +1] range, so we clamp its value.
    if (output < -1.0) output = -1.0;
    if (output > +1.0) output = +1.0;
    return output;
}

double PID::TotalError() {
}

