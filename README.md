# TMp
Metronome project. 
This project is written in C for Freedom KL46Z platfrom with built on ARM Cortex-M0+ processor.
In this project were used additional external peripherals: buzzer and AVT1616v2 module (buzzer and button).

SW1 and SW3 buttons (KL46Z platfrom) decrease and increase BPM value. 
TSI set up metre in 0-7 range.
Metre and BPM are displayed on the FRDM lcd.
Accented measure is raised by buzzer located in AVT1616v2 module, the other - by external buzzer.
Additionally, during accented measure is lighten up red led, during non-accented is lighten up green led.
dawania dźwięków, na płytce FRDM-KL46Z zapalają się diody- czerwona w momencie akozostałych. 
One of the buttons located on the AVT1616v2 module if for turning the metronome on/off.
