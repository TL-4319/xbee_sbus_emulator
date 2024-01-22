#include "sbus.h"
bfs::SbusTx sbus_tx(&Serial1, false);
bfs::SbusData data;

void setup(){
  Serial.begin(115200);
  while(!Serial){}
  sbus_tx.Begin();
  data.lost_frame = false;
  data.failsafe = false;
  data.ch17 = false;
  data.ch18 = false;
  data.ch[0] = 172;
  data.ch[1] = 172;
  data.ch[2] = 172;
  data.ch[3] = 172;
  data.ch[4] = 1811;
  data.ch[5] = 172;
  data.ch[6] = 1811;
  data.ch[7] = 172;
  data.ch[8] = 172;
  data.ch[9] = 172;
  data.ch[10] = 172;
  data.ch[11] = 172;
  data.ch[12] = 172;
  data.ch[13] = 172;
  data.ch[14] = 172;
  data.ch[15] = 172;
  sbus_tx.data(data);
  sbus_tx.Write();
  for (uint8_t i = 0; i < 25; i++){
    //if (sbus_tx.buf_[i] < 0x10){Serial.print("0");}
    Serial.print(sbus_tx.buf_[i]);
    Serial.print(",");
  }
}

void loop() {
}
