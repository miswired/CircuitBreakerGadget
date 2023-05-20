/*
This file contains helper functions for the power glitching features. 

Normally in a C program this would be a self contained module.
But as I am trying to keep this more beginnner friendly and use the Arduino IDE, there are some limitations on how it links files
and auto creates prototypes. So the main instantiation is still in the main ino.

This file is licensed under the Creative Commons Attribution-Share Alike 3.0 Unported license.
https://creativecommons.org/licenses/by-sa/3.0/deed.en

Attribution: Miswired
Special thanks goes to Rui Santos and the RandomNerdTutorials site. The work here was inspired by those examples.

    You are free:
        to share – to copy, distribute and transmit the work
        to remix – to adapt the work
    Under the following conditions:
        attribution – You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
        share alike – If you remix, transform, or build upon the material, you must distribute your contributions under the same or compatible license as the original. https://creativecommons.org/share-your-work/licensing-considerations/compatible-licenses
*/


// This is a quick and dirty glitching sequence used for testing. It's using nop's for delays as the delay function has too much overhead for short delays.
// The pulse width of the glitch is staticly set right now, this should be dynamic
void execute_test_glitch(uint32_t shortest_delay_us, uint32_t longest_delay_us, uint32_t pause_time_between_glitching_ms, uint32_t glitch_time_step_size)
{
  int i=0;
  uint32_t glitch_time_us = shortest_delay_us;

  while((glitch_time_us < longest_delay_us) && (digitalRead(GLITCH_SUCCESS_PIN) == false))
  {
    digitalWrite(ENTER_KEY_PIN,HIGH);
    digitalWrite(POWER_GLITCH_PIN, HIGH);
    for(i=0; i<10; i++)
    {
      asm ( "nop \n" );
    }
   
    digitalWrite(POWER_GLITCH_PIN, LOW);

    digitalWrite(POWER_GLITCH_PIN, HIGH);
    for(i=0; i<10; i++)
    {
      asm ( "nop \n" );
    }
   
    digitalWrite(POWER_GLITCH_PIN, LOW);

    digitalWrite(POWER_GLITCH_PIN, HIGH);
    for(i=0; i<10; i++)
    {
      asm ( "nop \n" );
    }
   
    digitalWrite(POWER_GLITCH_PIN, LOW);


    digitalWrite(POWER_GLITCH_PIN, HIGH);
    for(i=0; i<10; i++)
    {
      asm ( "nop \n" );
    }
   
    digitalWrite(POWER_GLITCH_PIN, LOW);

    digitalWrite(POWER_GLITCH_PIN, HIGH);
    for(i=0; i<10; i++)
    {
      asm ( "nop \n" );
    }
   
    digitalWrite(POWER_GLITCH_PIN, LOW);
    digitalWrite(ENTER_KEY_PIN,LOW);
    
    delay(pause_time_between_glitching_ms);
    glitch_time_us = glitch_time_us + glitch_time_step_size;
    Serial.println(glitch_time_us);
  }
}
