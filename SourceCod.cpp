void setup() {
   for(int k=8 ; k<14 ; k++) {
      pinMode(k,OUTPUT) ;   //pins 8-14 are enabled as output
   }

   LCD.begin(16, 2) ;   //initializing LCD

   // for the Peizo-buzzer
   //Serial.begin(8600) ;
   pinMode(buzzerPin, OUTPUT) ;

   // for Servo-Motor
   //pinMode(servoPin, OUTPUT) ;
   servo.attach(servoPin) ;

   // for Bluetooth-Module
   Serial.begin(9600) ;

   // Now, the Welcome message...
   LCD.setCursor(0,0) ;
   LCD.print("   WELCOME !!") ;
   LCD.setCursor(0,1) ;
   LCD.print("Set a Password :") ;

   InitializePassword(), InitializeString() ;
   CloseDoor() ;
}



void loop() {
   // for Bluetooth-module
   if( Serial.available() > 0 ) {
      state = Serial.read() ;
      flag_state = 0 ;
   }