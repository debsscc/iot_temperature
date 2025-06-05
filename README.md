# iot_temperature

IoT Project  
**Course**: Internet of Things  
**Students**: Débora Carvalho, Diego Morales, Pedro Bilhalva  
**Submission Date**: 06/05/2025  
**Institution**: Centro Universitário Senac-RS - Pelotas

---

## 📘 About

This project focuses on monitoring **temperature** and **humidity** levels using an IoT system.

The core components are:

- 🌡️ A **temperature and humidity sensor** (e.g., DHT11 or DHT22)
- 🧠 A **Vespa microcontroller** that reads and processes sensor data
- 🌐 **Wi-Fi** communication to connect the system to the internet
- ☁️ Integration with the **ThingSpeak API** to send and visualize data in the cloud

The internet acts as the main display interface, enabling **real-time remote monitoring** through online dashboards. This provides visibility and insights into environmental conditions.

---

## ⚙️ Technologies & Components

- Vespa microcontroller
- DHT sensor (temperature & humidity)
- Wi-Fi module (built-in or external)
- ThingSpeak API (data storage and visualization)
- Arduino IDE or MicroPython 

---

## 🚀 Features

- Real-time temperature and humidity monitoring
- Wi-Fi connectivity
- Cloud integration with ThingSpeak
- Remote data access and visualization
- Smart behavior automation based on sensor readings

---

## 📡 System Architecture

```plaintext
[ Sensor ] → [ Vespa Microcontroller ] → [ Wi-Fi ] → [ ThingSpeak API ] → [ Dashboard / Visualization ]

