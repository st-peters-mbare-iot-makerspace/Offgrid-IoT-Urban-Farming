import subprocess
latest_reading=subprocess.check_output(["tail","-1","sensorReadings.csv"])
print(latest_reading)
