const int inPin = A0;
const int outPin = 13;
float inVal = 0;
float thrVal;
float avgVal;
int i;

float avg (){
  for (i = 0; i < 1000; i++) {
  inVal += analogRead(inPin);
  }
  return inVal/1000;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
  thrVal = avg();
}

float flt_map (float val, float in_min, float in_max, float out_min, float out_max) {
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void loop() {
  // put your main code here, to run repeatedly:
  inVal = 0;
  inVal = analogRead(inPin);

  if (inVal < thrVal){
    digitalWrite(outPin, HIGH);
  }
  else if (inVal > thrVal) {
    digitalWrite(outPin, LOW);
  }
  
  Serial.print(inVal);
  Serial.print(' ');
  Serial.println(100 - flt_map(inVal, 0, 1023, 0, 100));
//  Serial.println(flt_map(inVal, thrVal, 0, 0, 100));
//  delay(2000);/
}
