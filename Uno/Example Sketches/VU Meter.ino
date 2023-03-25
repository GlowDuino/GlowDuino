/*

This is a VU meter sketch for the GlowDuino Uno board.
Visit the Instructables page to get to know more about this:
https://www.instructables.com/Volume-Meter-With-GlowDuino/

*/


// Replace A6 and A7 with the pin of your choice
// Audio inputs (analog pin):
#define LeftChannel A6
#define RightChannel A7

// Here you can set the maximum and minimum levels.
// 0 is 0V and 1023 is 5V. 
// Set the range of input voltage
#define MinimumVolume 0
#define MaximumVolume 350

// Uncomment if you want stereo inputs
#define Stereo

// Variables storing the channel values:
int leftValue = 0;
int rightValue = 0;

void setup() {
  pinMode(LeftChannel, INPUT);  //LeftChannel for both mono and stereo
  #ifdef Stereo                 //If stereo is selected, enable RightChannel
    pinMode(RightChannel, INPUT);
  #endif

  for(int i = 2; i < 14; i++){  //Set all the display pins (2-13) to output
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // If stereo mode is selected:
  #ifdef Stereo
    // Read left and right channel then map the value  to the number of leds
    leftValue = analogRead(LeftChannel);
    leftValue = map(leftValue, MinimumVolume, MaximumVolume, 0, 6);
    rightValue = analogRead(RightChannel);
    rightValue = map(rightValue, MinimumVolume, MaximumVolume, 0, 6);
    
    // Write the left channel to the output LEDs (8-13)
    for(int i = 13; i > 7; i--, leftValue--){
      if(leftValue > 0){
        digitalWrite(i, HIGH);
      }else{
        digitalWrite(i, LOW);
      }
    }

    // Write the right channel to the output LEDs (2-7)
    for(int i = 2; i < 8; i++, rightValue--){
      if(rightValue > 0){
        digitalWrite(i, HIGH);
      }else{
        digitalWrite(i, LOW);
      }
    }
  #endif

  // If mono mode is selected:
  #ifndef Stereo
    // Read left channel then map the value  to the number of leds
    leftValue = analogRead(LeftChannel);
    leftValue = map(leftValue, MinimumVolume, MaximumVolume, 0, 12);
    
    // Write the left channel to the output LEDs (2-13)
    for(int i = 2; i < 14; i++, leftValue--){
      if(leftValue > 0){
        digitalWrite(i, HIGH);
      }else{
        digitalWrite(i, LOW);
      }
    }
  #endif
}
