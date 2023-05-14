#include <Adafruit_LiquidCrystal.h>  // Include the Adafruit LCD library

using namespace std;

int led1 = 13;        // Pin number for LED
int button1 = 8;      // Pin number for button
int buttonLast = LOW; // Previous button state

Adafruit_LiquidCrystal lcd_1(0);  // Create an instance of the LCD display

char letter[1000];  // Array to store Morse code letter

void setup()
{
  Serial.begin(9600);  // Initialize serial communication for debugging
  
  lcd_1.begin(16, 2);  // Initialize the LCD display with 16 columns and 2 rows

  pinMode(led1, OUTPUT);    // Set LED pin as output
  pinMode(button1, INPUT);  // Set button pin as input
  digitalWrite(led1, LOW);  // Turn off the LED initially
}

void buttonPressed() 
{
  int duration = 0;  // Variable to store the duration of the button press
  
  digitalWrite(led1, LOW);  // Turn off the LED
  
  // While the button is pressed, turn on the LED, increment the duration, and delay for 1 millisecond
  while (digitalRead(button1) == HIGH)
  {
    digitalWrite(led1, HIGH);
    duration++;
    delay(1);
  }
  
  if (duration != 0) {
    if (duration < 300) {
      // Dot
      Serial.print(".");
      strcat(letter, ".");
      Serial.print(duration);
    } 
    else if (duration >= 300 && duration < 1000) 
    {
      // Dash
      Serial.print("-");
      strcat(letter, "-");
      Serial.print(duration);
    } 
    else if (duration >= 1000 && duration < 2000) 
    {
      searchLetters();
      Serial.print("/");
      Serial.print(duration);
    }
    else 
    {
      lcd_1.print(' ');
      Serial.print(" ");
      Serial.print(duration);
    }
  }
  
  duration = 0;  // Reset the duration after processing
}

void searchLetters() 
{
  // Decode the letter and print it to the LCD
  if (strcmp(letter, ".-") == 0) 
  {
    lcd_1.print('a');
  } 
  else if (strcmp(letter, "-...") == 0) 
  {
    lcd_1.print('b');
  } 
  else if (strcmp(letter, "-.-.") == 0) 
  {
    lcd_1.print('c');
  } 
  else if (strcmp(letter, "-..") == 0) 
  {
    lcd_1.print('d');
  } 
  else if (strcmp(letter, ".") == 0) 
  {
    lcd_1.print('e');
  } 
  else if (strcmp(letter, "..-.") == 0) 
  {
    lcd_1.print('f');
  } 
  else if (strcmp(letter, "--.") == 0) 
  {
    lcd_1.print('g');
  } 
  else if (strcmp(letter, "....") == 0) 
  {
    lcd_1.print('h');
  } 
  else if (strcmp(letter, "..") == 0)
  {
    lcd_1.print('i');
  } 
  else if (strcmp(letter, ".---") == 0) 
  {
    lcd_1.print('j');
  } 
  else if (strcmp(letter, "-.-") == 0)
  {
    lcd_1.print('k');
  } 
  else if (strcmp(letter, ".-..") == 0) 
  {
    lcd_1.print('l');
  }  
  else if (strcmp(letter, "--") == 0) 
  {
    lcd_1.print('m');
  } 
  else if (strcmp(letter, "-.") == 0) 
  {
    lcd_1.print('n');
  } 
  else if (strcmp(letter, "---") == 0) 
  {
    lcd_1.print('o');
  } 
  else if (strcmp(letter, ".--.") == 0) 
  {
    lcd_1.print('p');
  } 
  else if (strcmp(letter, "--.-") == 0) 
  {
    lcd_1.print('q');
  } 
  else if (strcmp(letter, ".-.") == 0) 
  {
    lcd_1.print('r');
  } 
  else if (strcmp(letter, "...") == 0) 
  {
    lcd_1.print('s');
  } 
  else if (strcmp(letter, "-") == 0) 
  {
    lcd_1.print('t');
  } 
  else if (strcmp(letter, "..-") == 0) 
  {
    lcd_1.print('u');
  }
  else if (strcmp(letter, "...-") == 0) 
  {
    lcd_1.print('v');
  } 
  else if (strcmp(letter, ".--") == 0) 
  {
    lcd_1.print('w');
  } 
  else if (strcmp(letter, "-..-") == 0) 
  {
    lcd_1.print('x');
  } 
  else if (strcmp(letter, "-.--") == 0) 
  {
    lcd_1.print('y');
  } 
  else if (strcmp(letter, "--..") == 0)
  {
    lcd_1.print('z');
  }
  
  letter[0] = '\0';  // Reset the letter after searching
}

void loop() 
{
  buttonPressed();  // Call the buttonPressed function repeatedly
}