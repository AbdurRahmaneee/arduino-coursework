import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("bmp180_log.csv")
df["time_s"] = df["time_ms"] / 1000

fig, ax1 = plt.subplots()
ax1.plot(df["time_s"], df["pressure_Pa"], color="tab:blue")
ax1.set_xlabel("Time (s)")
ax1.set_ylabel("Pressure (Pa)", color="tab:blue")

ax2 = ax1.twinx()
ax2.plot(df["time_s"], df["temp_C"], color="tab:red")
ax2.set_ylabel("Temperature (°C)", color="tab:red")

plt.title("BMP180 readings")
fig.tight_layout()
fig.savefig("bmp180_plot.png", dpi=150)
plt.show()