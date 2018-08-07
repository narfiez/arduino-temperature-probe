# arduino-temperature-probe
Arduino nano based temperature probe for use in a coffee roaster to log temperatures to an SD card.



## To run the system:
Plug in the Mini USB cable into the Arduino and the other end into the PC. The temperature data will be recorded on the SD card as long as it is powered.

## To view live data on PC:
Open Arduino software.
//Click “Tools” > “Board:” > “Arduino Nano”
Click “Tools” > “Port” > Select the port, something like “COM5”


![com selection](https://user-images.githubusercontent.com/40296224/43776935-b1f6e1c2-9a51-11e8-823f-e9aa320ee2ae.png)



Click “Tools” > “Serial Monitor”
If all is working, the serial monitor window will come up.

#### Note: Opening the Serial Monitor will restart the recording of data. All the previously saved data will still be on the SD card, but it will be separated by a new heading.


![serial monitor](https://user-images.githubusercontent.com/40296224/43777167-4ca6e4a6-9a52-11e8-9c3f-5b978b586fff.png)

If the SD card is not working or not plugged in, the monitor will say “Card Failure”.

![card failure](https://user-images.githubusercontent.com/40296224/43777200-61a587e0-9a52-11e8-9ae7-23993202a16e.png)


Afterwards, to view the data, unplug the USB cable to remove power to the Arduino. Remove the SD card and plug it into a computer. The file “LOG.csv” can be opened with Excel. The data should be separated into different cells as shown below.

![log](https://user-images.githubusercontent.com/40296224/43777248-7934df28-9a52-11e8-83b7-43ee10a72711.png)



If the data is not separated, and it is all in one column, select the whole column that you want to split, go to “Data” > “Text to Columns” > “Next” > Set the Delimeter to “Comma” > “Finish”

![split column](https://user-images.githubusercontent.com/40296224/43777272-895cb538-9a52-11e8-8a4f-a46fd137f2b9.png)

To view the data as a graph, select the data you want to view:

![select data](https://user-images.githubusercontent.com/40296224/43777292-9b576e0e-9a52-11e8-8d93-902d17acd217.png)

Then select to create a scatter plot. The data should be shown over time as below.

![scatter plot](https://user-images.githubusercontent.com/40296224/43777315-aefe29e8-9a52-11e8-9c6e-9bed7b4449c9.png)


If not, you may have to change some settings in excel to ensure that Decimals are separated by periods, not by commas.
Go to “File” > “Options” > Set the “Decimal Separator” to a full stop.

![decimal separator](https://user-images.githubusercontent.com/40296224/43777344-ce54d864-9a52-11e8-8d94-0385609819da.png)


