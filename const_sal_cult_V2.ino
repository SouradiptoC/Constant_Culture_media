// inPin in input pin
// outPin is output pin
// inVal is initial value of resistance
// thrVal is threshold value
// avgVal is average value

const int inPin = A0;
const int outPin = 13;  
float inVal = 0;
float thrVal;
float avgVal;
int i;

// This function calculates the avg with 1000 iter
float avg (){
  for (i = 0; i < 1000; i++) {
  inVal += analogRead(inPin);
  }
  return inVal/1000;
}

void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
  thrVal = avg();
}

// This function is a scaling function (standardizer)
float flt_map (float val, float in_min, float in_max, float out_min, float out_max) {
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void loop() {
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
