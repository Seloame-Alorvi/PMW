#include <math.h> 
uint8_t LEDPin_1 = 1;
uint8_t ledPin_2 = 2;
uint8_t ledPin_3 = 3; 
int dutyCycle[] = {255,512,767};
int PWMFreq = 5000;
int PWMChannel[] = {0,1,2};
int PWMResolution = 10;
int MAX_DUTY_CYCLE = 1023;
int the_value = 0 ; 
void setup() {
 
ledcSetup(PWMChannel[0], PWMFreq, PWMResolution);
ledcAttachPin(LEDPin_1, PWMChannel[0]);
ledcAttachPin(ledPin_2,PWMChannel[1]);
ledcAttachPin(ledPin_3,PWMChannel[2]);
};

void loop() {
dutyCycle[0]= 512*sin(2*the_value)+(512-1);
dutyCycle[1] = the_value*sin(1.5 * the_value) + 512;
dutyCycle[2]= 1023 * pow(sin(0.6*the_value),2);

for(int i=0;i<3;i++){


ledcWrite(PWMChannel[i], dutyCycle[i]);
delay(150);

}
the_value++;

}