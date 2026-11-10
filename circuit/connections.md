# Circuit Connections (Text Diagram)

Power: 2 x 18650 Li-ion cells (3.7V each) in series = 7.4V nominal (8.4V fully charged)

## 1. Power
```
Battery (+) ---> Switch ---+---> L298N 12V terminal
                           |
                           +---> Arduino Vin

Battery (-) ---+---> L298N GND terminal
               |
               +---> Arduino GND   (common ground, required)
```
Note: Keep the 5V-EN jumper on the L298N. Do NOT connect the L298N 5V pin to the Arduino, since the Arduino is powered through Vin.

## 2. Arduino to L298N (control signals)
```
Arduino D4  ---> L298N IN1   (Left motors forward)
Arduino D5  ---> L298N IN2   (Left motors backward)
Arduino D6  ---> L298N IN3   (Right motors forward)
Arduino D7  ---> L298N IN4   (Right motors backward)
Arduino GND ---> L298N GND
```
Keep the ENA and ENB jumpers in place (motors run at full speed).

## 3. L298N to Motors
```
L298N OUT1 + OUT2 ---> Left motors  (front-left and rear-left wired in parallel)
L298N OUT3 + OUT4 ---> Right motors (front-right and rear-right wired in parallel)
```
If a side spins the wrong way, swap that side's two motor wires.

## 4. HC-05 Bluetooth Module
```
HC-05 VCC ---> Arduino 5V
HC-05 GND ---> Arduino GND
HC-05 TXD ---> Arduino D0 (RX)
HC-05 RXD ---> Arduino D1 (TX)
```
Unplug HC-05 TXD/RXD while uploading code.

## 5. Full Signal Flow
```
[2x 18650 = 7.4V] --> [Switch] --+--> [L298N] --> [4 Motors]
                                 |       ^
                                 |       | IN1-IN4 (D4-D7)
                                 +--> [Arduino Uno] <--> [HC-05] <--> Phone
```
