I used the HC-SR04 ultrasonic ranging module to learn and explore ultrasonic sensors.

The sensor has 4 pins:
- Vcc -> Power connections
- Trig -> Stands for trigger, sending an output of sound
- Echo -> Echo receives the sound when it comes back, tells us how long it takes
- GND -> Ground connection

When the trigger sends out sound, the microcontroller is set to high, 
When it receives the sound wave back, it becomes low

<img width="832" height="419" alt="image" src="https://github.com/user-attachments/assets/13289e0c-8ef3-4f32-8e5f-655d7b5396a4" />

Much like echolocation, we send an ultrasonic sound from our side labelled T, and that data is pin Trig
As for being on the receiving end, we get it from the side labelled R, and that data is in pin Echo

[HC-SR04 Datasheet.pdf](https://github.com/user-attachments/files/27289055/HC-SR04.Datasheet.pdf)

<img width="977" height="498" alt="image" src="https://github.com/user-attachments/assets/80a59514-8fa0-427e-b81b-2a29759aef03" />

With the ultrasonic sensor's function in mind, it can be used in a plethora of unique and creative ways, in my case, for learning. I took the signal and compared it to a distance of 15cm (6 inches); if it's in the vicinity, then an LED would light up.

https://github.com/user-attachments/assets/1f7b9616-f900-4c4c-91ac-d04e0e9da707



