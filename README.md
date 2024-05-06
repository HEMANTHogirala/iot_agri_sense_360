# iot_agri_sense_360
This project focuses on optimizing crop yield by monitoring soil fertility continuously,Automating the irrigation schedules,disease detection in turmeric leaves using machine learning model YOLO V5.
The project is divided into three parts:
**Automating irrigation schedules:
considers the parameters like Soil Moisture,Temperature ,Humidity from sensors namely LM35,DHT11 and based on correlation of these values irrigation schedules are optimized using solenoid valve to operate the water flow.These values can be viewed in thingspeak channel too.
**Soil Acidity Monitoring and Alerting Stake holder:
This is not a readily available product in market so we have used analog 3 way meter integrated with hx771 amplifier to convert into digital values  to read soil Ph and alert user if there is any abnormality in values .so,the stakeholder can take action accordingly.
**Disease detection:
There are two leaf diseases in turmeric namely blotch and spot.These disease samples  are collected from real time and google images in ratio og 55 and 45 respectively.Then the YOLOV5 model is trained on these labeled images and the tested on rela world images captured by esp32 cam which is interfaced with FTDI module to send images to google drive which are further analyzed using colab model.
The allround project comprising three parts alerts stakeholders to make decisions wisely in foresight and make decisions accordingly thereby contributing to optimize crop yield.As we have done this in a lab environment considering single plant ,we have used turmeric plant for testing purposes.
Note: Thingspeak channel: https://thingspeak.com/channels/2339007/private_show
Note: Architecture and results are available in paper presented at conference yet to be published.So,Incase of queries drop mail at ogiralanagasaihemanth@gmail.com
