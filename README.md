# Smart Traffic Sensor System (LPC1768)

## ✅ Overview
This project implements a **Smart Traffic Control System** on the **LPC1768 ARM Cortex-M3** microcontroller. It combines:
- **Traffic signal control** with IR sensors and LEDs.
- **LCD display** to show active road status.
- **Temperature and Air Quality monitoring** using ADC and sensors (LM35 + MQ135).

---

## ✅ Features
- Detects traffic on 4 roads using **IR sensors**.
- Gives **priority to busy roads**.
- Shows **traffic signal status** on 16x2 LCD.
- Reads **temperature** and **air quality** in real-time.
- Displays environmental data after each cycle.

---

## ✅ Hardware Connections
- **IR Sensors**: P2.0 - P2.3
- **Traffic LEDs**: P1.19 - P1.26
- **LCD**: P0.10 (RS), P0.11 (EN), P0.15-P0.22 (Data)
- **LM35 (Temp)**: P0.24 (AD0.1)
- **MQ135 (Gas)**: P0.25 (AD0.2)

---

## ✅ File Structure
```
src/
├── main.c        // Main loop
├── lcd.c / lcd.h // LCD control functions
├── traffic.c/h   // IR-based traffic control
├── sensors.c/h   // ADC + sensor readings
```

---

## ✅ Build & Flash
- Open in **Keil uVision** or **VS Code + ARM GCC**.
- Compile and flash to LPC1768 board.

---

## ✅ Future Improvements
- Add **IoT support** (send data to cloud).
- Adaptive green signal duration.
- Data logging.

---
**License**: MIT
