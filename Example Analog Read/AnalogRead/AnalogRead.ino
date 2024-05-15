#define history_length 50
int history[history_length];
int history_counter = 0;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
}

void loop() {
  // read the analog / millivolts value for pin 2:
  int max_val=0;
  int min_val=5000;
  int analogValue = analogRead(2);
  history_counter++;
  if(history_counter == history_length){history_counter = 0;}
  history[history_counter] = analogValue;
  //int analogVolts = analogReadMilliVolts(2);
  
  for(int i=0; i<history_length; i++)
  {
    if(history[i] > max_val){max_val = history[i];}
    if(history[i] < min_val){min_val = history[i];}
  }

  int mid_val = ((max_val - min_val)/2) + min_val;
  
  // print out the values you read:
  Serial.printf("ADC analog value = %d\n",analogValue);
  Serial.printf("Mid value = %d\n",mid_val);
  //Serial.printf("ADC millivolts value = %d\n",analogVolts);
  if(analogValue > mid_val)
  {
    Serial.printf("LED OFF\n");
  }
  else
  {
    Serial.printf("LED ON\n");
  }
  
  delay(100);  // delay in between reads for clear read from serial
}
