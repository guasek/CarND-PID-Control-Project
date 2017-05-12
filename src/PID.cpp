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

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    previous_cte = 0;
    previous_timestamp = clock();
}

void PID::UpdateError(double cte) {
    clock_t current_time = clock();
    this->p_error = cte;
    this->i_error += cte;
    this->d_error = (cte - this->previous_cte) / ((float)(current_time - this->previous_timestamp ) / CLOCKS_PER_SEC) ;
    this->previous_cte = cte;
    this->previous_timestamp = current_time;
}

double PID::TotalError() {
    return (-this->Kp * this->p_error - this->Kd * this->d_error - this->Ki * this->i_error);
}

