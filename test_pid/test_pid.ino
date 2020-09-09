const int photores = A0;   // LDR input pin
const int pot = A1;        // Potentiometer input pin
const int led = 9;         // LED output pin
double lightLevel;         // Indirectly store the light level

double sensed_output, setpoint, control_signal;
double Kp = 0;
double Ki = 0;
double Kd = 0;
int T = 50;

unsigned long last_time;
double total_error, last_error;

void setup() {
 pinMode(led, OUTPUT);
 pinMode(photores, INPUT);
 pinMode(pot, INPUT);
 Serial.begin(9600);
}

void loop() {
  sensed_output = analogRead(photores);                 // Read the set point
  setpoint = analogRead(pot);
  PID_Control();
  analogWrite(led, control_signal);

 Serial.print("Setpoint = ");
 Serial.print(setpoint);
 Serial.print(" Input = ");
 Serial.print(control_signal);
 Serial.print(" Output = ");
 Serial.print(sensed_output);
 Serial.print("\n");
  
}

void PID_Control(){
  unsigned long current_time = millis();
  int delta_time = current_time - last_time;

  if (delta_time >=T){
    double error = setpoint - sensed_output;
    total_error += error;
    if (total_error >= 255) total_error = 255;
    else if (total_error <= 0) total_error = 0;
    double delta_error = error - last_error;

    control_signal = Kp*error + Ki*total_error + (Kd/T)*delta_error;
    if (control_signal >= 255) control_signal = 255;
    else if (control_signal <= 0) control_signal = 0;
    last_error = error;
    last_time = current_time;
    
  }
}
