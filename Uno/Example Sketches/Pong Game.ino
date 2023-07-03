/* 1D Pong game, inspired by Great Scott
 * 
 * Goal of the game is to push the button whenever the moving dot is in the range
 * of the end. If the player pushes the button when it is in the set range, the ball
 * bounces back. If the player is unable to bounce the ball back correctly, the 
 * opposing player gets a point. The first player to reach four points wins.
 * 
 * The player buttons can be set with the define statements below. Pins 2 to 13
 * is the playing field, pins A0 to A5 is the score display. 
 * 
 * To start the game, push the two buttons simultaniously.
 * 
 */

#define StartSpeed 100        // The start delay between LED changes
#define IncreaseSpeed 10      // The rate the ball speeds up
#define InputPassDistance 4   // The distance from each end that passes as good input
#define FastestSpeed 10       // The fastest speed the ball can go. The lower this number is the faster

#define ButtonOne 23
#define ButtonTwo 22

/// Game Variables below ///

// Used game states:
#define Idle 0
#define Play 1
int gameState = 0;

// Ball variables
int ballPosition = 2;
#define Left 1
#define Right -1
int ballDirection = Left;
int ballSpeed = StartSpeed;
bool bounce = false;

// Variables Storing button states
bool buttonOneState = 0;
bool buttonOnePreviousState = 0;
bool buttonTwoState = 0;
bool buttonTwoPreviousState = 0; 

int playerOneScore = 0;
int playerTwoScore = 0;
#define PlayerOne 0
#define PlayerTwo 1
bool lastScore = PlayerOne;

////////////////////////////////////////////////////////

void setup() {
  pinMode(ButtonOne, INPUT);    // Set buttons to input
  pinMode(ButtonTwo, INPUT);
  for(int i = 2; i < 14; i++){  // Set playfield to output
    pinMode(i, OUTPUT);
  }
  delay(500);
}

////////////////////////////////////////////////////////

void loop() {
  // Play idle animation while waiting for players
  while(gameState == Idle){   
    refreshLeds();
    buttonOneState = digitalRead(ButtonOne);
    buttonTwoState = digitalRead(ButtonTwo);

    // Wait before advancing and look for start command
    for(int i = 0; i < StartSpeed; i++){
      // Look for button presses
      if(buttonOneState == HIGH &&
         buttonTwoState == HIGH){
         playerOneScore = 0;
         playerTwoScore = 0;
         
         startGame();
         break;
      }
      delay(1);
    }
    ballPosition += ballDirection;  //Advance ball

    // Check if ball needs to bounce
    if(ballPosition == 14){
      ballPosition = 12;
      ballDirection = Right;
    }
    if(ballPosition == 1){
      ballPosition = 3;
      ballDirection = Left;
    }
  }

  // Handle game when in game mode
  while(gameState == Play){
    refreshLeds();  //Displayy current state of game
    
    // Wait before advancing and look for button presses at the same time
    for(int i = 0; i < ballSpeed; i++){      
      buttonOneState = digitalRead(ButtonOne);  // Read button state
      buttonTwoState = digitalRead(ButtonTwo);  // Read button state
      if(buttonOneState == HIGH &&
         buttonOnePreviousState == LOW &&
         ballDirection == Left &&
         ballPosition >= (14 - InputPassDistance)){ // Handle button press if valid
         bounce = true; // Mark button press as valid
      }
      if(buttonTwoState == HIGH &&
         buttonTwoPreviousState == LOW &&
         ballDirection == Right &&
         ballPosition <= (1 + InputPassDistance)){  // Handle button press if valid
         bounce = true; // Mark button press as valid
      }
      delay(1);
    }
    buttonOnePreviousState = digitalRead(ButtonOne);  // Record current state of button
    buttonTwoPreviousState = digitalRead(ButtonTwo);  // Record current state of button
    ballPosition += ballDirection;  // Advance ball

    // Check if ball needs to bounce and handle scores
    if(ballPosition == 14 &&
       bounce == true){
      ballPosition = 12;  // Bounce ball
      ballDirection = Right;  // Reverse ball direction
      ballSpeed -= IncreaseSpeed; // Increase ball speed
      bounce = false; // Clear button press
    }else if(ballPosition == 14){ // If no valid button press happened, add score
      ballPosition = 13;  // Bounce ball
      ballDirection = Right;  // Reverse ball direction
      ballSpeed = StartSpeed; // Reset speed
      playerTwoScore++;       // Increase player score
      lastScore = PlayerTwo;  // Record next start position
      if(playerTwoScore == 4){  // Check if game ended
        endGame();  // Play end animation
      }else{
        startGame();  // Start new game round
      }
    }
    // Check if ball needs to bounce and handle scores
    if(ballPosition == 1 &&
       bounce == true){
      ballPosition = 3; // Bounce ball
      ballDirection = Left; // Reverse ball direction
      ballSpeed -= IncreaseSpeed; // Increase ball speed
      bounce = false; // Clear button press
    }else if(ballPosition == 1){  // If no valid button press happened, add score
      ballPosition = 2; // Bounce ball
      ballDirection = Left; // Reverse ball direction
      ballSpeed = StartSpeed; // Reset speed
      playerOneScore++; // Increase player score
      lastScore = PlayerOne;  // Record next start position
      if(playerOneScore == 4){  // Check if game ended
        endGame();  // Play end animation
      }else{
        startGame();  // Start new game round
      }
    }
  }
}

////////////////////////////////////////////////////////

// Output refresh function
void refreshLeds (){
  for(int i = 2; i < 14; i++){  // Refresh playfield
    if(i == ballPosition){
      digitalWrite(i, HIGH);
    }else{
      digitalWrite(i, LOW);
    }
  }
  
  int scoreBuffer = playerOneScore;
  for(int i = 14; i < 17; i++){ // Display Player One score
    if(scoreBuffer > 0){
      digitalWrite(i, HIGH);
      scoreBuffer--;
    }else{
      digitalWrite(i, LOW);
    }
  }
  scoreBuffer = playerTwoScore;
  for(int i = 19; i > 16; i--){ // Display Player Two score
    if(scoreBuffer > 0){
      digitalWrite(i, HIGH);
      scoreBuffer--;
    }else{
      digitalWrite(i, LOW);
    }
  }
}

void startGame (){
  if(lastScore == PlayerOne){ // Decide which side to start at
    ballPosition = 2;
    ballDirection = Left;
  }else{
    ballPosition = 13;
    ballDirection = Right;
  }
  bounce = false;
  refreshLeds();
  delay(500);

  // Play start animation
  for(int i = 0; i < 4; i++){
    digitalWrite(ballPosition, HIGH);
    delay(300);
    digitalWrite(ballPosition, LOW);
    delay(300);
  }
  for(int i = 0; i < 4; i++){
    digitalWrite(ballPosition, HIGH);
    delay(200);
    digitalWrite(ballPosition, LOW);
    delay(200);
  }
  for(int i = 0; i < 4; i++){
    digitalWrite(ballPosition, HIGH);
    delay(100);
    digitalWrite(ballPosition, LOW);
    delay(100);
  }
  
  gameState = Play;
  refreshLeds();
}

void endGame (){
  if(lastScore == PlayerOne){   // Check who won and play end animation
    for(int i = 0; i < 5; i++){
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      delay(500);
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      delay(500);
    }
  }else{
    for(int i = 0; i < 5; i++){
      digitalWrite(A3, HIGH);
      digitalWrite(A4, HIGH);
      digitalWrite(A5, HIGH);
      delay(500);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      delay(500);
    }
  }
  gameState = Idle; 
}
