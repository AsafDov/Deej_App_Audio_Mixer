<img width="1149" height="619" alt="image" src="https://github.com/user-attachments/assets/cb274ebf-9f73-4b12-8da4-87355facd9a3" /># Deej - PC Volume Mixer
When I play games with friends, I like to keep spotify running with my music playing in the back ground, but I also want to talk with my friends on discord. 
Sometimes I like listening to music while watching Youtube videos as well, and sometimes I like music playing in the background during a teams work meeting. 
No matter the usecase, windows' mixer requires to many actions to operate, and inteferes with the current activity. For example, during a game I need to pause and move the focus to the desktop before being able to access the equlizer.
 
####I therefore present to you an arduino micro based solution that is a definite game changer for the convenience of multitasking
![Finished Product](/assets/Finished_Deej.jpg)

## Features
- Buttons to instantly mute the channel. LED turns off.
- Configurable volume dials to adjust the volume of **any application**
- 3d printable replaceable led lit icons
- 3d printable case
- Rubber feet to prevent it sliding around

## Design Process

I used OnShape to 3d model my mixer.
![Collage](/assets/Collage.png)

Some simple 8mm LEDs, 12mm led buttons, 5kOhm potentiometers and an arduino micro later it was built!

The arduino programming was done by me, but the GO software intefacing with window's janky mixer was written by the OG creator of this project [Omri Harel](https://github.com/omriharel/deej).
All I had to do was read the potentiometers and send it down the Serial communication port to interact with the deej software.

If you want to print this for yourself, click on the image below for my printables model.
[<img width="1149" height="619" alt="image" src="https://github.com/user-attachments/assets/02852687-7a4a-4939-b758-c112217c5d8e" />](https://www.printables.com/model/1348358-deej-with-leds)
