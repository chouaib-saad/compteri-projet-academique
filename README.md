# Compteri_Project

## This projet is developed during Labs of the subject IoT Architecture :

#### By:
#### Chouaib saad

Under-graduated students, 
Embadded system and IoT Bachelors 


#### Under the supervision of:
#### Amira Henaien, 
Computer Science, Assistant Professor,
Higher Institute of Computer Science Mahdia(ISIMA),
University of Monastir Tunisia


*Title of the project:
Compteri (:a water meter systeme)

*Description:
intelligent consumption reduction and controling based on IoT

*Objectif:
-Calculation of consumption and its possible peak and projection of the monthly tariff compared to the daily and normal energy tariff.
-create a connected and intelligent object that allows the reading of the consumption meter.
-find/create an intelligent agent that allows the recognition of characters (numbers) from images.
-Warning in case of leak or the consumption is higher than normal.
-integrate a remote payment module and get rid of waiting time in front of post offices.

*List of devices:
required devices  :
-esp32-cam module : <br>
<img src="https://user-images.githubusercontent.com/106425884/209489181-06fce8cf-c6a2-43c4-96e8-3ebde009d16f.jpg" width="50%" height="50%">
-esp32 module : <br>
<img src="![esp32](https://user-images.githubusercontent.com/106425884/209489196-016231f0-73d0-480d-b7e3-cb623f3e8a24.jpg)
" width="30%" height="30%">
-raspberrypi 4 (you can  replace it with laptop) : 
<img src="https://user-images.githubusercontent.com/106425884/209489201-702fc9c4-ccac-484b-bc94-728e968df215.jpg" width="30%" height="30%">
for security system you need : (not necessarly) 
-PIR sensor :
<img src="https://user-images.githubusercontent.com/106425884/209489241-6426a0bc-49d7-4619-a44c-db60e4ac4a19.jpg" width=30%" height="30%">
-jumper wires : <br>
<img src="https://user-images.githubusercontent.com/106425884/209489223-143ffd82-a10c-4d82-9035-2729156682b3.png" width="30%" height="30%">
-Electronic Door Lock : <br>
<img src="https://user-images.githubusercontent.com/106425884/209489048-caf90bea-7eb2-4f76-8927-cdf57a904c61.jpg" width="30%" height="30%">





-First you need to download the zip file of the project which contains all the files and source codes we need.

### =>install the mobile app<=
-Download and install the mobile app : compteri app .

### =>install frimware on the esp32-cam<=
1)fixe the camera position with video streaming sketch .
2)install python from microsoft store .
3)instal the model frimware from github .
5)unzip the folder
5)copy the content of sdcard folder on a sdcard <=16GB and formatted with fat32
6)modify wlan.ini and enter username and password of your home wifi
7)connect the esp32-cam to your computer
8)insert the prepared sdcard (lust be equal or less than 16gb )

=>open command line or powershell and :
9)install the required python libraries and esp tools with:
sudo apt-get install python3-pip
sudo pip install esptool

10)navigate to the firmware folder and enter the following commands :

*Change to the directory of the loaded firmware! :
exemple :
cd C:\Users\chouaieb saad\Desktop\projet github\le module learning pour esp32-cam (pour le calcule de consommation)\firmware
*Connect the ESP32 via USB to the computer and run these lines of codes:
esptool.py.exe erase_flash
esptool.py.exe write_flash 0x01000 bootloader.bin 0x08000 partitions.bin 0x10000 firmware.bin
=> the installation should complete succesfully ! <br>

<img src="https://user-images.githubusercontent.com/106425884/209493973-3f1de797-60be-481d-93ff-db63131bd6a8.PNG" width="30%" height="30%">

en cas d'erreurs : <br>
*[su_spoiler title=”You get an error message that the ESPtool would not be present?” initial_state=”collapse”] :
pip show -f esptool

### =>upload the security module on esp32<=
-the cose is located on "code module de securite esp32.ino" run and upload the code using arduino ide with micro-usb  cable .


### =>install the broaker<=
install the broaker on the raspberrypi 4 or on laptop  :
-download and install mosquitto client server on your systeme using the offical <a href="https://mosquitto.org/download/">site</a>
-start the server with the following commands (nb : change the ip address with yours!)
-open the command prompt and visit the mosquitto files location :
cd C:\Program Files\mosquitto
-and start the server with this command :
mosquitto -v -c test.conf
<br>
<img src="https://user-images.githubusercontent.com/106425884/209494218-40f85624-f4f8-4cb3-aa8f-dd152efe0c1c.PNG" width="30%" height="30%">

<br>

-you can subscribe to the server with (example of ip address) :
mosquitto_sub -h 192.168.0.4 -t compteur/coutMesuree -d

### =>setup & connections<=

1)"compteri" carton model: <br>
<img src="https://user-images.githubusercontent.com/106425884/209491827-d3394bc7-1f32-452d-b5f4-4c80700ba7eb.jpg" width="30%" height="30%"> <br>
<img src="https://user-images.githubusercontent.com/106425884/209491834-a95febcc-166d-4afb-bfd2-bc063bf20996.jpg" width="30%" height="30%"> <br>

2) for the best result and experience use 3D printer : <br>
<img src="https://user-images.githubusercontent.com/106425884/209492126-9c536493-1ad6-49ca-91e9-6a30c310729c.jpg" width="30%" height="30%"> <br>


-esp32-cam flash diagram :

-methode1 : <br>
<img src="https://user-images.githubusercontent.com/106425884/209492564-bc6d91ce-f0bc-441d-b5c2-cc620b95d539.png" width="30%" height="30%"> <br>
-methode2 : <br>
<img src="https://user-images.githubusercontent.com/106425884/209493542-79aa86db-877d-4be7-8b9b-225dc965c661.png" width="30%" height="30%"> <br>


esp32 + delonaide door lock module : <br>
<img src="https://user-images.githubusercontent.com/106425884/209493609-e3ca9d7c-c2be-4968-a684-f74563e424ce.jpg" width="30%" height="30%"> <br>


esp32 + PIR sensor diagram : <br>
<img src="https://user-images.githubusercontent.com/106425884/209493633-73fb1de8-95a0-4fa9-957b-46d89f792021.jpg" width="30%" height="30%"> <br>

<br>
                                                                                                                                          
### Congratulation your project is ready :) !



**dashboard <br>
<img src="https://user-images.githubusercontent.com/106425884/209493813-6b28c5d2-ac5c-473d-9261-68c5ff9ce15d.jpg" width="30%" height="30%"> <br>



**mobile application :
<br>
                                                                                                                                          <center>
  <video controls>
    <source src="https://user-images.githubusercontent.com/106425884/209493831-5853e501-bccb-4adf-a828-69d4fe39999a.mp4
" type="video/mp4" />
  </video>
</center>






