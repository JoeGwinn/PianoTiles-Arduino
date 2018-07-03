#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState =0;
int prevSwitchState = 0;
int reply;
const int buttonLeft = A0;
const int buttonRight = A1;

float timer = 0.0;
bool timerStarted = false;
bool timerPaused = false;
float pausedTime = 0.0;
float startTime = 0.0;

const ntiles = 4;

struct tile {
  float y;
  bool column;
};

bool buttonLeftPressed = false;
bool buttonRightPressed = false;

float gspeed = 0.0;

tile* tiles[ntiles];

void startTimer(){
  timerStarted = true;
  timerPaused = false;
  pausedTime = 0.0;
  startTime = millis();
  timer = 0.0;
}

float getTime()
{
  if (timerPaused)
  {
    return pausedTime;
  }
  else
  {
    timer = millis() - startTime;
    return ((float)timer / 1000.0);
  }
}

void pauseTimer()
{
  timerPaused = true;
  pausedTime = getTime();
  startTime = 0;
}

void setup(){

  timerStarted = true;
  timerPaused = false;
  for (int i = 0; i < ntiles; i++)
  {
    tiles[i] = NULL;
  }
  
  lcd.begin(16,2);
  lcd.print("WAFFLES");
  delay(1000);
  lcd.clear();

}

void handleEvents()
{
  if (digitalRead(buttonLeft) == HIGH)
  {
    buttonLeftPressed = true;
  }
  else
  {
    buttonLeftPressed = false;
  }
  if (digitalRead(buttonRight) == HIGH)
  {
    buttonRightPressed = true;
  }
  else
  {
    buttonRightPressed = false;
  }
}

void logic()
{
  
}

void render()
{
  
}

void loop() {
  lcd.print("Press any button")
  lcd.cursor(1, 0);
  lcd.print("to start...");
  if (digitalRead(buttonLeft) == HIGH || digitalRead(buttonLeft) == HIGH)
  {
    lcd.clear();
    lcd.cursor(0, 1);
    lcd.print("Ready Player One");
    lcd.cursor(1, 0);
    bool quit = false;
    startTimer();
    float deltaTime = 0.0;
    float prevTime = getTime();
    while (!quit)
    {
      prevTime = getTime();
      
      handleEvents();

      logic();

      render();
      
      deltaTime = getTime() - prevTime;
    }
  }
  lcd.clear();
}

