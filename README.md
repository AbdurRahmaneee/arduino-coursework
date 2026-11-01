# Arduino UNO R4 WiFi — Coursework & Projects

A collection of Arduino sketches and Python scripts I wrote while working through an embedded-systems course on the **Arduino UNO R4 WiFi**. The work goes from blinking an LED to reading I²C sensors, driving motors and displays, logging data to a PC, and talking to the board over Wi-Fi with UDP.

Each folder is a standalone Arduino sketch (`FolderName/FolderName.ino`), so any of them can be opened directly in the Arduino IDE.

---

## Highlights

| Project | What it does | Concepts |
|---|---|---|
| [`barometer_with_graph_OLED`](barometer_with_graph_OLED/barometer_with_graph_OLED.ino) | Weather station on a 128×64 OLED. Shows temperature, humidity (DHT11) and barometric pressure (BMP180 on a GY-87). Each reading is drawn as a scrolling live graph, and a push button cycles between the screens. | I²C bus sharing, sensor fusion, auto-scaling graphs, button debouncing |
| [`client_server_gy87_press_temp`](client_server_gy87_press_temp/client_server_gy87_press_temp.ino) + [`Python/client.py`](Python/client.py) | UDP server on the R4 WiFi. A Python client sends `t`, `p` or `b`, and the board replies with temperature, pressure or both, read from the BMP180. | Wi-Fi, UDP sockets, client/server protocol, Python networking |
| [`UDP-1`](UDP-1/UDP-1.ino) | Sets an RGB LED colour remotely. The client sends `R,G,B` over UDP and the board parses the string and sets the PWM duty cycles. | String parsing, PWM, network control |
| [`log_bmp180.py`](log_bmp180.py) → [`bmp180_log.csv`](bmp180_log.csv) → [`plot_bmp180.py`](plot_bmp180.py) | Data-logging pipeline. The board streams CSV over serial, Python records it to a file, and pandas/matplotlib plot pressure and temperature against time. | pySerial, CSV, pandas, matplotlib |
| [`gy87_bmp180_altitude_tetherless_HW`](gy87_bmp180_altitude_tetherless_HW/gy87_bmp180_altitude_tetherless_HW.ino) | Battery-powered altimeter. A button press registers the base height, and the OLED then shows relative altitude from the change in pressure. | Barometric altitude, calibration, standalone UI |
| [`ping_ping_final`](ping_ping_final/ping_ping_final.ino) | A Pong-style game on the R4's built-in 12×8 LED matrix, with two buttons to move the paddle and a game-over message. | Frame buffers, game loop, collision logic |

---

## Skills demonstrated

- **Embedded C++:** variables and scope, functions with pass-by-reference, arrays, sorting, state machines, edge-triggered button handling
- **Digital and analog I/O:** pull-up/pull-down resistors (external and internal), ADC reading, PWM, perceptual (logarithmic) brightness mapping
- **Sensors:** BMP180 pressure/temperature (GY-87), DHT11 temperature/humidity, HC-SR04 ultrasonic distance, PIR motion, photoresistor, potentiometer
- **Actuators:** hobby servo, 28BYJ-48 stepper, bidirectional DC motor via TA6586 driver, passive buzzer through an S8050 transistor
- **Displays:** SSD1306 OLED (text, primitives, live graphs) and the UNO R4 12×8 LED matrix (bitmaps, scrolling text)
- **Communication:** I²C (including bus scanning), UART/Serial, Wi-Fi + UDP
- **Python tooling:** serial data logging, CSV handling, plotting with pandas/matplotlib, UDP sockets

---

## Project index

### 1. Programming fundamentals
| Sketch | Description |
|---|---|
| `firstProgram` | First sketch: Morse-style short/long LED blinks |
| `second4led` | Four LEDs blinking SOS using helper functions |
| `sosVariable` | SOS pattern refactored with variables for timing |
| `counter` | 4-bit binary counter (0–15) on four LEDs |
| `calculateCircleArea` | Arithmetic and formatted Serial output |
| `inputFromSerialMonitor` | Reading ints, floats and strings from the Serial Monitor |
| `array_first_lesson` | Arrays: enter grades, compute average, sort, find min/max |
| `global_variable` | Same grade program restructured into functions with global state |
| `local_variables` | Local variables and pass-by-reference: rectangle area/perimeter/diagonal |
| `local_variable_pot_led` | Local scope applied to a potentiometer → LED dimmer |

### 2. Analog I/O, PWM and RGB LEDs
| Sketch | Description |
|---|---|
| `analogPotReading` | Read a potentiometer and convert it to voltage |
| `analogmod` | PWM brightness ramp on an LED |
| `LEDuserInput` | Set LED brightness from Serial input on an exponential (perceived-brightness) scale |
| `ControlRGB` | Choose an RGB LED colour (R/G/B/Y/C/M/O/W) and brightness from the Serial Monitor |
| `RGB25times`, `RGB25TIMESFORLOOP` | Blink an RGB sequence N times (`while` loop vs. `for` loop) |
| `photoresistor` | Light-level reading with an LDR |

### 3. Buttons and digital input
| Sketch | Description |
|---|---|
| `ButtonSwitch_pullupResistor` | Push button with an external pull-up resistor |
| `internal_pullup_res` | The same using `INPUT_PULLUP` |
| `Toggle_LED` | Toggle an LED on each button press (edge detection) |
| `Three_Switch_LED_Toggle` | Three buttons independently toggling red/green/blue LEDs |
| `Three_Switch_LED_Toggle_internal_pullup` | The same with internal pull-ups and less wiring |

### 4. Sound and motion detection
| Sketch | Description |
|---|---|
| `Transistor_Buzzer` | Driving a buzzer through a transistor |
| `music_passive_buzzer_transistor_s8050` | Playing melodies with `tone()` and a note table |
| `PIR_sensor_lesson43` | PIR motion sensor: "Intruder Alert" vs. "All Clear" |
| `passive_buzzer_transistor_PIR` | Motion-triggered audible alarm |

### 5. Motors and actuators
| Sketch | Description |
|---|---|
| `servo1stlesson` | Servo angle set from Serial input |
| `servoANDpot` | Potentiometer-controlled servo |
| `photoresistor_servo` | Servo position follows light level |
| `Bidirectional_dc_motor_TA6586_m_CONT` | DC motor forward/reverse with a TA6586 H-bridge |
| `Bi_motor_TA6586_Mcontroller_switching_HW` | Homework: button reverses direction, potentiometer sets speed |
| `stepper_motor_control` | 28BYJ-48 stepper basics |
| `stepped_motor_switch_HW` | Homework: three buttons for ¼ turn, ½ turn forward and ½ turn reverse |

### 6. Displays and distance sensing
| Sketch | Description |
|---|---|
| `LED_matrix_R4` | Drawing bitmaps on the UNO R4 built-in LED matrix |
| `LED_Matrix_R4_texting` | Scrolling text on the LED matrix |
| `ping_pong_LED_matrix` | Bouncing-ball animation on the LED matrix |
| `ping_ping_final` | Playable Pong-style game with two buttons |
| `temp_humid_DHT11` | DHT11 temperature, humidity and heat index on button press, shown on the LED matrix |
| `OLED` | SSD1306 OLED basics: text, invert, pixels and lines |
| `HC-SR04_ultrasonic_sensor` | Ultrasonic distance measurement with `pulseIn()` |
| `ULTRASONIC_OLED_TOGGLE_HW` | Homework: press a button to measure distance and show it on the OLED |

### 7. I²C sensors: barometer and altimeter (GY-87 / BMP180)
| Sketch | Description |
|---|---|
| `scan_find_i2c_addresses` | I²C bus scanner to find device addresses |
| `gy87_temp_press` | Read temperature and pressure from the BMP180 |
| `gy87_bmp180_altitude` | Relative altitude from a base-pressure reference (Serial) |
| `gy87_bmp180_altitude_tetherless_HW` | Homework: standalone altimeter with OLED and calibration button |
| `barometer_project_nominal_pressure` | Sea-level-corrected pressure (inHg) with smoothing, shown on the OLED |
| `barometer_with_graph_OLED` | Multi-sensor weather station with scrolling graphs (see Highlights) |
| `log_bmp180.py`, `plot_bmp180.py`, `bmp180_log.csv` | Serial → CSV logger and plot script, plus a sample dataset |

### 8. Wi-Fi networking (UNO R4 WiFi)
| Sketch | Description |
|---|---|
| `UDP-1` | UDP server controlling an RGB LED from `R,G,B` messages |
| `client_server_gy87_press_temp` | UDP server returning live BMP180 readings on request |
| `Python/client.py` | Python UDP client used with both sketches |

### 9. Python practice
| File | Description |
|---|---|
| `Python/helloworld.py` | First Python script |
| `Python/grades_sorting.py` | Grade entry, bubble sort and letter grade (work in progress) |

### Instructor reference solutions
Folders ending in `_instructor_solution` or `_instructor_sol` hold the course's reference solutions. I kept them next to my own versions to compare approaches: `Altitude_bmp180_button_instructor_solution`, `barometer_plot_oled_instructor_solution`, `Bi_motor_TA6586_Mcontroller_switching_HW_instructor_sol`, `LED_Toggle_instructor_solution`.

---

## Hardware

- Arduino UNO R4 WiFi (built-in 12×8 LED matrix, ESP32-S3 Wi-Fi module)
- GY-87 10-DOF module (BMP180 barometer on I²C)
- SSD1306 128×64 I²C OLED
- DHT11, HC-SR04, PIR sensor, photoresistor, potentiometers
- Servo motor, 28BYJ-48 stepper + driver board, DC motor + TA6586 driver
- Passive buzzer, S8050 transistor, RGB and single-colour LEDs, push buttons

## Libraries

Install these through **Arduino IDE → Library Manager**:

`Adafruit BMP085 Library`, `Adafruit SSD1306`, `Adafruit GFX Library`, `Adafruit BusIO`, `Adafruit Unified Sensor`, `DHT sensor library`, `ArduinoGraphics`, `Servo`, `Stepper`

`WiFiS3` and `Arduino_LED_Matrix` come with the UNO R4 board package.

Python scripts: `pip install pyserial pandas matplotlib`

## Running the Wi-Fi sketches

The Wi-Fi credentials are kept out of the repository. In `UDP-1/` and `client_server_gy87_press_temp/`:

1. Copy `secrets.h.example` to `secrets.h`
2. Fill in your network name and password
3. Upload, open the Serial Monitor to find the board's IP address, and set `HOST` in `Python/client.py` to that address

`secrets.h` is listed in `.gitignore`, so it won't be committed by accident.
