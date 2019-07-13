
#define button 2
#define led 3
#define temp 0  //analog
#define speak 4
#define gas 4 //analog
void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT);
pinMode(temp,INPUT);
pinMode(led,INPUT);
pinMode(speak,INPUT);
digitalWrite(led,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonr=digitalRead(button);  //ref
  Serial.println(buttonr);
  delay(100);
  if(buttonr==1)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
  int tempr=analogRead(gas); //gas
  Serial.println(gasr);
  delay(100);
  if(gasr<=350 || tempr>200)
  {
    digitalWrite(speak,0);
  }
  if(gasr>350  || tempr<=200)
   {
    digitalWrite(speak,1);
  }
}
