# Smart Home Automation - README

## Introduction

Welcome to the **Smart Home Automation** system! This program is designed to simulate the automation of a studio-type or 1 BHK home, focusing on controlling lights and fans in various rooms. It allows users to turn devices ON/OFF manually or schedule them using a timer, calculates energy consumption, and provides detailed reports and trends.

This README will guide you through the process of setting up, compiling, and running the program, as well as provide detailed instructions on how to use its features. The goal is to make it easy for anyone, regardless of technical background, to get started.

---

## Table of Contents

1. [System Requirements](#system-requirements)
2. [Getting the Code](#getting-the-code)
3. [Compiling the Program](#compiling-the-program)
4. [Running the Program](#running-the-program)
5. [Using the Program](#using-the-program)
   - [Initial Password Authentication](#initial-password-authentication)
   - [Main Menu Navigation](#main-menu-navigation)
   - [Settings Menu](#settings-menu)
   - [Initializing the System](#initializing-the-system)
     - [Adding Rooms](#adding-rooms)
     - [Adding Devices](#adding-devices)
   - [Mode Selection](#mode-selection)
     - [Manual Mode](#manual-mode)
     - [Timer Mode](#timer-mode)
   - [Enquiring Device Status](#enquiring-device-status)
   - [Generating Reports](#generating-reports)
   - [Viewing Trends](#viewing-trends)
6. [Troubleshooting](#troubleshooting)
7. [Closing the Program](#closing-the-program)
8. [Conclusion](#conclusion)

---

## System Requirements

To run the Smart Home Automation program, you will need:

- **Operating System:** Windows, macOS, or Linux.
- **C++ Compiler:** A compiler that supports C++11 or later (e.g., GCC, Clang, or Visual Studio).
- **Terminal/Command Prompt:** Access to the command line to compile and run the program.
- **Text Editor/IDE (Optional):** For viewing or editing the code (e.g., Visual Studio Code, Code::Blocks, Notepad++, etc.).

---

## Getting the Code

Copy the entire code provided and save it in a file named `smart_home.cpp`. Ensure that the file extension is `.cpp` to indicate that it's a C++ source file.

---

## Compiling the Program

### Step-by-Step Compilation Guide

1. **Open Command Prompt/Terminal:**

   - **Windows:** Press `Win + R`, type `cmd`, and press `Enter`.
   - **macOS/Linux:** Open the `Terminal` application.

2. **Navigate to the Directory:**

   Use the `cd` command to navigate to the directory where you saved `smart_home.cpp`.

   ```bash
   cd path/to/your/directory
   ```

3. **Compile the Code:**

   To compile the program, you need a C++ compiler. We'll use `g++` in this example.

   - **Check if g++ is Installed:**

     ```bash
     g++ --version
     ```

     If it's not installed, you may need to install it:

     - **Windows:** Install MinGW or use Windows Subsystem for Linux (WSL).
     - **macOS:** Install Xcode Command Line Tools.
     - **Linux:** Install via your package manager, e.g., `sudo apt-get install g++`.

   - **Compile the Program:**

     ```bash
     g++ -std=c++11 -o smart_home smart_home.cpp
     ```

     - `-std=c++11` specifies that we are using the C++11 standard.
     - `-o smart_home` specifies the output executable file name.

   - **Note:** If you encounter any errors during compilation, refer to the [Troubleshooting](#troubleshooting) section.

---

## Running the Program

Once the program is compiled successfully, you can run it using the following command:

```bash
./smart_home
```

- **Windows Users:** Use `smart_home.exe` instead of `./smart_home`.

---

## Using the Program

### Overview

The Smart Home Automation program is menu-driven, providing an interactive command-line interface. You will navigate through various menus to set up the system, control devices, and view reports.

### Initial Password Authentication

Upon starting the program, you will be prompted to enter a password. This is to ensure that only authorized users can access the system settings.

- **Password:** `5680`
- **Instructions:**

  1. When prompted, type `5680` and press `Enter`.
  2. If you enter the wrong password, you will have up to **three attempts** before the program exits.
  3. Upon successful authentication, you will proceed to the Main Menu.

### Main Menu Navigation

The Main Menu provides access to all the primary functions of the program.

**Main Menu Options:**

1. **Settings**
2. **Enquire device status**
3. **Reports**
4. **Trends**
5. **Exit**

**Instructions:**

- Type the number corresponding to the option you wish to select and press `Enter`.
- Example: To go to Settings, type `1` and press `Enter`.

### Settings Menu

The Settings Menu allows you to initialize the system and select operational modes for your devices.

**Settings Menu Options:**

1. **Initialize the system**
2. **Select modes**
3. **Exit**

### Initializing the System

Before using the system, you need to initialize it by adding rooms and devices.

#### Adding Rooms

According to the project scope, the system supports two rooms: **Bedroom** and **Living Room**.

**Instructions:**

1. From the Settings Menu, select **1** to **Initialize the system**.
2. From the Initialize Menu, select **1** to **Add rooms**.
3. The program will automatically add "Bedroom" and "Living Room".
   - You will see a confirmation message: `Rooms 'Bedroom' and 'Living Room' added.`

#### Adding Devices

You can add devices to each room, limited to a maximum of **3 lights and 1 fan** per room.

**Instructions:**

1. From the Initialize Menu, select **2** to **Add devices**.
2. For each room, the program will prompt you to enter the power ratings for each device.
   - **Adding Lights:**
     - You will be prompted three times to enter the power rating for `Light 1`, `Light 2`, and `Light 3`.
     - Enter a positive number (in watts) each time and press `Enter`.
   - **Adding Fan:**
     - You will be prompted to enter the power rating for the `Fan`.
     - Enter a positive number (in watts) and press `Enter`.
3. Repeat the process for the second room.
4. After adding devices to both rooms, you will return to the Initialize Menu.

**Example:**

- Entering power ratings for the Bedroom:
  - `Enter power rating (in watts) for Light 1: 60`
  - `Enter power rating (in watts) for Light 2: 40`
  - `Enter power rating (in watts) for Light 3: 75`
  - `Enter power rating (in watts) for Fan: 100`

### Mode Selection

After initializing the system, you can select the operational mode for your devices.

**Mode Options:**

1. **Manual Mode**
2. **Timer Mode**
3. **Exit**

**Instructions:**

1. From the Settings Menu, select **2** to **Select modes**.
2. Choose between **Manual Mode** and **Timer Mode** by entering **1** or **2**.
3. Follow the prompts for the selected mode.

#### Manual Mode

In Manual Mode, you can manually turn devices ON or OFF.

**Instructions:**

1. Select **1** for **Manual Mode**.
2. The program will display a list of rooms.
3. Type the number corresponding to the room you want to access and press `Enter`.
4. The program will display a list of devices in the selected room.
   - Each device will show its current status: `(ON)` or `(OFF)`.
5. Type the number corresponding to the device you want to toggle and press `Enter`.
6. The program will update the status of the device and record the activation time.

**Example:**

- Selecting the Bedroom:
  - `Select a room: 1`
- Toggling Light 1:
  - `Select a device to toggle its status: 1`
  - If Light 1 was OFF, it will now be ON, and vice versa.

#### Timer Mode

In Timer Mode, you can schedule devices to turn ON and OFF at specific times.

**Instructions:**

1. Select **2** for **Timer Mode**.
2. The program will display a list of rooms.
3. Type the number corresponding to the room you want to access and press `Enter`.
4. The program will display a list of devices in the selected room.
5. Type the number corresponding to the device you want to schedule and press `Enter`.
6. You will be prompted to enter the ON and OFF times in `HH:MM` format (24-hour clock).
   - Example:
     - `Enter ON time (HH:MM): 05:30`
     - `Enter OFF time (HH:MM): 07:00`
7. The program will schedule the device and inform you of its current status.
   - If the current time is within the scheduled period, the device will be ON.
   - If the scheduled times are in the future, the device will be OFF until the ON time.

**Important Notes:**

- Ensure that you enter times in the correct format and that the OFF time is after the ON time.
- The program uses your computer's system clock for scheduling.

### Enquiring Device Status

You can check the current status of all devices.

**Instructions:**

1. From the Main Menu, select **2** to **Enquire device status**.
2. The program will display each room and the status of its devices.
   - Example:
     - `Room: Bedroom`
       - `- Light 1: ON`
       - `- Fan: OFF`
     - `Room: Living Room`
       - `- Light 2: OFF`
       - `- Fan: ON`

### Generating Reports

The program can generate reports on energy consumption and cost.

**Instructions:**

1. From the Main Menu, select **3** to **Reports**.
2. The program will display:
   - Energy consumed by each device.
   - Total energy consumed in each room.
   - Total electrical units consumed across all rooms.
   - Total cost of electricity used.
3. The cost is calculated using the rate of **0.009 Fils per kWh**.

**Understanding the Report:**

- **Energy Consumption:** Calculated based on the power rating and the duration the device was ON.
- **Total Units Consumed:** Measured in kilowatt-hours (kWh). 1 unit = 1 kWh.
- **Total Cost:** Calculated as `Total Units Consumed x Rate per unit`.

**Example Output:**

```
Device: Light 1 in Bedroom
 - Energy consumed: 0.090 kWh

Room Summary - Bedroom:
Total Energy: 0.090 kWh

Results:
Total Electrical Units Consumed: 0.090 units
Total Cost: 0.0008 Fils
```

### Viewing Trends

You can view trends related to energy consumption.

**Instructions:**

1. From the Main Menu, select **4** to **Trends**.
2. The program will display:
   - Which room consumes the most energy.
   - Which device consumes the most energy.
   - Which device has been activated for the longest time.

**Understanding Trends:**

- **Most Energy Consumed:** Determined by comparing the total energy consumption of each room/device.
- **Longest Activation Time:** Based on the total duration a device has been ON.

**Example Output:**

```
Room consuming the most energy: Bedroom (0.090 kWh)
Device consuming the most energy: Light 1 in Bedroom (0.090 kWh)
Device activated for the longest time: Light 1 in Bedroom (1.50 hours)
```

---

## Troubleshooting

If you encounter any issues while compiling or running the program, refer to the following tips:

- **Compilation Errors:**
  - Ensure that you have copied the code correctly into `smart_home.cpp`.
  - Make sure all necessary headers are included at the top of the file.
  - Use the correct compiler flags (`-std=c++11`) when compiling.

- **Permission Issues (Linux/macOS):**
  - If you receive a "Permission Denied" error when running `./smart_home`, make the file executable:
    ```bash
    chmod +x smart_home
    ```

- **Incorrect Password:**
  - Remember that the password is **5680**.
  - The password is required upon starting the program and when accessing the Settings Menu.

- **Invalid Input:**
  - If you enter an invalid choice or data, the program will prompt you to try again.
  - Always follow the input format specified in the prompts.

- **Time Formatting:**
  - For Timer Mode, enter times in 24-hour format (`HH:MM`), e.g., `17:30` for 5:30 PM.

- **Time Zone Issues:**
  - The program uses your system's local time. Ensure your system clock is set correctly.

- **No Data Available:**
  - If the reports or trends indicate "No data available," make sure you have:
    - Initialized the system by adding rooms and devices.
    - Activated devices in Manual Mode or scheduled them in Timer Mode.

---

## Closing the Program

- To exit any menu, select the option labeled **Exit**.
- To terminate the program, select **5** from the Main Menu.

---

## Conclusion

You are now ready to use the Smart Home Automation program! Feel free to experiment with turning devices ON/OFF, scheduling them, and viewing the detailed reports and trends.

Remember:

- **Initialize the system first** by adding rooms and devices.
- **Use Manual Mode** for immediate control over devices.
- **Use Timer Mode** to schedule devices based on your routine.
- **Check Device Status** to see what's currently ON or OFF.
- **Generate Reports** to monitor energy consumption and costs.
- **View Trends** to understand your usage patterns.

---

**Enjoy automating your smart home!**

If you have any questions or need further assistance, don't hesitate to reach out for support.