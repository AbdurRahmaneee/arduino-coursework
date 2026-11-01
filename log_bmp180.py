import csv
import serial

PORT = "COM3"
BAUD = 9600
OUTFILE = "bmp180_log.csv"

ser = serial.Serial(PORT, BAUD, timeout=5)

with open(OUTFILE, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["time_ms", "temp_C", "pressure_Pa"])
    print("Logging. Press Ctrl+C to stop.")
    try:
        while True:
            line = ser.readline().decode("utf-8", errors="ignore").strip()
            parts = line.split(",")
            if len(parts) == 3:
                try:
                    row = [float(p) for p in parts]
                except ValueError:
                    continue  # skip startup messages
                writer.writerow(row)
                f.flush()
                print(row)
    except KeyboardInterrupt:
        print("Stopped.")

ser.close()