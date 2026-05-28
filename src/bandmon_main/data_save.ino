
void print_user_data(){
  Serial.println();
  Serial.printf("i user_call:%s\n",user_data.user_call);
  Serial.printf("i repeater_call:%s\n",user_data.rptr_call);
  Serial.printf("i state:%s\n",user_data.state);
  //Serial.printf("i mqtt server:%s:%s\n",user_data.mqtt_svr,user_data.port);
  Serial.printf("i mqtt svr:%s\n",user_data.mqtt_svr);
  Serial.printf("i mqtt port:%d\n",user_data.port);
  Serial.printf("i timeout:%d\n",user_data.timeout);
  Serial.printf("i audio cutoff:%f\n",user_data.audio_cutoff);
}


  // void EEMROM_init(){
  //    strcpy(user_data.mqtt_svr, custom_mqtt_server.getValue());
  //   strcpy(user_data.user_call, custom_user_call.getValue());
  //   strcpy(user_data.rptr_call, custom_user_rcall.getValue());
  //   strcpy(user_data.state, custom_user_state.getValue());
  //   user_data.port = atoi(custom_mqtt_port.getValue());
  //   user_data.audio_cutoff = atoi(custom_user_cutoff.getValue());
  // }

void read_EEPROM_wifi(){

  EEPROM.begin(512);
  // dump eeprom data
  EEPROM.get(0, wifi_data); 
  EEPROM.get(sizeof(wifi_data)+1,user_data);
  print_user_data();

}


void write_EEPROM_wifi(){
  //write user and wifi data to EEPROM
  Serial.println("Data saving to EEPROM");
  EEPROM.begin(512);
  EEPROM.put(0,wifi_data);
  EEPROM.put(sizeof(wifi_data)+1,user_data);
  EEPROM.commit();
}


