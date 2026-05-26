// GRUPO 10 - GARELIK, GONZALEZ, PRE
TaskHandle_t Task1;
TaskHandle_t Task2;

// LED pins modificados
const int pin_LED_1 = 25;
const int pin_LED_2 = 26;

void setup() {
  Serial.begin(115200); 
  pinMode(pin_LED_1, OUTPUT);
  pinMode(pin_LED_2, OUTPUT);

  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
  delay(500); 
}

// Task1code: Enciende 10s y apaga 10s
void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(pin_LED_1, HIGH); 
    delay(10000); 
    digitalWrite(pin_LED_1, LOW); 
    delay(10000);
  } 
}

// Task2code: Enciende 0.5s y apaga 0.5s
void Task2code( void * pvParameters ){
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());
  
  for(;;){
    digitalWrite(pin_LED_2, HIGH); 
    delay(500); 
    digitalWrite(pin_LED_2, LOW); 
    delay(500);
  }
}

void loop() {
  // El loop principal queda libre para otras acciones
}
