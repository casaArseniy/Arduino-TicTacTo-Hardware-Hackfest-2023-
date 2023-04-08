#include <LiquidCrystal.h>
#include <string.h>


#define PIN_BUTTON 2
#define PIN_AUTOPLAY 1
#define PIN_READWRITE 10
#define PIN_CONTRAST 12



//GAME LOGIC
// Define the Tic Tac Toe board as a 3x3 array
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to check if there is a winner
char checkWinner() {
  // Check the rows
  for (int row = 0; row < 3; row++) {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
      return board[row][0];
    }
  }

  // Check the columns
  for (int col = 0; col < 3; col++) {
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
      return board[0][col];
    }
  }

  // Check the diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2];
  }

  // If there is no winner, return ' ' to indicate a tie or an unfinished game
  return ' ';
}
//

LiquidCrystal lcds[] = {
  LiquidCrystal(11, 9, 6, 5, 4, 3),
  LiquidCrystal(11, 10, 6, 5, 4, 3),
  LiquidCrystal(11, 8, 6, 5, 4, 3),
  LiquidCrystal(11, 7, 6, 5, 4, 3)
};

int row[] = {1,2,3};
int column[] = {2,7,13};


void press(int row, int column, int player) {
  if (player == 2) {
  	lcds[row].setCursor(column, 1);
    lcds[row].print("0");
  } else {
    lcds[row].setCursor(column, 1);
    lcds[row].print("X");
  }
}

void createBoard() {
  lcds[1].print("    |     |");
  lcds[1].setCursor(0, 1);
  lcds[1].print("    |     |");
  lcds[2].print("    |     |");
  lcds[2].setCursor(0, 1);
  lcds[2].print("    |     |");
  lcds[3].print("    |     |");
  lcds[3].setCursor(0, 1);
  lcds[3].print("    |     |");
  

  lcds[1].setCursor(0, 1);
  lcds[1].print("0000");
  lcds[1].setCursor(6, 1);
  lcds[1].print("0001");
  lcds[1].setCursor(12, 1);
  lcds[1].print("0010");
  
  lcds[2].setCursor(0, 1);
  lcds[2].print("0011");
  lcds[2].setCursor(6, 1);
  lcds[2].print("0100");
  lcds[2].setCursor(12, 1);
  lcds[2].print("0101");
  
  lcds[3].setCursor(0, 1);
  lcds[3].print("0110");
  lcds[3].setCursor(6, 1);
  lcds[3].print("0111");
  lcds[3].setCursor(12, 1);
  lcds[3].print("1000");
  
}



void setup(){
  pinMode(PIN_READWRITE, OUTPUT);
  digitalWrite(PIN_READWRITE, LOW);
  pinMode(PIN_CONTRAST, OUTPUT);
  digitalWrite(PIN_CONTRAST, LOW);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH);
  pinMode(PIN_AUTOPLAY, OUTPUT);
  digitalWrite(PIN_AUTOPLAY, HIGH);
  
  pinMode(A1, INPUT);
  
  
  lcds[0].begin(16, 2);
  lcds[1].begin(16, 2);
  lcds[2].begin(16, 2);
  lcds[3].begin(16, 4);
  
  createBoard();
}


int buttonState = 0;

String binary = "";

void loop(){
  
  lcds[0].blink();
  delay(500);
  
  buttonState = digitalRead(A1);
  lcds[0].noBlink();
  
  if (buttonState == HIGH) {
    binary+="1";
    lcds[0].setCursor(0, 1);
  	lcds[0].print(binary);
  } else if (buttonState == LOW){
    binary+="0";
    lcds[0].setCursor(0, 1);
  	lcds[0].print(binary);
  }
  delay(500);
  
  if (binary.length() == 4 ) {
    lcds[0].setCursor(0, 0);
    lcds[0].print(binary);
    binary="";
    lcds[0].setCursor(0, 1);
  	lcds[0].print("    ");
  }
  
  
}
