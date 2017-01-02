/*
 * App.c
 *
 *  Created on: 2 de ene. de 2017
 *      Author: facun
 */


#include "stm32f4_discovery.h"
#include "bsp/bsp.h"
#include "menu/menu.h"

void APP_GetData(uint8_t dato);
void menu_msg(int choice);
void adc_bin(uint16_t n);
float adc_volt(float adc);

typedef enum {	ST0_MP,
				ST1_ADC,
				ST2_LEDS,
				ST3_SW,
				ST4_ERROR
			} states;

states menu = ST0_MP;

uint8_t txBuffer[200];
int size;
char bin[12] = "";
char *p = bin;


int main(void)
{
BSP_Init();
	size = sprintf(txBuffer,"\tUCC TP3:\n");
	TransmitData (txBuffer, size);
	menu_msg(menu);

	for(;;);
}

void APP_GetData(uint8_t dato){

	switch (menu)
	{
		case ST0_MP:
			if		(dato == '1')
				menu = ST1_ADC;
			else if (dato == '2')
				menu = ST2_LEDS;
			else if	(dato == '3')
				menu = ST3_SW;
			else if	(dato == '0')
				menu = ST0_MP;
			else
			{	// Si entro al estado de error,se despliega el mensaje de error y retorno al menu correspondiente.
				menu = ST4_ERROR;
				menu_msg(menu);
				menu = ST0_MP;
			}
		break;

		case ST1_ADC:
		{
			uint16_t adc = 0;
			adc= BSP_ADC_GetValue();

			if (dato == '1')
			{
				p = bin;
				memset(bin,0,strlen(bin));
				if (adc == 0)
					*p = 0 + '0';
				else
					adc_bin(adc);

				size = sprintf(txBuffer,"Valor ADC: %s (%d)\n\n",bin, adc);
				TransmitData (txBuffer, size);
			}

			else if	(dato == '2')
			{
				size = sprintf(txBuffer,"Valor ADC: %d\n\n",adc);
				TransmitData (txBuffer, size);
			}
			else if	(dato == '3')
			{
				float volt;
				volt = adc_volt(adc);
				size = sprintf(txBuffer,"Valor ADC: %2.2fV (%d)\n\n",volt, adc);
				TransmitData (txBuffer, size);
			}

			else if	(dato == '0')
				menu = ST0_MP;
			else
			{
				menu = ST4_ERROR;
				menu_msg(menu);
				menu = ST1_ADC;
			}
		}
		break;

		case ST2_LEDS:
			if (dato == '1')
			{
				LedToggle(LED_ROJO);
				if(Get_LED_State(LED_ROJO))
					size = sprintf(txBuffer,"\nLED_ROJO ON \n\n");
				else
					size = sprintf(txBuffer,"\nLED_ROJO OFF \n\n");

				TransmitData (txBuffer, size);
			}

			else if (dato == '2')
			{
				LedToggle(LED_VERDE);
				if(Get_LED_State(LED_VERDE))
					size = sprintf(txBuffer,"\nLED_VERDE ON \n\n");
				else
					size = sprintf(txBuffer,"\nLED_VERDE OFF \n\n");

				TransmitData (txBuffer, size);
			}

			else if (dato == '3')
			{
				LedToggle(LED_NARANJA);
				if(Get_LED_State(LED_NARANJA))
					size = sprintf(txBuffer,"\nLED_NARANJA ON \n\n");
				else
					size = sprintf(txBuffer,"\nLED_NARANJA OFF \n\n");

				TransmitData (txBuffer, size);
			}

			else if (dato == '4')
			{
				LedToggle(LED_AZUL);
				if(Get_LED_State(LED_AZUL))
					size = sprintf(txBuffer,"\nLED_AZUL ON \n\n");
				else
					size = sprintf(txBuffer,"\nLED_AZUL OFF \n\n");

				TransmitData (txBuffer, size);
			}

			else if	(dato == '0')
				menu = ST0_MP;
			else
			{
				menu = ST4_ERROR;
				menu_msg(menu);
				menu = ST2_LEDS;
			}
		break;

		case ST3_SW:
			if	(dato == '1')
			{
				if(BSP_SW_GetState(SW_UP))
					size = sprintf(txBuffer,"\nSW1 : 1 \n\n");
				else
					size = sprintf(txBuffer,"\nSW1 : 0 \n\n");

				TransmitData (txBuffer, size);
			}

			else if	(dato == '2')
			{
				if(BSP_SW_GetState(SW_LEFT))
					size = sprintf(txBuffer,"\nSW2 : 1 \n\n");
				else
					size = sprintf(txBuffer,"\nSW2 : 0 \n\n");

				TransmitData (txBuffer, size);
			}

			else if	(dato == '3')
			{
				if(BSP_SW_GetState(SW_DOWN))
					size = sprintf(txBuffer,"\nSW3 : 1 \n\n");
				else
					size = sprintf(txBuffer,"\nSW3 : 0 \n\n");

				TransmitData (txBuffer, size);
			}

			else if	(dato == '4')
			{
				if(BSP_SW_GetState(SW_RIGHT))
					size = sprintf(txBuffer,"\nSW4 : 1 \n\n");
				else
					size = sprintf(txBuffer,"\nSW4 : 0 \n\n");

				TransmitData (txBuffer, size);
			}
			else if	(dato == '0')
				menu = ST0_MP;
			else
			{
				menu = ST4_ERROR;
				menu_msg(menu);
				menu = ST3_SW;
			}
		break;

	}

	menu_msg(menu);

}

void adc_bin(uint16_t n)
{
	if(n != 0)
	{
		adc_bin (n/2);
		*p = (n%2)+ '0';
		p++;
	}
}

float adc_volt(float adc)
{
	float volt;

	volt= adc * (3.3/4095);
	return volt;
}

void menu_msg(int choice)
{
	for(int i=0 ;i<=4 ;i++)
	{
		size = sprintf(txBuffer,"%s\n", menu1[choice][i]);
		TransmitData (txBuffer, size);
	}
}


