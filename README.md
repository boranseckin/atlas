# atlas

A simple homemade kernel for RaspberryPi 4 (BCM2711) from scratch.

This project is my implementation of the step-by-step guide on how to create a simple operating system (OS) kernel from scratch prepared by [Sergey Matyukevich](https://github.com/s-matyukevich). While I followed his guide word for word, the original version was created for RaspberryPi 3 which unfortunately has a a different SoC (BCM2837). This required me to make some small but important changes.

### Mini UART
The first thing to implement was a way to communicate with the kernel. On RaspberryPi there are 2 different UART implementations. While `PL011` is a fully fledged UART implementation, `mini UART` is ~~relatively easier~~ simpler(?) to set up and the drawbacks are not crucial for the simple communication. The most important part of the `mini UART` implementation is setting the baud rate. 
```
baudrate = system_clock_freq / (8 * (baudrate_reg + 1))
```
Using this equation, I calculated that to have a baud rate of `115200`, `AUX_MU_BAUD_REG` should be set to `541`. However, even after this change, I was getting gibberish on my serial terminal. A rather painful and lengthy debuggin session later, I realized that the RPi 4 was underclocking itself (see this [table](https://www.raspberrypi.org/documentation/computers/configuration.html#mini-uart-and-cpu-core-frequency)) which is a huge problem when using an asynchronous communication method. To have the clock frequency fixed at `500 MHz` as desired, I had to disable the dynamic clock which is done by adding the next line to the `confix.txt` (see the [documentation](https://www.raspberrypi.org/documentation/computers/config_txt.html#force_turbo)).
```
force_turbo=1
```
With this change, `mini UART` was working proparly and I finally had a way to `print` stuff.

While on the topic of `config.txt`, I also want to mention other important settings.

1. Setting [`arm_64bit=1`](https://www.raspberrypi.org/documentation/computers/config_txt.html#arm_64bit) tells the bootloader to look for a kernel image called `kernel8.img` and also makes sure everything is configured for 64-bit since both BCM2837 and BCM2711 can run in both 32 and 64-bit modes.

2. Setting [`uart_2ndstage=1`](https://www.raspberrypi.org/documentation/computers/config_txt.html#uart_2ndstage) causes the second-stage loader and the main firmware to output diagnostic information to the serial port even before we initialized it. This is not recommended to be used but I used it to make sure the serial connection was correct and working.

Another deviation from the guide was enabling the GPIO pins for `mini UART`. On BCM2837, there is a lengthy process of changing the pull-up/pull-down behaviours of the GPIO pins (see GPIO Pull-up/down Clock Registers (`GPPUDCLKn`) on page 101). However, on BCM2711, changing the state of the pins are as easy as just setting a register called `GPIO_PUP_PDN_CNTRL_REGn`. On top of that, this step is not even necessary on BCM2711 because the reset state of the pin 14 and 15 are already low (see 5.3. Alternative Function Assignments on page 76). As a result, the lines 41 to 45 on [mini_uart.c](https://github.com/s-matyukevich/raspberry-pi-os/blob/31fc1481f529ba1a72a8a6bc62dc488b84fc2cdb/src/lesson01/src/mini_uart.c#L41-L45) from the guide can be omitted.

### PL011 UART

Compared to [Mini UART](#mini-uart), the implementation of PL011 UART was much simpler. Most importantly, PL011 UART has its own internal clock that runs at `48 MHz` by default (see [`init_uart_clock`](https://www.raspberrypi.org/documentation/computers/config_txt.html#init_uart_clock)). So, rather than forcing the whole chip to run at turbo, we can just use that clock to fix our communication speed and calculate the baud rate. Calculating the correct baud rate, however, requires a bit of reading of the technical reference manual. But once both the integer and the fraction parts are calculated and set, the rest is a breeze.

### Sources
- [ARM Peripherals Datasheet for BCM2711](https://datasheets.raspberrypi.org/bcm2711/bcm2711-peripherals.pdf)
- [ARM Peripherals Datasheet for BCM2835](https://datasheets.raspberrypi.org/bcm2835/bcm2835-peripherals.pdf) (same for BCM2837)
- [RaspberryPi Hardware Differences Explained](https://github.com/thanoskoutr/armOS/wiki/Raspberry-Pi-Hardware)
- [PrimeCell UART (PL011) Technical Reference Manual](https://developer.arm.com/documentation/ddi0183/g)

### References
- [s-matyukevich/raspberry-pi-os](https://github.com/s-matyukevich/raspberry-pi-os)
- [rockytriton/LLD](https://github.com/rockytriton/LLD/)
