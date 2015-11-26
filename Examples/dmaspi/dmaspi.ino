#include <dmaspi.h>

#define SPI_RATE 2

#define CS 10

#define SPI_BUFF_SIZE 1000
uint8_t rx_buffer[SPI_BUFF_SIZE];
uint8_t tx_buffer[SPI_BUFF_SIZE];

void setup() {
  Serial.begin(9600);
  pinMode(CS,OUTPUT);
  digitalWrite(CS,HIGH);
  spiBegin();
  spiInit(SPI_RATE);
}

void loop() {
  uint32_t t1;
  double mbs;
  char str[64];

  digitalWrite(CS,LOW);
  t1 = micros();
  spiSend(tx_buffer,SPI_BUFF_SIZE);
  t1 = micros() - t1;
  digitalWrite(CS,HIGH);
  mbs = 8*SPI_BUFF_SIZE/(float)t1;
  sprintf(str,"%d us 84/%d= %d Mhz  %.2f mbs",t1,SPI_RATE,84/SPI_RATE,mbs);
  Serial.println(str);
  delay(3000);
}

