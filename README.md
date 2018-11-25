# PIC18F4550_PWM

<<<<<<< HEAD

=======
>>>>>>> fb2b73cd4e6dcaabb8e2fa784a910bc07e21431b
There are only two functions in this library

********************Functions***********************
void setupPWM(long PWM_Hz,T2PSS);
This function sets up everything needed for the PWM signal, including Timers and Period of Oscillation.

void PWM1_Set_Duty(uint16_t dutycycle);
This function is used to set the dutycycle of the PWM signal
The value of  "dutycyle" could be between 0 - 100%;


******************Definitions************************
PWM_Hz is the desired frequency of the PWM signal

T2PSS is the prescaler for the  timer2 module of the PIC18F microcontroller
#PWM in the MCU uses the Timer2 peripheral of the MCU
#The Presecale values of 1 , 4, 16 can be selected
Use  PS_1  for  prescaler 1
Use  PS_4  for  prescaler 4
Use  PS_16  for  prescaler 16

NB: make sure you define _XTAL_FREQ for your oscillator frequency
NB:make sure to set your CCP1 or CCP2 port as an output using the TRIS register
