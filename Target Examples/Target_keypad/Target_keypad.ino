/*
This file is licensed under the Creative Commons Attribution-Share Alike 3.0 Unported license.
https://creativecommons.org/licenses/by-sa/3.0/deed.en

Attribution: Miswired

    You are free:
        to share – to copy, distribute and transmit the work
        to remix – to adapt the work
    Under the following conditions:
        attribution – You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
        share alike – If you remix, transform, or build upon the material, you must distribute your contributions under the same or compatible license as the original. https://creativecommons.org/share-your-work/licensing-considerations/compatible-licenses
*/

        
// Defining Pins here
#define ENTER_KEY_PIN       2   
#define KEY_1_PIN           6
#define KEY_2_PIN           5
#define KEY_3_PIN           4
#define KEY_4_PIN           3
#define LOCKED_LED_PIN      13 
#define UNLOCKED_LED_PIN    12     

//Globals
bool g_button_state = false;         // variable for reading the pushbutton status
volatile bool g_unlocked = false;   //volatile so that the optimizer doesn't remove the code since it is always false
bool g_was_the_right_key_pressed = false;

void setup() {
  // initialize pin registers
  pinMode(LOCKED_LED_PIN, OUTPUT);
  pinMode(UNLOCKED_LED_PIN, OUTPUT);
  pinMode(ENTER_KEY_PIN, INPUT);

  //Note, this example expects the pins to be pulled high and low, no pullup needed.
  pinMode(KEY_1_PIN, INPUT);
  pinMode(KEY_2_PIN, INPUT);
  pinMode(KEY_3_PIN, INPUT);
  pinMode(KEY_4_PIN, INPUT);

  // Show locked
  digitalWrite(LOCKED_LED_PIN, HIGH);
  digitalWrite(UNLOCKED_LED_PIN, LOW);
}

void loop() {
  if(digitalRead(KEY_1_PIN))
  {
    g_was_the_right_key_pressed = false;
  }

    if(digitalRead(KEY_2_PIN))
  {
    g_was_the_right_key_pressed = false;
  }

  //In this example, we only care if key 3 is pressed, because it's the right key.
  if(digitalRead(KEY_3_PIN))
  {
    g_was_the_right_key_pressed = true;

    //Do some extra operation to simulate a different execution path, this is NOT realilistic, just for testing
    float testing=1928.12*272727/0.5782+5;
    Serial.println(testing);
  }

    if(digitalRead(KEY_4_PIN))
  {
    g_was_the_right_key_pressed = false;
  }

  

  //Check to see if button is pressed and we should evaluate the password
  if (digitalRead(ENTER_KEY_PIN)) {
    if(g_was_the_right_key_pressed)
    {
      unlock_system();
    }
  } 
}

//The function that should never get called
void unlock_system()
{
  digitalWrite(LOCKED_LED_PIN, LOW);
  digitalWrite(UNLOCKED_LED_PIN, HIGH);

  //Stay here forever
  while(true);
}
