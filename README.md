# 🤖 RSL-Integration

### Arduino Line-Following Robot Control System

This project implements the basic structure for a **line-following robot** using **Arduino**.  
It provides a modular foundation for sensor reading, motor control, and system configuration,  
following clean and scalable coding practices.

---

## 📚 Overview

**RSL-Integration** is designed as a teaching and integration base for robotics systems that use:
- **Line sensors** for path detection.
- **DC motors** controlled by PWM signals.
- **A button** for control input.
- **A buzzer** for feedback.

The project separates hardware definitions, sensor reading logic, and motor/speed control routines into modular files, making it easier to expand and maintain.

---

## 🧩 File Structure

```
RSL-Integration/
├── include/
│   └── pins.h                 # Hardware pin definitions for all sensors and actuators
├── src/
│   ├── main.cpp               # Core control loop and behavior definitions
├── lib/
|   ├── leituraSensores/
|   │    ├── leituraSensores.cpp    # Sensor setup and reading functions
|   │    └── leituraSensores.h      # Sensor function prototypes and shared variables
|   ├── controleVelocidade/
|   │    ├── controleVelocidade.cpp    # Setup and output in pwm to control motor speed
|   │    └── controleVelocidade.h      # Motor speed function prototypes and shared variables
|   ├── initStopRobo/
|   │    ├── initStopRobo.cpp    # Settings on how to stop and start the RSL
|   │    └── initStopRobo.h      # init and stop function prototypes and shared variables
├── platformio.ini             # PlatformIO configuration for Arduino
└── README.md                  # Project documentation (this file)
```

---

## ⚙️ Features

- Modular **Arduino C++** architecture using headers and source separation.
- Clear pin mappings for all components.
- Functions for:
  - Initializing sensors and motors.
  - Reading analog sensor values.
  - Controlling robot motion and speed.
  - Following a line based on sensor input.
- Extensible for PID control or other robot behaviors.

---

## 🔌 Pin Configuration

| Component        | Pin  | Description              |
|------------------|------|--------------------------|
| **Motors**       | 9, 6, 11, 10 | PWM motor control pins |
| **Sensors**      | A5–A1 | Line sensor inputs and LDR |
| **Button**       | 7 | Start/Stop input |
| **Buzzer**       | 8 | Sound feedback |
| **Misc.**        | 2–5 | Digital I/O pins for display |

Defined in [`pins.h`](include/pins.h):

```cpp
#define DISPA 3
#define DISPB 5
#define DISPC 4
#define DISPD 2
#define BOTAO 7
#define BUZZER 8
#define PWMIN1 9
#define PWMIN2 6
#define PWMIN3 11
#define PWMIN4 10
#define LE A5
#define CE A4
#define CD A3
#define LD A2
#define LDR A1
const int SENSORES[5] = {LE, CE, CD, LD, LDR};
```

---

## 🚀 Getting Started

### 🧰 Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) **or** [PlatformIO](https://platformio.org/)
- A compatible Arduino board (e.g., **Arduino Uno**, **Nano**, or **Mega**)
- Basic electronic components:
  - 5 line sensors (infrared reflectance type)
  - 2 DC motors with motor driver (e.g., L298N)
  - Push button
  - Buzzer

---

### 🛠️ Building & Uploading

1. Clone the repository:
   ```bash
   git clone https://github.com/Harveker/RSL-Integration.git
   cd RSL-Integration
   ```
2. Open the folder in **PlatformIO** or **Arduino IDE**.
3. Compile and upload to your board:
   ```bash
   pio run --target upload
   ```
   *(or use the Upload button in Arduino IDE)*

---

## 💡 Code Overview

### `main.cpp`

Defines the program’s structure and main control loop:

```cpp
void setup() {
  // Inicialização de sensores e motores
}

void loop() {
  // Lógica principal de seguir linha e controle de velocidade
}
```

Includes control-related functions:
- `seguirLinha()` → Line-following logic  
- `controleVelocidade(int velocidade)` → Adjusts motor speed  
- `paradaRobo()` → Stops robot movement  
- `initMotores()` → Initializes motor control system  

---

### `leituraSensores.cpp` / `.h`

Handles configuration and analog reading of the sensors.

```cpp
void configSensores() {
  pinMode(LE, INPUT);
  pinMode(CE, INPUT);
  pinMode(CD, INPUT);
  pinMode(LD, INPUT);
  pinMode(LDR, INPUT);
}

void lerSensores(int tamanho) {
  Serial.println("Lendo sensores...");
  for (int i = 0; i < tamanho; i++) {
    valorSensores[i] = analogRead(SENSORES[i]);
  }
}
```

---

## 🧠 Future Improvements

- Implement PID control for smoother line following.
- Add calibration routines for sensor thresholds.
- Include obstacle detection (e.g., ultrasonic sensor).
- Integrate Bluetooth or Wi-Fi telemetry.
- Add speed and direction control via PWM tuning.

---

## 🧑‍💻 Contributing

1. Fork this repository  
2. Create a new branch (`feature/my-feature`)  
3. Commit your changes  
4. Push and open a Pull Request  

---

## 🪪 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

## 🧭 Authors

Developed by [**Harveker**](https://github.com/Harveker) and collaborators.

---

### 🏁 Example Serial Output
When running with connected sensors, the serial monitor might show:
```
Lendo sensores...
Lendo sensores...
Lendo sensores...
```

---

> _“Build modular. Think scalable. Debug early.”_
