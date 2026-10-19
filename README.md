# 🤖 IoT Wireless Servo Actuator with RemoteXY GUI Framework

An IoT-enabled wireless robotic arm using ESP8266 and RemoteXY GUI over local Wi-Fi. Features a hand-soldered linear power supply circuit engineered with a bridge rectifier network and LM7824 voltage regulator to deliver clean, ripple-free power to multi-axis servo actuators under heavy mechanical loads.

## 🛠️ System Architecture & Features
- **Microcontroller:** ESP8266 (Operating in local Wi-Fi Access Point Mode).
- **Control Interface:** Real-time telemetry via RemoteXY GUI framework (integrated smartphone mapped precisely to multi-axis servo PWM outputs).
- **Architecture:** Modular 3D-printed robotic arm linkages actuated by servo motors.
- **Power Delivery Network:** In-house custom-built linear power supply isolating sensitive digital logic from heavy inductive mechanical loads.

---

## 🔌 Hardware Power Circuit Specifications
To counter voltage sags and electromagnetic interference (EMI) generated under heavy mechanical loading, a custom linear regulated power supply unit (PSU) was designed and implemented:

- **Input Stage:** Center-tapped step-down transformer converting mains AC voltage.
- **Rectification Network:** Hand-soldered full-bridge rectifier circuit converting AC to unsmoothed DC.
- **Regulation Stage:** **LM7824 linear voltage regulator** paired with smoothing electrolytic filter capacitors to output a clean **24V DC rail** for high-current actuators.
- **Logic Isolation:** Integrated a secondary secondary drop-down stage (`7805`) to isolate the high-noise 24V power rail from the 5V/3.3V ESP8266 microcontroller system logic.

---

## 📁 Repository Structure
```text
📁 iot-robotic-arm/
├── 📁 sketches/         --> Pure C++/Arduino firmware configuration code (.ino)
├── 📁 schematics/       --> Hand-drawn wiring schematics and hardware architecture #On-Going
├── 📁 assets/           --> 3D assembly print logs, project photos, and video demos #On-Going
└── 📄 .gitignore        --> Native Arduino IDE temporary build filter file
```

---

## 🚀 Installation & Firmware Deployment

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/MeiranoAlkays/IoT-Wireless-Servo-Actuator-with-RemoteXY-GUI-Framework.git
   ```
2. **Setup the Toolchain:**
   - Open **Arduino IDE**.
   - Install the **ESP8266 Board Manager Package** via Preferences.
   - Install the **RemoteXY library** via the Library Manager.

3. **Secure Your Wi-Fi Configurations:**
   Open `sketches/projectcontrolservo_esp8266remotexy.ino` and replace the credentials string with your network profile:
   ```cpp
   #define REMOTEXY_WIFI_SSID "YOUR_CUSTOM_AP_NAME"
   #define REMOTEXY_WIFI_PASSWORD "YOUR_SECURE_PASSWORD"
   ```
4. **Compile & Flash:**
   Connect the ESP8266 node via USB, select your board port, and hit **Upload**. Connect your mobile device to the generated Access Point and launch the RemoteXY application.
