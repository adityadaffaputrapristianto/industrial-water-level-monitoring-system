# Industrial Water Level Monitoring System using Arduino UNO

A mini industrial-style water level monitoring and alarm system built using Arduino UNO.

This project simulates a basic industrial tank monitoring system commonly used in automation and instrumentation engineering.

---

# Project Overview

The system continuously monitors water level using a water level sensor connected to Arduino UNO.

When the water level becomes too low:

- Red LED turns ON
- Passive buzzer activates
- Green LED turns OFF

When sufficient water is detected:

- Green LED turns ON
- Red LED and buzzer turn OFF

This project introduces basic industrial instrumentation concepts such as:

- Level sensing
- Process monitoring
- Alarm systems
- Industrial indicator systems
- Basic automation logic

---

# Features

- Real-time water level monitoring
- Low water level alarm system
- Visual warning indicators
- Audible alarm using passive buzzer
- Serial monitor monitoring
- Industrial-style monitoring logic

---

# Components Used

| Component | Quantity |
|---|---|
| Arduino UNO R3 | 1 |
| Water Level Sensor | 1 |
| Red LED | 1 |
| Green LED | 1 |
| 220Ω Resistors | 2 |
| Passive Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | Several |

---

# System Logic

| Water Condition | Green LED | Red LED | Buzzer |
|---|---|---|---|
| Water Detected | ON | OFF | OFF |
| Low Water Level | OFF | ON | ON |

---

# Circuit Connections

## Water Level Sensor

| Sensor Pin | Arduino |
|---|---|
| S | A0 |
| + | +5V |
| - | GND |

---

## Green LED

| LED Pin | Arduino |
|---|---|
| Positive (+) | D2 |
| Negative (-) | GND through 220Ω resistor |

---

## Red LED

| LED Pin | Arduino |
|---|---|
| Positive (+) | D3 |
| Negative (-) | GND through 220Ω resistor |

---

## Passive Buzzer

| Buzzer Pin | Arduino |
|---|---|
| Positive (+) | D4 |
| Negative (-) | GND |

---

# Arduino Code

```cpp
int sensorPin = A0;

int ledHijau = 2;
int ledMerah = 3;
int buzzer = 4;

void setup() {

  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int waterValue = analogRead(sensorPin);

  Serial.print("Water Level: ");
  Serial.println(waterValue);

  // Low water level
  if(waterValue < 300) {

    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);

    tone(buzzer, 1000);

  }

  // Water detected
  else {

    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);

    noTone(buzzer);

  }

  delay(500);
}
```

---

# How It Works

The water level sensor detects the presence of water by measuring conductivity across the sensor traces.

Arduino reads the analog signal from the sensor using pin A0.

If the water level falls below the threshold:

- Red LED activates
- Passive buzzer sounds
- Green LED turns OFF

Otherwise:

- Green LED remains ON
- Alarm stays OFF

---

# Serial Monitor

Open:

```text
Tools → Serial Monitor
```

Baud rate:

```text
9600
```

The serial monitor displays real-time water level values.

---

# Applications

This project can simulate:

- Industrial water tank monitoring systems
- Reservoir monitoring systems
- Water storage alarms
- Basic process monitoring systems
- Introductory instrumentation systems

---

# Future Improvements

Possible future upgrades:

- Automatic pump control
- Relay module integration
- LCD display integration
- IoT monitoring
- SCADA/HMI simulation
- Multi-level tank monitoring
- Automatic refill system

---

# Project Preview

![Project](images/project.jpg)

---

# Author

Aditya Daffa

---

# License

This project is open-source and free to use for educational purposes.
