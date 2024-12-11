#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <map>
#include <thread>
#include <sstream>  // For stringstream

// Utility function to get current date and time as a string
std::string currentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm *tm_local = std::localtime(&now_c);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%c", tm_local);
    return std::string(buffer);
}

// Activation record for devices
struct ActivationRecord {
    std::time_t onTime;
    std::time_t offTime;
};

// Device class
class Device {
public:
    std::string name;
    double powerRating; // in watts
    bool status; // true = ON, false = OFF
    std::vector<ActivationRecord> activationRecords;

    Device(std::string n, double p) : name(n), powerRating(p), status(false) {}

    // Calculate energy consumed by this device
    double calculateEnergyConsumed() const {
        double totalEnergy = 0.0;
        for (const auto& record : activationRecords) {
            double duration = difftime(record.offTime, record.onTime) / 3600.0; // in hours
            totalEnergy += (powerRating / 1000.0) * duration;
        }
        return totalEnergy;
    }

    // Calculate total activation time
    double totalActiveTime() const {
        double totalTime = 0.0;
        for (const auto& record : activationRecords) {
            totalTime += difftime(record.offTime, record.onTime);
        }
        return totalTime; // in seconds
    }
};

// Room class
class Room {
public:
    std::string name;
    std::vector<Device> devices;

    Room(std::string n) : name(n) {}
};

// Authentication function
bool authenticateUser() {
    const std::string PASSWORD = "5680";
    std::string input;
    std::cout << "Enter password: ";
    std::cin >> input;
    if (input == PASSWORD) {
        return true;
    } else {
        std::cout << "Incorrect password.\n";
        return false;
    }
}

// Function prototypes
void mainMenu(std::vector<Room>& rooms);
void settingsMenu(std::vector<Room>& rooms);
void initializeMenu(std::vector<Room>& rooms);
void addRooms(std::vector<Room>& rooms);
void addDevices(std::vector<Room>& rooms);
void modeSelectionMenu(std::vector<Room>& rooms);
void manualMode(std::vector<Room>& rooms);
void timerMode(std::vector<Room>& rooms);
void enquireDeviceStatus(const std::vector<Room>& rooms);
void displayReports(const std::vector<Room>& rooms);
void displayTrends(const std::vector<Room>& rooms);
void updateFeatures(std::vector<Room>& rooms);

// Main function
int main() {
    std::vector<Room> rooms;
    mainMenu(rooms);
    return 0;
}

// Main Menu function
void mainMenu(std::vector<Room>& rooms) {
    int choice;
    do {
        // Display menu options
        std::cout << "####################################################\n";
        std::cout << " Welcome to mySmart Home\n";
        std::cout << "Main Menu\n";
        std::cout << "Press\n";
        std::cout << "1. Settings\n";
        std::cout << "2. Enquire device status\n";
        std::cout << "3. Reports\n";
        std::cout << "4. Trends\n";
        std::cout << "5. Exit\n";
        std::cout << currentDateTime();
        std::cout << "\n####################################################\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (authenticateUser()) {
                    settingsMenu(rooms);
                }
                break;
            case 2:
                enquireDeviceStatus(rooms);
                break;
            case 3:
                displayReports(rooms);
                break;
            case 4:
                displayTrends(rooms);
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

// Settings Menu function
void settingsMenu(std::vector<Room>& rooms) {
    int choice;
    do {
        std::cout << "####################################################\n";
        std::cout << " Welcome to mySmart Home\n";
        std::cout << "Settings Menu\n";
        std::cout << "Press\n";
        std::cout << "1. Initialize the system\n";
        std::cout << "2. Update the features\n";
        std::cout << "3. Select modes\n";
        std::cout << "4. Exit\n";
        std::cout << currentDateTime();
        std::cout << "\n####################################################\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                initializeMenu(rooms);
                break;
            case 2:
                updateFeatures(rooms);
                break;
            case 3:
                modeSelectionMenu(rooms);
                break;
            case 4:
                std::cout << "Exiting Settings Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Initialize Menu function
void initializeMenu(std::vector<Room>& rooms) {
    int choice;
    do {
        std::cout << "####################################################\n";
        std::cout << " Welcome to mySmart Home\n";
        std::cout << "Initialize Menu\n";
        std::cout << "Press\n";
        std::cout << "1. Add number of rooms\n";
        std::cout << "2. Add device\n";
        std::cout << "3. Exit\n";
        std::cout << currentDateTime();
        std::cout << "\n####################################################\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addRooms(rooms);
                break;
            case 2:
                addDevices(rooms);
                break;
            case 3:
                std::cout << "Exiting Initialize Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Function to add rooms
void addRooms(std::vector<Room>& rooms) {
    int numRooms;
    std::cout << "Enter number of rooms: ";
    std::cin >> numRooms;
    for (int i = 0; i < numRooms; ++i) {
        std::string roomName;
        std::cout << "Enter name for Room " << (i + 1) << ": ";
        std::cin >> roomName;
        rooms.emplace_back(roomName);
        std::cout << "Room \"" << roomName << "\" added.\n";
    }
}

// Function to add devices to rooms
void addDevices(std::vector<Room>& rooms) {
    if (rooms.empty()) {
        std::cout << "No rooms available. Please add rooms first.\n";
        return;
    }
    for (auto& room : rooms) {
        int numDevices;
        std::cout << "Adding devices to " << room.name << ".\n";
        std::cout << "How many devices in " << room.name << "?: ";
        std::cin >> numDevices;
        for (int i = 0; i < numDevices; ++i) {
            std::string deviceName;
            double powerRating;
            std::cout << "Enter name for Device " << (i + 1) << ": ";
            std::cin >> deviceName;
            std::cout << "Enter power rating (in watts) for " << deviceName << ": ";
            std::cin >> powerRating;
            room.devices.emplace_back(deviceName, powerRating);
            std::cout << "Device \"" << deviceName << "\" added to " << room.name << ".\n";
        }
    }
}

// Mode Selection Menu function
void modeSelectionMenu(std::vector<Room>& rooms) {
    if (rooms.empty()) {
        std::cout << "No rooms and devices available. Please initialize the system first.\n";
        return;
    }
    int choice;
    do {
        std::cout << "####################################################\n";
        std::cout << " Welcome to mySmart Home\n";
        std::cout << "Mode Selection Menu\n";
        std::cout << "Press\n";
        std::cout << "1. Manual Mode\n";
        std::cout << "2. Timer Mode\n";
        std::cout << "3. Exit\n";
        std::cout << currentDateTime();
        std::cout << "\n####################################################\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manualMode(rooms);
                break;
            case 2:
                timerMode(rooms);
                break;
            case 3:
                std::cout << "Exiting Mode Selection Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Manual Mode function
void manualMode(std::vector<Room>& rooms) {
    int roomChoice;
    int deviceChoice;

    std::cout << "Manual Mode\n";
    // List rooms
    for (size_t i = 0; i < rooms.size(); ++i) {
        std::cout << (i + 1) << ". " << rooms[i].name << "\n";
    }
    std::cout << "Select a room: ";
    std::cin >> roomChoice;
    if (roomChoice < 1 || roomChoice >(int)rooms.size()) {
        std::cout << "Invalid room selection.\n";
        return;
    }
    Room& selectedRoom = rooms[roomChoice - 1];
    // List devices in the selected room
    for (size_t i = 0; i < selectedRoom.devices.size(); ++i) {
        std::cout << (i + 1) << ". " << selectedRoom.devices[i].name << " ("
            << (selectedRoom.devices[i].status ? "ON" : "OFF") << ")\n";
    }
    std::cout << "Select a device to toggle its status: ";
    std::cin >> deviceChoice;
    if (deviceChoice < 1 || deviceChoice >(int)selectedRoom.devices.size()) {
        std::cout << "Invalid device selection.\n";
        return;
    }
    Device& selectedDevice = selectedRoom.devices[deviceChoice - 1];
    // Toggle device status
    if (selectedDevice.status) {
        // Device is ON, turn it OFF
        selectedDevice.status = false;
        selectedDevice.activationRecords.back().offTime = std::time(nullptr);
        std::cout << selectedDevice.name << " turned OFF.\n";
    } else {
        // Device is OFF, turn it ON
        selectedDevice.status = true;
        ActivationRecord newRecord;
        newRecord.onTime = std::time(nullptr);
        newRecord.offTime = newRecord.onTime; // Initialize offTime
        selectedDevice.activationRecords.push_back(newRecord);
        std::cout << selectedDevice.name << " turned ON.\n";
    }
}

// Timer Mode function
void timerMode(std::vector<Room>& rooms) {
    int roomChoice;
    int deviceChoice;
    std::string onTimeStr, offTimeStr;
    std::tm tm_on = {}, tm_off = {};

    std::cout << "Timer Mode\n";
    // List rooms
    for (size_t i = 0; i < rooms.size(); ++i) {
        std::cout << (i + 1) << ". " << rooms[i].name << "\n";
    }
    std::cout << "Select a room: ";
    std::cin >> roomChoice;
    if (roomChoice < 1 || roomChoice > (int)rooms.size()) {
        std::cout << "Invalid room selection.\n";
        return;
    }
    Room& selectedRoom = rooms[roomChoice - 1];
    // List devices in the selected room
    for (size_t i = 0; i < selectedRoom.devices.size(); ++i) {
        std::cout << (i + 1) << ". " << selectedRoom.devices[i].name << "\n";
    }
    std::cout << "Select a device to schedule: ";
    std::cin >> deviceChoice;
    if (deviceChoice < 1 || deviceChoice > (int)selectedRoom.devices.size()) {
        std::cout << "Invalid device selection.\n";
        return;
    }
    Device& selectedDevice = selectedRoom.devices[deviceChoice - 1];

    std::cout << "Enter ON time (HH:MM): ";
    std::cin >> onTimeStr;
    std::cout << "Enter OFF time (HH:MM): ";
    std::cin >> offTimeStr;

    // Parse ON time
    std::istringstream iss_on(onTimeStr);
    iss_on >> std::get_time(&tm_on, "%H:%M");
    if (iss_on.fail()) {
        std::cout << "Invalid ON time format.\n";
        return;
    }

    // Parse OFF time
    std::istringstream iss_off(offTimeStr);
    iss_off >> std::get_time(&tm_off, "%H:%M");
    if (iss_off.fail()) {
        std::cout << "Invalid OFF time format.\n";
        return;
    }

    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    tm_on.tm_year = now_tm->tm_year;
    tm_on.tm_mon = now_tm->tm_mon;
    tm_on.tm_mday = now_tm->tm_mday;
    tm_off.tm_year = now_tm->tm_year;
    tm_off.tm_mon = now_tm->tm_mon;
    tm_off.tm_mday = now_tm->tm_mday;

    std::time_t on_time = std::mktime(&tm_on);
    std::time_t off_time = std::mktime(&tm_off);

    if (difftime(off_time, on_time) <= 0) {
        std::cout << "OFF time must be after ON time.\n";
        return;
    }

    std::cout << "Device \"" << selectedDevice.name << "\" scheduled from "
        << onTimeStr << " to " << offTimeStr << ".\n";

    // Simulate waiting until ON time
    std::time_t current_time = std::time(nullptr);
    double seconds_until_on = difftime(on_time, current_time);
    if (seconds_until_on > 0) {
        std::cout << "Waiting until ON time...\n";
        std::this_thread::sleep_for(std::chrono::seconds((int)seconds_until_on));
    } else {
        std::cout << "ON time is in the past. Turning device ON immediately.\n";
    }

    // Turn device ON
    selectedDevice.status = true;
    ActivationRecord newRecord;
    newRecord.onTime = std::time(nullptr); // Record actual ON time
    newRecord.offTime = off_time;
    selectedDevice.activationRecords.push_back(newRecord);
    std::cout << "Device \"" << selectedDevice.name << "\" turned ON.\n";

    // Simulate device being ON until OFF time
    double seconds_until_off = difftime(off_time, std::time(nullptr));
    if (seconds_until_off > 0) {
        std::this_thread::sleep_for(std::chrono::seconds((int)seconds_until_off));
    }

    // Turn device OFF
    selectedDevice.status = false;
    selectedDevice.activationRecords.back().offTime = std::time(nullptr); // Record actual OFF time
    std::cout << "Device \"" << selectedDevice.name << "\" turned OFF.\n";
}

// Enquire Device Status function
void enquireDeviceStatus(const std::vector<Room>& rooms) {
    std::cout << "####################################################\n";
    std::cout << " Welcome to mySmart Home\n";
    std::cout << "Device Status\n";
    for (const auto& room : rooms) {
        std::cout << "Room: " << room.name << "\n";
        for (const auto& device : room.devices) {
            std::cout << " - " << device.name << ": " << (device.status ? "ON" : "OFF") << "\n";
        }
    }
    std::cout << currentDateTime();
    std::cout << "\n####################################################\n";
}

// Display Reports function
void displayReports(const std::vector<Room>& rooms) {
    const double ratePerUnit = 0.009; // Fils per kWh
    std::cout << "####################################################\n";
    std::cout << " Welcome to mySmart Home\n";
    std::cout << "Reports\n";
    double totalEnergy = 0.0;
    for (const auto& room : rooms) {
        double roomEnergy = 0.0;
        for (const auto& device : room.devices) {
            double energy = device.calculateEnergyConsumed();
            roomEnergy += energy;
        }
        totalEnergy += roomEnergy;
        std::cout << "Energy consumed in " << room.name << ": "
            << roomEnergy << " kWh\n";
    }
    double totalCost = totalEnergy * ratePerUnit;
    std::cout << "Total Energy Consumed: " << totalEnergy << " kWh\n";
    std::cout << "Total Cost: " << totalCost << " Fils\n";
    std::cout << currentDateTime();
    std::cout << "\n####################################################\n";
}

// Display Trends function
void displayTrends(const std::vector<Room>& rooms) {
    std::cout << "####################################################\n";
    std::cout << " Welcome to mySmart Home\n";
    std::cout << "Trends\n";

    // Which room consumes more energy?
    std::string highestEnergyRoom;
    double highestEnergy = 0.0;
    for (const auto& room : rooms) {
        double roomEnergy = 0.0;
        for (const auto& device : room.devices) {
            roomEnergy += device.calculateEnergyConsumed();
        }
        if (roomEnergy > highestEnergy) {
            highestEnergy = roomEnergy;
            highestEnergyRoom = room.name;
        }
    }
    std::cout << "Room consuming the most energy: " << highestEnergyRoom
        << " (" << highestEnergy << " kWh)\n";

    // Which device consumes more energy?
    std::string highestEnergyDevice;
    double highestDeviceEnergy = 0.0;
    for (const auto& room : rooms) {
        for (const auto& device : room.devices) {
            double deviceEnergy = device.calculateEnergyConsumed();
            if (deviceEnergy > highestDeviceEnergy) {
                highestDeviceEnergy = deviceEnergy;
                highestEnergyDevice = device.name + " in " + room.name;
            }
        }
    }
    std::cout << "Device consuming the most energy: " << highestEnergyDevice
        << " (" << highestDeviceEnergy << " kWh)\n";

    // Which device is activated for more time?
    std::string longestActiveDevice;
    double longestActiveTime = 0.0;
    for (const auto& room : rooms) {
        for (const auto& device : room.devices) {
            double activeTime = device.totalActiveTime(); // in seconds
            if (activeTime > longestActiveTime) {
                longestActiveTime = activeTime;
                longestActiveDevice = device.name + " in " + room.name;
            }
        }
    }
    std::cout << "Device activated for the longest time: " << longestActiveDevice
        << " (" << longestActiveTime / 3600.0 << " hours)\n";

    std::cout << currentDateTime();
    std::cout << "\n####################################################\n";
}

// Update Features function (placeholder, can be expanded as needed)
void updateFeatures(std::vector<Room>& rooms) {
    std::cout << "Update Features - Functionality not implemented yet.\n";
}