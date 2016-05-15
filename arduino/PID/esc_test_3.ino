double Kp = 1.2;  //출력값
double Ki = 2.5;  //출력값
double Kd = 3.2;  //출력값
double error; //
double error_previous;

double desired_angle = 10;
double current_angle;

double P_control, I_control, D_control;
double Time = 0.004;
double PID_control;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  pidcontrol();

}

void pidcontrol() {

  current_angle; //갱신코드
  error = desired_angle - current_angle;

  P_control = Kp * error;
  I_control += Ki * error * Time;
  D_control = Kd * (error - error_previous) / Time;

  PID_control = P_control + I_control + D_control;
  PID_control = constrain(PID_control, 0, 255);
  analogWrite(6, PID_control);

  error_previous = error;


}
