# PempekROV

This repo contains the proteus 8 simulation w/ all the library and arduino code for our submarine project.
There are 3 people in this team with interchangeable position, but mainly focuses on:

MUHAMMAD FARISHANIF WIDYONO (Programming and Device Building)

MUHAMMAD FATIH FAHROJI (Schematics, Programming, and Device Building

RACHMAN HANAFI (Device Building and Programming)

How to use?
1. Extract all the files inside this repo to your pc

2. Open the Library folder and copy everything

3. Open your Proteus 8 Library folder, usually located at your Proteus 8 installation folder (...\Labcenter Electronics\Proteus 8 Professional\DATA\LIBRARY)

4. Paste all the copied file inside Proteus 8 Library folder

5. Return to this repo extraction folder

6. Open beta.pdsprj with your Proteus 8

For Ultrasonic and Rain sensor please do this:

7. Right click the sensor

8. Click on edit properties

9. In the Program File column, navigate to your library extraction folder and choose UltraSonicSensor.HEX or RainSensorsTEP.HEX respectively

10. Close the edit component tab

11. Open the Arduino_Code extracted from this repo

12. Open BETA.ino with your Arduino IDE

13. On your IDE, click File then Preferences

14. Check compilation and upload box

15. Close the Preferences tab

16. On the IDE, click verify (the check symbol on top left corner) then wait until the compiling is done

17. On your Arduino IDE terminal, find "Linking everything together..." then search and copy the address of the *.HEX file.

18. Back to Proteus 8, right click the Arduino Uno Rev3 then click properties

19. On Program File, paste the copied address of the *.HEX file

20. Close the edit component tab
21. Start the simulation by clicking play on bottom left corner of Proteus 8
