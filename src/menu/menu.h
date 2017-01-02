/*
 * menu.h
 *
 *  Created on: 2 de ene. de 2017
 *      Author: facun
 */

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

char *menu1[5][100] = {
							{	//MENU PRINCIPAL
								"\n1. Obtener valor ADC.",
								"2. Leds.",
								"3. Estado de SW.",
								"0. Menu anterior.",
								" "
							},

							{	//SUB-MENU 1
								"1. Obtener binario.",
								"2. Obtener decimal.",
								"3. Obtener Volt.",
								"0. Menu anterior.",
								" "
							},

							{	//SUB-MENU 2
								"1. Toggle Led R.",
								"2. Toggle Led V.",
								"3. Toggle Led N.",
								"4. Toggle Led A.",
								"0. Menu anterior."
							},

							{	//SUB-MENU 3
								"1. SW1.",
								"2. SW2.",
								"3. SW3.",
								"4. SW4.",
								"0. Menu anterior."
							},

							{	//ERROR MENU
								"Ha ingresado un caracter incorrecto.",
								"Intente nuevamente con un caracter",
								"valido entre las opciones del menu.",
								"...",
								" "
							}
						};



#endif /* MENU_MENU_H_ */
