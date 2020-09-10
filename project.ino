#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define relayPin 12 
#define buzzerPin 13 
#define obstaclePin 8
float targetTemp;
int hasObstacle = HIGH;
float predefinedTemp = 37.40;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  mlx.begin();  
}

void loop() {
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH)
  {  
    targetTemp = mlx.readObjectTempC();
    if (targetTemp <= predefinedTemp)
    { 
       digitalWrite(relayPin, HIGH);
       delay(6000);       
    }
    else
    {
      digitalWrite(buzzerPin, HIGH); 
      delay(3000);
    }
  }
}
