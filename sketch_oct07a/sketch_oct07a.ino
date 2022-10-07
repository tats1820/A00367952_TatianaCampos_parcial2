byte sensorHumedad_pin = A0; //Sensor de humedad

//Bombillos LED
const int PIN_ONE = 4;
const int PIN_TWO = 5;
const int PIN_THREE = 6;
const int PIN_FOUR = 7;
const int PIN_FIVE = 8;
const int myLEDs [5] = {4, 5, 6, 7, 8};

//Boton
bool btnState = false;

int BTN_PIN = 2;

//Sensor de + o -
int PIEZO_PIN = 3;


void setup()
{
  for(int i = 0; i < 5; i++){
    pinMode(myLEDs[i], OUTPUT);
  }
  
  pinMode (BTN_PIN, INPUT);
  pinMode (sensorHumedad_pin, OUTPUT);
  pinMode (PIEZO_PIN, INPUT);
}

void loop()
{
  Serial.print("Humidity Level (0-1023):" );
  Serial.println(read_humidity_sensor()); 
  delay(10000);
  
  for(int i = 0; i < 5; i++){
    if (btnState){
    digitalWrite(myLEDs[4-i], HIGH);
    }else{
      digitalWrite(myLEDs[i], HIGH);
      }
    delay(1000);
  }
  for(int i = 0; i < 5; i++){
    if(btnState){
      digitalWrite(myLEDs[i], LOW);
    } else{
      digitalWrite(myLEDs[4-i], LOW);
    }
    delay(1000);
  }
  
  if (sensorHumedad_pin < 0.2){
    Serial.print("RIEGA LA PLATA");
    tone(pin, 50, 100);
    
    
  } else (sensorHumedad_pin > 0.8){
    
    Serial.print("EXCESO DE AGUA");
    tone(pin, 40, 5000)
  }
  
  
  if (btnState){
  
  }
 
}
