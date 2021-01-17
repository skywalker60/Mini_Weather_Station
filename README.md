# Mini_Weather_Station(IOT mini Project)

## An ESP-32 based mini weather station 

 Components Required:
```

  ESP32 Dev Toolkit
  DHT11/22 sensor
  BMP180 barometric sensor
  
  
```
Software used :
Thinkspeak and Arduino ide

Procedure:

1. Connect the DHT11 to the ESP32 board via jumper wires ti 3.3 V and GND pins,and connect the data pin of DHT11 to the 4 pin on the ESP32.
Same with the pressure sensor for GND and Vin , and connect the data pin to any of the input pins of the ESP32 board

2. After doing the connections change the given codes wifi credentials and ThinkSpeak api key to your liking

3. Then connect the ESP32 to your laptop or PC via a USB B type connector

4. Then in the arduino IDE upload the code while pressing the boot button on the ESP32 board (until it finishes writing)
After the writing and compiling is done , press EN button on the ESP32 for getting the output.

5. This should run the code on the board and give you all the required values, and check the Thinkspeak channel for the graphs for the aquired values.


For instruction on how to use the thinkspeak api check out this this repo by [Mathworks Github Page](https://github.com/mathworks/thingspeak-arduino)
