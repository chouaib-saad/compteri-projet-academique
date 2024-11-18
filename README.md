```markdown
# Compteri Project

## Overview

This project was developed as part of the **IoT Architecture** course. The goal of the project is to create an intelligent water meter system that allows for efficient consumption monitoring, control, and reduction using IoT technology.

### Developed by:
- **Chouaib Saad**  
  [LinkedIn](https://www.linkedin.com/in/chouaib-saad-bb4106219/)  
  Under-graduate student, Embedded Systems and IoT Bachelor's Program

### Supervised by:
- **Amira Henaien**  
  Assistant Professor, Computer Science  
  [Higher Institute of Computer Science Mahdia (ISIMA)](https://isima.rnu.tn/fra/home)  
  University of Monastir, Tunisia

## Project Title
**Compteri: Intelligent Water Meter System**

## Project Description
This project aims to reduce water consumption through IoT-based intelligent monitoring and control. It includes the following key features:
- Calculation of consumption, peak detection, and monthly tariff projection.
- Creation of a connected object for real-time consumption readings.
- An intelligent agent for optical character recognition (OCR) to read meter values.
- Alerts for leaks or unusually high consumption.
- Integration of a remote payment module for seamless bill payment.

---

## Devices Required

- **ESP32-CAM Module**  
  ![ESP32-CAM](https://user-images.githubusercontent.com/106425884/209489181-06fce8cf-c6a2-43c4-96e8-3ebde009d16f.jpg)

- **ESP32 Module**  
  ![ESP32 Module](https://user-images.githubusercontent.com/106425884/209489196-016231f0-73d0-480d-b7e3-cb623f3e8a24.jpg)

- **Raspberry Pi 4** (or laptop as a substitute)  
  ![Raspberry Pi](https://user-images.githubusercontent.com/106425884/209489201-702fc9c4-ccac-484b-bc94-728e968df215.jpg)

### Optional Security Devices
- **PIR Sensor**  
  ![PIR Sensor](https://user-images.githubusercontent.com/106425884/209489241-6426a0bc-49d7-4619-a44c-db60e4ac4a19.jpg)

- **Jumper Wires**  
  ![Jumper Wires](https://user-images.githubusercontent.com/106425884/209489223-143ffd82-a10c-4d82-9035-2729156682b3.png)

- **Electronic Door Lock**  
  ![Electronic Door Lock](https://user-images.githubusercontent.com/106425884/209489048-caf90bea-7eb2-4f76-8927-cdf57a904c61.jpg)

---

## Installation Guide

### 1. **Install the Mobile App**
Download and install the **Compteri app** to your mobile device.

---

### 2. **Install Firmware on the ESP32-CAM**
1. Fix the camera position using the video streaming sketch.
2. Install Python from the Microsoft Store.
3. Download the firmware from GitHub and unzip the folder.
4. Copy the contents of the `sdcard` folder to a microSD card (minimum 16GB, formatted to FAT32).
5. Modify `wlan.ini` with your home Wi-Fi credentials.
6. Connect the ESP32-CAM to your computer and insert the prepared SD card.

#### Install Python Libraries
Open **Command Line** or **PowerShell** and run the following commands:
```bash
sudo apt-get install python3-pip
sudo pip install esptool
```

#### Flash the ESP32-CAM
Navigate to the firmware folder and run the following commands:
```bash
esptool.py.exe erase_flash
esptool.py.exe write_flash 0x01000 bootloader.bin 0x08000 partitions.bin 0x10000 firmware.bin
```
This should successfully flash the firmware onto the ESP32-CAM.

**Note:** In case of errors, verify the installation with:
```bash
pip show -f esptool
```

---

### 3. **Upload Security Module to ESP32**
- Open the `code module de securite esp32.ino` in the Arduino IDE.
- Connect the ESP32 using a micro-USB cable and upload the code.

---

### 4. **Install Broker (MQTT) on Raspberry Pi**
1. Install Mosquitto Client Server from the [official site](https://mosquitto.org/download/).
2. Start the Mosquitto server with the following commands:
   ```bash
   cd C:\Program Files\mosquitto
   mosquitto -v -c test.conf
   ```
3. Subscribe to the server with:
   ```bash
   mosquitto_sub -h <Your IP Address> -t compteur/coutMesuree -d
   ```

---

## System Setup & Connections

1. **Carton Model of the Compteri:**
   ![Carton Model](https://user-images.githubusercontent.com/106425884/209491827-d3394bc7-1f32-452d-b5f4-4c80700ba7eb.jpg)

2. **For the best results, use a 3D Printer:**
   ![3D Printed Model](https://user-images.githubusercontent.com/106425884/209492126-9c536493-1ad6-49ca-91e9-6a30c310729c.jpg)

3. **ESP32-CAM Flash Diagrams:**
   - Method 1:  
     ![Method 1](https://user-images.githubusercontent.com/106425884/209492564-bc6d91ce-f0bc-441d-b5c2-cc620b95d539.png)
   - Method 2:  
     ![Method 2](https://user-images.githubusercontent.com/106425884/209493542-79aa86db-877d-4be7-8b9b-225dc965c661.png)

4. **ESP32 + Electronic Door Lock:**
   ![ESP32 + Door Lock](https://user-images.githubusercontent.com/106425884/209493609-e3ca9d7c-c2be-4968-a684-f74563e424ce.jpg)

5. **ESP32 + PIR Sensor:**
   ![ESP32 + PIR Sensor](https://user-images.githubusercontent.com/106425884/209493633-73fb1de8-95a0-4fa9-957b-46d89f792021.jpg)

---

## Congratulations! Your project is ready to use. 🎉

### Dashboard
![Dashboard](https://user-images.githubusercontent.com/106425884/209493813-6b28c5d2-ac5c-473d-9261-68c5ff9ce15d.jpg)

### Mobile Application Demo:
[View Mobile App Demo](https://user-images.githubusercontent.com/106425884/209493831-5853e501-bccb-4adf-a828-69d4fe39999a.mp4)

---
```
