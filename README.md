
# 🚦 Smart Traffic Sensor System (LPC1768)

## ✅ Overview
This project implements a **Smart Traffic Control System** on the **LPC1768 ARM Cortex-M3** microcontroller.  
The system combines **traffic light control, IR sensors, LCD display, temperature sensing, and air quality monitoring** for enhanced traffic management.

---

## 🔍 Features
✔ **Traffic Signal Control** using LEDs and IR sensors to manage road priority.  
✔ **Automatic Detection** of vehicles using IR sensors.  
✔ **LCD Display** for real-time status of roads and sensor readings.  
✔ **Temperature & Air Quality Monitoring** for environmental data display.  
✔ **Modular Code Design** with separate files for LCD, Sensors, and Traffic Logic.  

---

## 🛠 Hardware Requirements
- **LPC1768 ARM Cortex-M3 Development Board**
- **16x2 LCD Display**
- **IR Sensors (x4)**
- **Temperature Sensor (LM35 or similar)**
- **Gas Sensor (MQ-135 or similar)**
- **LEDs (for traffic lights)**
- **Resistors, Breadboard, and Wires**

---

## 📂 Project Structure
```
Smart-Traffic-Sensor/
│
├── src/
│   ├── main.c         # Main logic integrating all modules
│   ├── lcd.c          # LCD driver functions
│   ├── lcd.h
│   ├── traffic.c      # Traffic control logic
│   ├── traffic.h
│   ├── sensors.c      # Temperature & Air quality sensors
│   ├── sensors.h
│
├── LICENSE            # MIT License
└── README.md          # Project documentation
```

---

## ⚙️ How It Works
1. **IR Sensors** detect vehicles at each road.
2. Traffic lights change dynamically based on vehicle detection.
3. **LCD** displays:
   - Current active road
   - Temperature (°C)
   - Air quality (simulated or measured via MQ-135)
4. Default cycle runs if no IR detection is triggered.

---

## ▶️ Getting Started
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Smart-Traffic-Sensor.git
   ```
2. Open the project in **Keil uVision** or **MCUXpresso** IDE.
3. Compile and flash to LPC1768 board.
4. Connect hardware as per the pin configuration in the code.

---

## 🧪 Testing
- Trigger each IR sensor → Check if the corresponding road gets priority.
- Monitor **LCD** → It should display active road, temperature, and air quality.
- Observe traffic lights → Correct LEDs should glow for each state.

---

## 📜 License
This project is licensed under the [MIT License](LICENSE).

---


