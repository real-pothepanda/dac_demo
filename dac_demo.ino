// GPIO Pins
const byte POT = 34;
const byte DAC_PIN = 25;

// variables
int adc_val = 0;
float voltage_in = 0;

void setup() {
  // adc pin - resolution should always be 8-bit
  pinMode(POT, INPUT);
  analogReadResolution(8);

  // dac pin
  pinMode(DAC_PIN, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // 8-bit adc numerical value
  adc_val = analogRead(POT);
  Serial.printf("ADC Numeric value: %d\n", adc_val);
  delay(500);

  // convert 8-bit ADC to actual voltage
  voltage_in = (adc_val/256.0)*3.3;
  Serial.printf("Input voltage: %.2f\n", voltage_in);
  delay(500);

  // use multimeter to verify the actual voltage
  dacWrite(DAC_PIN, adc_val);
}
