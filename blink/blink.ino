//blink bare metal



void setup() {
  //Initialize digital pin LED_BUILTIN as an output

  //LOW LEVEL
  DDRB = 32;  //00100000 sets PB5 as output
}

void loop() {
  // put your main code here, to run repeatedly:
  //Blink

  //HIGH LEVEL
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

//---------------------------------------------------//
 
void setup() {
  //Initialize digital pin LED_BUILTIN as an output

  DDRB = 32;  //00100000 sets PB5 as output

}
void loop() {
  //LOW LEVEL
  //PORTB = 32;
  
  //for(long i = 0; i< 10000000; i++) { PORTB = 30; }
  
  //PORTB =0;
  
  //for(long i = 0; i< 10000000; i++) { PORTB = 0; }
  }

//---------------------------------------------------//

  //WITH MEMORY REGISTERS and pointers

 void setup() {
  //Initialize digital pin LED_BUILTIN as an output

  DDRB = 32;  //00100000 sets PB5 as output

}
  void loop() {
    
  volatile byte* variable = 0x25;
  *variable = 32;
  
  for(long i = 0; i< 10000000; i++) { *variable = 30; }
  
  *variable = 0;
  
  for(long i = 0; i< 10000000; i++) { *variable = 0; }
  
}
//---------------------------------------------------//

//WITH MEMORY REGISTERS and pointers directly

 void setup() {
  //Initialize digital pin LED_BUILTIN as an output

  DDRB = 32;  //00100000 sets PB5 as output

}

  void loop() {
  *((volatile byte*) 0x25) =32;
  
  for(long i = 0; i< 10000000; i++) { *((volatile byte*) 0x25) = 32; }
  
  *((volatile byte*) 0x25) =0;
  
  for(long i = 0; i< 10000000; i++) { *((volatile byte*) 0x25) = 0; }
  }

//---------------------------------------------------//
  
//WITH MEMORY REGISTERS and pointers directly simpler

//really low
//Define variable
  #define memory_adress *((volatile byte*) 0x25)
  #define memory_adress_2 *((volatile byte*) 0x24)

   void setup() {
  //Initialize digital pin LED_BUILTIN as an output

  memory_adress_2 = 32;  //00100000 sets PB5 as output

}

void loop() {
  memory_adress = 32;
  
  for(long i = 0; i< 10000000; i++) { memory_adress = 32; }
  
  memory_adress = 0;
  
  for(long i = 0; i< 10000000; i++) { memory_adress = 0; }
}
  
//---------------------------------------------------//
