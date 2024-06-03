#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <BluetoothSerial.h>

Adafruit_ADS1115 ads;
BluetoothSerial SerialBT;

const float b[] = {0.96286765, -0.96286765}; // Coeficientes del numerador (b)
const float a[] = {1.000, -0.92573529};      // Coeficientes del denominador (a)
float x[2] = {0};  // Buffer de entrada (xn)
float y[2] = {0};  // Buffer de salida (yn)

unsigned long startTime;
unsigned long samplingDuration = 180000; // 3 minutos 180000

byte yn_bits = 0; 

char clave = '1';

void setup(void) {
  SerialBT.begin("BluetoothESP32");
  Serial.begin(115200);

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  startTime = millis();
}

void loop(void) {
  if (SerialBT.available()) {
    char mensaje = SerialBT.read();
    if (mensaje == clave) {
      startTime = millis(); // Reiniciar el tiempo de inicio
      while (millis() - startTime < samplingDuration) {
        int16_t ppg_16bits = ads.readADC_Differential_0_1();
        float xn = ppg_16bits;
        
        // Aplicar el filtro IIR
        float yn = b[0] * xn + b[1] * x[0] - a[1] * y[0];

        // Actualizar los valores anteriores para el próximo ciclo
        x[1] = x[0];
        x[0] = xn;
        y[1] = y[0];
        y[0] = yn;

        //yn_bits = map(yn, 0, 800, 0, 255);
        SerialBT.println(yn);
        //SerialBT.println(yn_bits);
        Serial.println(yn);

        delay(100); // Esperar 100 ms para mantener la tasa de envío de datos a 10 Hz
      }
    }
  }
}
