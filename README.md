# TechTogether2020
devpost link: https://devpost.com/software/sweet-dreams-qyruhs

## Inspiration
Recurrent nightmares is a common symptom across mental illnesses, especially post traumatic stress disorder (PTSD). 1 in 11 Americans will have PTSD in their lives, and women are twice as likely as men to be diagnosed. Those with PTSD display excessive fear after experiencing a traumatic event. Many have at least 1 nightmare a week that is related to their traumatic experience. Not many treatments for nightmares are done in a realistic settings so we wanted to make a device that can monitor and help treat these nightmares. This product can be used by the individual at home, which gives the user more autonomy over their mental health care; their sleep can be tracked outside of a hospital setting.

## What it does
Sweet Dreams has three main functions:

### Nightmare Recovery
Sweet Dreams uses an accelerometer and a moisture sensor to monitor the quality of your sleep, called the Sleep Quality Index. When your Sleep Quality Index falls below a certain threshold, the system assumes you are having a nightmare or are otherwise panicked, and calms you down with a traditional 4-7-8 yoga breathing method.
### Data Analytics
Sensors monitor the room's temperature, humidity, and lighting, then easily displays them along your Sleep Quality Index for the night so you can see what conditions are best for you for sleeping.
### Light Therapy
Many PTSD suffers also suffer from insomnia. When you wake up, simply press the button on Sweet Dreams to start your light therapy.
### Sleep History
Users and doctors can view sleep history and see which therapies improved the user's sleep the most.
How we built it
We used Arduino to control the sensors:

Moisture
Accelerometer
Temperature and Humidity Sensor
Piezo Speaker -Photoresistor -LED -Push button
We used Blynk to display the data in an app format

## Challenges we ran into
We originally attempted to check out a Raspberry Pi, but we weren't able to set it up because there was no external monitor available. We also tried to publish the app from Blynk, but it requires a paid subscription.

## Accomplishments that we're proud of
We're proud that we were able to display readable information to the user. This is also a meaningful solution to a problem the greatly affects women.

## What we learned
Research in more depth the requirements for hardware before we start the project.

What's next for Sweet Dreams
Reminders:

Notifies users when to sleep
Daily check-ins on user’s mood and tiredness throughout the day
Advice on sleep hygiene
Better Sensors:

EKG
Eye movement
A real speaker
Heart rate tracker
More calming methods

Use of AI/Machine Learning

Use data from multiple users to suggest optimal sleeping conditions, meditation methods
