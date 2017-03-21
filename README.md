# TMp
Metronome project. 
This project is written in C for Freedom KL46Z platfrom with built on ARM Cortex-M0+ processor.
In this project were used additional external peripherals: buzzer and AVT1616v2 module (buzzer and button).

SW1 and SW3 buttons (KL46Z platfrom) decrease and increase BPM value. 
TSI set up metre in 0-7 range.
Metre and BPM are displayed on the FRDM lcd.
Accented measure is raised by buzzer located in AVT1616v2 module, the other - by external buzzer.
Additionally, during accented measure is lighten up red led, during non-accented is lighten up green led.
One of the buttons located on the AVT1616v2 module is used for turning the metronome on/off.
