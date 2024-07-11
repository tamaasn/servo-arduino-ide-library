class Servo{
  public:
    void use_pin(int pin);
    void write(unsigned int angle);
    int CurrentPin;
    int MinPulseWidth=544;
    int MaxPulseWidth=2400;
};

void Servo::use_pin(int pin){
  pinMode(pin , OUTPUT);
  CurrentPin = pin;
}

void Servo::write(unsigned int angle){
  if (angle > 180) angle=180;
  int pulsewidth = map(angle , 0 , 180 , MinPulseWidth , MaxPulseWidth);
  digitalWrite(CurrentPin , HIGH);
  delayMicroseconds(pulsewidth);
  digitalWrite(CurrentPin , LOW);
  delayMicroseconds(20000 - pulsewidth);
}

