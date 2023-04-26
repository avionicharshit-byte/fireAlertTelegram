A detailed overview of the steps and requirements to create a fire alert message on Telegram using an ESP32:

Step 1: Gather Hardware and Components 

ESP32 microcontroller: This is a powerful Wi-Fi and Bluetooth enabled microcontroller that will be used to detect fire and send alerts to Telegram.
Fire detection sensor(s): Depending on the desired method of fire detection, you may need a temperature sensor, smoke sensor, flame sensor, or a combination of sensors.
Power source: You'll need a reliable power source to power the ESP32 and other components.

Schematics:
![image](https://user-images.githubusercontent.com/78672319/234660789-b2844457-0807-4e7a-9f72-2f2b0678b974.png)



Step 2: Set up Software Environment

Arduino IDE: Install the Arduino IDE on your computer, which is an open-source software that allows you to program microcontrollers like the ESP32.
ESP32 board support: Make sure you have the ESP32 board support installed in your Arduino IDE. You can follow the instructions provided by the ESP32 documentation to install the board support.
Libraries: Install the necessary libraries for your project. This may include the UniversalTelegramBot library, which provides functions to interact with Telegram APIs, and any other libraries required for your specific fire detection sensors.

Step 3: Create a Telegram Bot

Create a Telegram bot using the Telegram platform. This involves creating a new bot on Telegram, obtaining an API token, and configuring bot settings, such as bot name, description, and profile picture. The API token is a unique code that identifies your bot and allows it to send and receive messages on Telegram.
Obtain Chat ID: Note down the Chat ID of the desired recipient or group on Telegram, to which the fire alert messages will be sent. You can obtain the Chat ID by sending a message to the recipient/group using the Telegram bot and then querying the Telegram bot API to get the Chat ID.

Setting up telegram bot:

Log in to your telegram app and follow the steps;

1. Search "@BotFather" it is an official telegram bot creator.

![image](https://user-images.githubusercontent.com/78672319/234656247-9cc6980d-5567-4f7e-aa50-2c3e3a362408.png)


![image](https://user-images.githubusercontent.com/78672319/234656491-19a2e723-9a83-4973-bf65-b37d2a7fd5ae.png)


![image](https://user-images.githubusercontent.com/78672319/234656683-09bc88c8-745c-456a-9fcf-767e351a955c.png)

![image](https://user-images.githubusercontent.com/78672319/234656857-1b71eb0f-11dc-43a5-a307-1171e8cc48b6.png)


Getting your chat Id:

Search "@myidbot" and follow as shown in picture below:

![image](https://user-images.githubusercontent.com/78672319/234657180-4b24e7c6-ce5f-4e8d-8528-31551025d4ed.png)


Step 4: ESP32 Programming

Read Sensor Data: Program the ESP32 to read input from the fire detection sensor(s) to detect the presence of fire. This may involve reading sensor data, such as temperature, smoke, or flame level, and processing it to determine if a fire event has occurred.
Send Telegram Alert: If a fire event is detected, use the UniversalTelegramBot library to send a fire alert message to the Telegram bot. This can include relevant information, such as the location and severity of the fire. Use the Telegram bot API and the obtained API token to send messages to the desired Chat ID. You can access the arduino sketch in the repository.

Step 5: Telegram Bot Message Handling

Configure Message Handlers: Configure the Telegram bot to handle incoming fire alert messages. This may involve setting up appropriate message handlers in the bot's code to receive and process fire alert messages from the ESP32.
Take Actions: Once the fire alert message is received by the Telegram bot, it can take appropriate actions, such as sending notifications to designated recipients, storing the information in a database, or triggering alarms. You can customize the actions based on your specific requirements.

Step 6: Testing and Deployment

Thoroughly test the system to ensure that it properly detects fire events and sends alert messages to the designated recipients.
Consider Security Measures: Implement appropriate security measures, such as encrypting the messages or implementing authentication mechanisms, to protect the system from unauthorized access.

Deploy the System: Once the system is tested and functioning properly, deploy it in the desired location, such as a building or a designated fire-prone area, to provide fire alert notifications in case of fire events.
Remember to follow appropriate safety guidelines and regulations when dealing with fire detection systems and always prioritize the safety of individuals and properties.

Precautions 
- Upload the code to esp32 in isolation i.e. nothing should be connected to esp32 while uplaoding the code 
- If you are using esp32 wroom 32 module then you have to press boot button while uploading the code.
- Try to use the 4g wifi for connecting esp32 to wifi , In some cases 5G shows some issues while connecting to esp32.
- Try to give the power to esp32 through 3.3 volt not through Vin or through 5 volt, it can damage the esp32.  
