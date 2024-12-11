# mySmart Home System Documentation

## Table of Contents
1. [Overview](#overview)
2. [System Requirements](#system-requirements)
3. [Installation](#installation)
4. [Features](#features)
5. [System Architecture](#system-architecture)
6. [Usage Guide](#usage-guide)
7. [Technical Details](#technical-details)
8. [Security](#security)

## Overview
mySmart Home is a C++ based home automation system that allows users to monitor and control various electronic devices throughout their home. The system provides both manual and timer-based control options, along with energy consumption monitoring and reporting capabilities.

## System Requirements
- C++11 compatible compiler
- Standard C++ libraries
- Minimum 512MB RAM
- Terminal/Console interface support
- Operating System: Windows/Linux/MacOS

## Installation
1. Clone or download the source code
2. Compile using a C++11 compatible compiler:
```bash
g++ -std=c++11 -o smart_home main.cpp
```
3. Run the executable:
```bash
./smart_home
```

## Features

### 1. Authentication System
- Password-protected access to settings
- Default password: "5680"

### 2. Room Management
- Add multiple rooms
- Custom room naming
- Flexible room configuration

### 3. Device Management
- Add multiple devices per room
- Device specifications:
  - Custom naming
  - Power rating configuration (in watts)
  - Status monitoring (ON/OFF)
  - Usage tracking

### 4. Operating Modes

#### Manual Mode
- Direct device control
- Real-time status toggling
- Immediate response system

#### Timer Mode
- Schedule device operations
- Time-based automation
- Format: HH:MM for both ON and OFF times
- Automatic execution of scheduled tasks

### 5. Monitoring and Reporting

#### Status Enquiry
- Real-time device status
- Room-wise organization
- Current state display

#### Energy Reports
- Energy consumption calculations
- Cost estimation
- Room-wise consumption breakdown
- Billing rate: 0.009 Fils per kWh

#### Usage Trends
- Highest energy-consuming room
- Most power-intensive device
- Longest-active device statistics
- Historical usage patterns

## System Architecture

### Core Classes

#### Device Class
```cpp
class Device {
    string name;
    double powerRating;
    bool status;
    vector<ActivationRecord> activationRecords;
}
```

#### Room Class
```cpp
class Room {
    string name;
    vector<Device> devices;
}
```

#### ActivationRecord Structure
```cpp
struct ActivationRecord {
    time_t onTime;
    time_t offTime;
}
```

## Usage Guide

### Initial Setup
1. Launch the program
2. Select "Settings" (Option 1)
3. Enter the default password: "5680"
4. Choose "Initialize the system" (Option 1)
5. Add rooms and devices as needed

### Daily Operations
1. Main Menu Navigation:
   - Settings (Password protected)
   - Device Status Enquiry
   - Reports
   - Trends

2. Device Control:
   - Manual Mode: Immediate ON/OFF control
   - Timer Mode: Schedule-based operation

### Monitoring
1. Regular status checks through "Enquire device status"
2. Energy consumption monitoring via "Reports"
3. Usage pattern analysis through "Trends"

## Technical Details

### Energy Calculations
- Energy (kWh) = (Power Rating × Operating Time) / 1000
- Cost = Energy × Rate (0.009 Fils/kWh)

### Time Management
- Uses system clock for timing
- Supports 24-hour format
- Real-time monitoring and logging

### Data Storage
- Runtime memory storage
- Activation records for usage history
- Temporary storage for current session

## Security
- Password-protected settings access
- Input validation for all user inputs
- Protected system configuration
- Error handling for invalid operations

Would you like me to expand on any particular section of this README?