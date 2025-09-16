# 🌱 Off-Grid IoT Urban Farming

## Overview
Off-Grid IoT Urban Farming is a community-driven initiative that demonstrates how **low-cost IoT, open-source technologies, and aquaponics** can be combined to tackle food insecurity in underserved urban areas.  

The project explores how sensors, microcontrollers, and edge devices can create a **self-sustaining, reproducible farming model** that reduces resource use, improves yields, and empowers communities.

---

## Why This Project?
Urban communities in Zimbabwe (and many other regions) face overlapping challenges:  
- Limited access to affordable fresh food  
- Poor sanitation and recurring disease outbreaks  
- Scarce water and land resources  
- Limited exposure to practical, emerging technologies  

By leveraging **aquaponics** and **open IoT systems**, this project aims to turn these constraints into opportunities for **food security, sustainability, and skills development**.

---

## Aquaponics in Action
Aquaponics combines **aquaculture (raising fish)** with **hydroponics (growing plants in water)** to form a circular ecosystem:
- Fish waste provides natural fertilizer for plants.  
- Plants filter and clean the water, which is recirculated back to the fish.  
- IoT sensors and actuators regulate and optimize the system.  

Our implementation uses **1000L IBC totes** as growing units. These systems are:  
- **Low-cost and reproducible** — built with accessible materials  
- **Efficient** — up to 90% less water than conventional farming  
- **Chemical-free** — no pesticides, closed system  
- **Resilient** — off-season vegetable growth enabled through climate control  

---

## System Architecture

### Hardware
- **Microcontrollers & Compute**: Arduino Uno, Raspberry Pi 3  
- **Sensors**:  
  - Electroconductivity (nutrient concentration)  
  - Temperature  
  - pH  
  - Water level  
- **Actuators**: Fish feeder, water pumps, aerators  
- **Other Modules**: RTC (real-time clock), analog isolator  

### Software
- **Arduino IDE (≥1.8)** for sensor + actuator programming  
- **Node.js (LTS)** and **npm** for web services  
- **Node-RED** with Dashboard, SerialPort, and MongoDB nodes for visual IoT flows  
- **MongoDB** for time-series sensor data storage  
- **Kubernetes (K3s/K8s)** for scalable service orchestration  

---

## Features
- 📊 **Real-time Monitoring**: Graphs and dashboards powered by Node-RED  
- ♻️ **Optimized Farming**: Automated water recycling and nutrient management  
- 🚫 **Zero Pesticides**: Closed, controlled environment reduces risks  
- 📱 **Remote Access**: Data visualization on mobile or web dashboards  
- 🔗 **Open & Extensible**: Built with open-source hardware and software  

---

## Getting Started
1. Clone this repository:  
   ```bash
   git clone https://github.com/<your-username>/offgrid-iot-urban-farming.git
