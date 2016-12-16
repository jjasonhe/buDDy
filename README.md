# buDDy

## Inspiration
According to the National Highway Traffic Safety Administration, every two minutes, a person is injured in a drunk driving accident. We wanted to help solve this problem by encouraging people to always have a designated driver.

## What it does
The device was a hardware project that prompts drivers to put their keys in the drawer and shut it. It automatically locks, so you cannot get your keys back. You can go out, do your thing, and when you get back, it prompts you to pass a breath test. If it detects that you are drunk, you will not be able to get your keys back. Instead, it will text your designated friend every 30 seconds to come pick you up, until they breath in and pass the test.

## How it works
We started with the Texas Instruments TM4C123 LaunchPad, CC3100 SimpleLink Wi-Fi BoosterPack, Adafruit MiCS5524 gas sensor, Adafruit 5V mini-solenoid, Adafruit ST7735R LCD display, and various resistors and capacitors. We did a breadboard design and tested our components, first, then designed a custom PCB to create our compact device. We lasercut our custom box with acrylic and pieced it all together with hot glue. The software was written like a state machine--one state where nothing is in the box and one state where the drawer has the keys. In the first state, the code uses a busy-wait implementation and checks for a button press. When the button is pressed, it waits a predetermined amount of time so the user can open the drawer, put their keys in, and shut it. It then enters the second state. In the second state, the code again waits for a button press. When the button is pressed, the timer counts down "3, 2, 1, BREATHE!" and checks the analog-to-digital converter (ADC) value. If the user passes, it unlocks for a set amount of time, then re-locks. If the user does not pass, the lock stays locked and it stays in the current state. A text message is sent to the designated friend using the Twilio API and Node Red on IBM Bluemix.

## Challenges we ran into
The Wi-Fi incorporation, to add the texting capability, was the most challenging part. The reason is because the CC3100 libraries use a lot of the pins, so even from the start, designing our PCB to not use the CC3100 pins was difficult. We used a logic analyzer to be able to debug and see if the PCB was behaving properly. Then, the CC3100 uses some of the GPIO interrupt handlers. We originally had our buttons written with debouncing and edge-triggered interrupts, but after much debugging, we realized we could no longer do that. Thus, we had to shift all our code to a busy-wait style.

## Accomplishments we're proud of
We thought our custom box looked really clean and beautiful, which was cool. We went through two renditions--our first box was made of wood and painted red, etched with our buDDy logo. The design had flaws, though, such as not enough room for our power cable, and we hadn't though of using a drawer to hold the keys yet. Instead, it had a sliding door that was locked when the solenoid poked through a hole in the door. This was not very stable, and the wood material made the door very hard to slide at times. Therefore, we are happy we redid our box, even though it took quite a bit of extra time.

## What we learned
Sometimes, the simplest way works! We realized with the Wi-Fi that our device honestly didn't *need* edge-triggered interrupts, since it didn't need to run anything when it was waiting for button presses. If we had just gone with the simpler, busy-wait method to begin with, that would have worked fine. Not sure I'm using it properly, but Occam's Razor, right?

## What's next
We both have one more semester of school before graduation! Amanda is off to ARM to work full-time, and Jason is applying for graduate programs to do bioelectronic devices research. We likely won't be working on buDDy much more, but one idea we did have was potentially using the Wi-Fi functionality to call an Uber to the location, instead of just texting a friend. Another possible development would be creating an actual web or mobile interface where users can input their friend's phone number, etc.
