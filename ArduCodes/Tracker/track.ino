int RELAY1 = 4;
int RELAY2 = 2;
int RELAY3 = 3;
int incByte;
int photores1 = 1;
int photores2 = 2;   
int photoresinfo1;
int photoresinfo2;
int diff;
int pos;
int track;
int reset;
int tdone;

void setup() {
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);
  pinMode(RELAY3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  photoresinfo1 = analogRead(photores1);  
  photoresinfo2 = analogRead(photores2);
  diff = photoresinfo2 - photoresinfo1 ;
  
if (diff < -2 ) {
  
  digitalWrite(RELAY1,LOW);           
  delay(1000);

  digitalWrite(RELAY2,HIGH);           
  delay(1000);

  digitalWrite(RELAY3,HIGH);           
  delay(1000);

  digitalWrite(RELAY1,HIGH); 
  tdone = tdone + 1;
  pos = 140 + ( 10 * tdone);
}
if (reset == 1 ) {
  
  digitalWrite(RELAY1,LOW);           
  delay(1000);

  digitalWrite(RELAY2,HIGH);           
  delay(1000);

  digitalWrite(RELAY3,HIGH);           
  delay(1000);

  digitalWrite(RELAY1,HIGH);  

  reset = 0;
}

if (Serial.available() > 0){
  incByte = Serial.read();

  if (incByte == 'A'){
    Serial.flush();
    Serial.println("Connected");
    Serial.flush();
    }
  if (incByte == 'B'){
    Serial.flush();
    photoresinfo1 = analogRead(photores1); 
    Serial.println(photoresinfo1);
    Serial.flush();
    }
  if (incByte == 'C'){
    Serial.flush();
    photoresinfo2 = analogRead(photores2);
    Serial.println(photoresinfo2);
    Serial.flush();
    }
  if (incByte == 'D'){
    pos = 140 + ( 10 * tdone);
    Serial.println(pos);
    Serial.flush();
    }
    
  if (incByte == 'E'){
    Serial.flush();
    diff = photoresinfo2 - photoresinfo1 ;
    Serial.println(diff);
    Serial.flush();
    }
  if (incByte == 'F'){
    Serial.flush();
    reset = 1;
    Serial.println(reset);
    Serial.flush();
    }  

}
}
