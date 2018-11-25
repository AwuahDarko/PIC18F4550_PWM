/* 
 * File: PIC18F4550_PWM  
 * Author: Yaw Awuah Darko
 * Comments: May work on PIC18F2455/2550/4455 as well though not tested yet as at 24 Nov 2018
 * Revision history: First release
 */


#include <xc.h>
#include <stdint.h>

void setupPWM(long ,int);
void PWM1_Set_Duty(uint16_t);

#define _XTAL_FREQ 8000000
#define PS_1 1
#define PS_4 4
#define PS_16 16

void setupPWM(long PWM_Hz,int T2PSS)
{
    if(T2PSS == 1)
    {
        T2CKPS0 = 0;
        T2CKPS1 = 0;
        TMR2ON = 1;
        if(PWM_Hz != 0)
        {PR2 = (((1/PWM_Hz)/(4*(1/_XTAL_FREQ))) - 1);}
    }
    else if(T2PSS == 4)
    {
        T2CKPS0 = 1;
        T2CKPS1 = 0;
        TMR2ON = 1; 
        if(PWM_Hz != 0)
        {PR2 = (((1/PWM_Hz)/(4*4*(1/_XTAL_FREQ))) - 1);}
    }
    else if(T2PSS == 16)
    {
        T2CKPS1 = 1;
        TMR2ON = 1;
        if(PWM_Hz != 0)
        {PR2 = (((1/PWM_Hz)/(16*4*(1/_XTAL_FREQ))) - 1);}
    }
    
    CCP1M2 = 1;
    CCP1M3 = 1;  
}

void PWM1_Set_Duty(uint16_t dutycycle)
{
	dutycycle = dutycycle * 10;
  // Check The DC Value To Make Sure it's Within 10-Bit Range
  if(dutycycle<1024)
  {
    DC1B0 = dutycycle & 1;
    DC1B1 = dutycycle & 2; 
    CCPR1L = (dutycycle) >> 2;
  }
}



