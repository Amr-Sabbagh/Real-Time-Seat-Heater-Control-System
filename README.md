# Seat Heater Control System

## Overview
This project implements a real-time Seat Heater Control System for the front seats of a vehicle using **FreeRTOS** on a **Tiva C** microcontroller. The system allows users to set heating levels for the driver and passenger seats while maintaining temperature control within specified ranges. The project demonstrates real-time task management, diagnostics.

### Features
- **Heating Levels:** Off, Low (25°C), Medium (30°C), High (35°C)
- **Temperature Control:** Maintains temperature within desired range ± 2°C
- **Diagnostics:** Detects and logs sensor failures when temperature readings are outside 5°C to 40°C
- **User Interface:** Displays heating level, current temperature, and system status via UART
- **Simulated Components:** Uses LEDs to represent heating intensities (green, blue, cyan) and a red LED for error indication

## Project Structure
The project is organized as follows:
- **MCAL (Microcontroller Abstraction Layer):** Contains modules for GPIO, UART, ADC, and GPTM
- **APP:** Contains application-specific modules for system functionality
- **FreeRTOS Configuration:** Includes FreeRTOS setup and configuration files

### APP Folder Modules
1. **Setup Module (`System_Setup.c`/`System_Setup.h/System_Setup_Cfg.h`)**
   - **Purpose:** Initializes system components and creates tasks, semaphores, and mutexes.
   - **Responsibilities:**
     - Defines task handles and shared resources
     - Calls initialization functions for other modules
     - Configures FreeRTOS objects for inter-task communication

2. **Control Module (`System_Control.c`/`System_Control.h`)**
   - **Purpose:** Manages heating levels and heater activation.
   - **Responsibilities:**
     - Adjusts heater intensity based on the temperature difference from the desired level
     - Handles button presses to cycle through heating levels
     - Implements logic to enable or disable heaters

3. **Diagnostics Module (`System_Diagnostics.c`/`System_Diagnostics.h`)**
   - **Purpose:** Monitors and logs system errors.
   - **Responsibilities:**
     - Detects sensor failures
     - Logs errors with timestamps
     - Displays diagnostic messages

4. **Display Module (`System_Display.c`/`System_Display.h`)**
   - **Purpose:** Sends system status to the UART for display.
   - **Responsibilities:**
     - Displays current temperature, heating level, and error status

5. **Measurement Module (`System_Measurements.c`/`System_Measurements.h`)**
   - **Purpose:** Reads temperature values from sensors.
   - **Responsibilities:**
     - Interfaces with the ADC to read sensor data
     - Simulates temperature input using a potentiometer

### Key FreeRTOS Elements
- **Tasks:**
  - **Temperature Monitoring Task:** Periodically reads temperature data from the ADC and triggers control actions if necessary.
  - **Heating Control Task:** Adjusts the heater’s intensity based on the difference between the current and desired temperatures.
  - **Button Handling Task:** Detects button presses to cycle through heating levels and updates system state accordingly.
  - **Diagnostics Task:** Monitors sensor health and logs errors if sensor values go out of the valid range.
  - **Display Task:** Sends current system information to the UART for user feedback.
  - **CPU Load Monitoring Task:** Measures and logs the CPU usage and task execution times for performance evaluation.

- **Semaphores, Mutexes, and Event Groups:**
  - **xSystemStateMutex:** provides exclusive access to the system structure.
  - **SystemControlEventGroup:** an event bit is set whenever an interrupt ocures from a button indecating a heating level change for the corresponding seat, also an event bit is set when ever a tempreture sensore reading exceeds the sensor range to log a failure in the diagnostic module.

### Pin Configuration
- **Temperature Sensor (Potentiometer):** Connect the middle pin to **ADC0** and the outer pins to **GND** and **3.3V**.
- **Control Buttons:** Connect one terminal to a GPIO pin (e.g., **PB0** for driver seat, **PB1** for passenger seat) and the other to **GND**.
- **Heater Intensity LEDs:** Connect the LED cathodes to **GND** and anodes to GPIO pins:
  - **Low Intensity (Green):** **PC0**
  - **Medium Intensity (Blue):** **PC1**
  - **High Intensity (Cyan):** **PC2**
- **Error Indicator (Red LED):** Connect the cathode to **GND** and the anode to **PC3**.

## Usage
1. **Build and Flash:** Compile the project and flash it onto a Tiva C microcontroller.
2. **Testing:** Use buttons to simulate heating level changes and a potentiometer for temperature input.
3. **UART Output:** Monitor system status through the UART interface.
