#define history_length 50
int history[history_length];
int history_counter = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;

#define adc_buffer_len 100
uint16_t adc_buffer1[adc_buffer_len];
uint16_t adc_buffer2[adc_buffer_len];
uint16_t adc_buffer3[adc_buffer_len];

#define KEY_1_PIN 22
#define KEY_2_PIN 23
#define KEY_3_PIN 21

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  //Setup key's and set them high, a low is a key press
  pinMode(KEY_1_PIN, OUTPUT);
  pinMode(KEY_2_PIN, OUTPUT);
  pinMode(KEY_3_PIN, OUTPUT);
  digitalWrite(KEY_1_PIN, HIGH);
  digitalWrite(KEY_2_PIN, HIGH);
  digitalWrite(KEY_3_PIN, HIGH);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
  Serial.printf("Waiting for target to settle\n");
  delay(10000);
  Serial.printf("Running\n");

  //Serial.printf("Key 1\n");
  digitalWrite(KEY_1_PIN, LOW);
  time1=micros();
  for(int i=0; i<adc_buffer_len; i++)
  {
    adc_buffer1[i]=analogRead(2);
  }
  time2=micros();
  digitalWrite(KEY_1_PIN, HIGH);
  //Serial.printf("Micros Elapsed for ADC: %ul\n",time2-time1);

  /*
  for(int i=0; i<adc_buffer_len; i++)
  {
    Serial.printf("Key1:%d\n",adc_buffer[i]);
  }
  */
  
  delay(5000);

  //Serial.printf("Key 2\n");
  digitalWrite(KEY_2_PIN, LOW);
  time1=micros();
  for(int i=0; i<adc_buffer_len; i++)
  {
    adc_buffer2[i]=analogRead(2);
  }
  time2=micros();
  digitalWrite(KEY_2_PIN, HIGH);
  //Serial.printf("Micros Elapsed for ADC: %ul\n",time2-time1);

  //Serial.printf("Key 3\n");
  digitalWrite(KEY_3_PIN, LOW);
  time1=micros();
  for(int i=0; i<adc_buffer_len; i++)
  {
    adc_buffer3[i]=analogRead(2);
  }
  time2=micros();
  digitalWrite(KEY_3_PIN, HIGH);

  
  for(int i=0; i<adc_buffer_len; i++)
  {
    Serial.printf("Key1:%d,Key2:%d,Key3:%d\n",adc_buffer1[i],adc_buffer2[i],adc_buffer3[i]);
  }
  
}

void loop() {
  // read the analog / millivolts value for pin 2:

  
  
  delay(100);  // delay in between reads for clear read from serial
}
