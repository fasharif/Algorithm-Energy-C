import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data.csv")
print(df)

plt.figure()
plt.bar(df["algorithm"], df["time_sec"], color="seagreen")
plt.title("Runtime by Algorithm")
plt.ylabel("Seconds")
plt.show()

plt.figure()
plt.bar(df["algorithm"], df["comparisons"], color="olive")
plt.title("Comparisons by Algorithm")
plt.ylabel("Count")
plt.show()
