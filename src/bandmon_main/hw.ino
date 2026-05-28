
// Radio pins

// COR pin attach as an interupt to get events and use milsto export the data

void init_io(){

  //attachInterrupt(digitalPinToInterrupt(SQL_pin), ISR,CHANGE);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SQL_pin,INPUT);

  pinMode(wifi_reset_btn, INPUT);  //wifi button

}


float noise_cal(){
  // Noise level calibration

  float ns_avg = 0.0;

  

  for (int i = 0; i < 500; i++) {
    ns_avg += analogRead(analog_in);
    delay(10);
  }
  ns_avg = ns_avg / 500 + 10.0;  //add 50 as a safety factor
  Serial.print("i noice level:");
  Serial.println(ns_avg);

  return ns_avg;
}