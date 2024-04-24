# Migraine Device Control via ESP32 and BLE

This repository contains the code and documentation for a project that demonstrates how to control a migraine device using an ESP32 microcontroller, which is in turn controlled over Bluetooth Low Energy (BLE). The project uses PlatformIO as the IDE and Arduino as the framework.

## Background

Migraines are a common and debilitating condition. This project aims to provide a solution by enabling the control of a migraine device using modern technology. The device can be controlled remotely via BLE, providing a convenient and user-friendly way to manage migraines.

## Technology Stack

- **Migraine Device**: A device used to treat migraines.
- **ESP32**: A series of low-cost, low-power system-on-a-chip microcontrollers with integrated Wi-Fi and dual-mode Bluetooth.
- **BLE (Bluetooth Low Energy)**: A power-efficient variant of the classic Bluetooth technology, which is designed for short-range communication between devices.
- **PlatformIO**: An open-source ecosystem for IoT development.
- **Arduino**: An open-source electronics platform based on easy-to-use hardware and software.

## Getting Started

Follow these steps to get this project up and running on your local machine:

### Prerequisites

- An ESP32 microcontroller
- A migraine device that can be controlled electronically
- A device capable of communicating over BLE (like a smartphone or computer)
- PlatformIO IDE and Arduino framework installed on your computer

### Connection

![alt text](/images/neurawave_bb.png)

### Installation

1. **Clone the Repository**

   Open your terminal and run the following command:

   ```bash
   git clone https://github.com/yourusername/migraine-device-control.git
   ```

2. **Open the Project**

   Open the PlatformIO IDE and navigate to the directory where you cloned the repository. Open the `platformio.ini` file. PlatformIO will automatically download the necessary tools and libraries for ESP32 development with Arduino.

3. **Upload the Code**

   Connect your ESP32 to your computer. Select the correct board and port in the PlatformIO IDE, then click the upload button to upload the code to your ESP32.

### Running the Code

After uploading the code to the ESP32, you can control the migraine device using a BLE-capable device. The specifics of this will depend on the migraine device and the BLE device you are using. Please refer to their respective documentation for more information.
