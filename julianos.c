//////////////////////////////
//   Fecha en julianos      //
//  rommeljose@gmail.com    //
//   Cumana - Enero  2011   //
//////////////////////////////
/*(Los astrónomos numeran cada período de 24 horas, 
 * comenzando y terminando al mediodía, con un número entero único, 
 * el Número de día juliano [7]. El día cero juliano fue hace mucho tiempo; 
 * un punto de referencia conveniente es que el día juliano 2440000 
 * comenzó al mediodía del 23 de mayo de 1968. Si conoce el Número 
 * de día juliano que comienza al mediodía de una fecha determinada del 
 * calendario, entonces el día de la semana de esa fecha se obtiene 
 * sumando 1 y tomando el resultado módulo base 7; una respuesta cero 
 * corresponde a Domingo, 1 al lunes,:::, 6 al sábado.).
 */

#include <18F25k20.h>

#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 4000000)


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <flex_lcd.c>

 float julday(float mm,int id, long int iyyy);
 
/*En esta rutina, julday devuelve el número de día juliano que comienza 
 * al mediodía de la fecha del calendario especificada por mes mm, 
 * id de día y año iyyy, todas variables enteras. Año positivo significa A.D .;
 *  negativo, B.C. Recuerde que el año posterior al 1 a. C. fue el año 1 d.C.
 * Numerical Recipes In C: The Ar Of Scientific Computing - William H. Press, 
 * 
 * Tomada de: Brian P. Flannery, Saul A. Teukolsky, William T. Vetterling. 
 * Cambridge University Press (1992). Página 11-12.
 */
 
 float julday(float mm, int id,  long int iyyy)
{
//	const float IGREG=15+31*(10+12*1582);    //Calendario gregoriano adoptado el 15 de octubre de 1582
	const float IGREG = 588829;
	const float ano = 1720995;
	const float  ani = 30.6001;
	float  anu;
	float  jul;
	float  ja,jm;
	signed long int jy;
	jy =iyyy;

//	if (jy == 0) nrerror("julday: there is no year zero.");
	if (jy < 0) ++jy;
	if (mm > 2) {
		jm = mm + 1;
	} else {
		--jy;
		jm = mm + 13;
	}

	jul = (float)(floor(365.25 * jy) + floor(ani * jm) + id + ano);

	anu =  31*(mm + 12 * iyyy) +id;

	if (anu >= IGREG) {
		ja = (int)(0.01 * jy);
		jul += 2-ja + (int)(0.25 * ja);
	}
	return jul;
}


void main() {

   	lcd_init();

//printf(lcd_putc,"\fFecha: %s",__DATE__);

// formato (int mm,int id, long int iyyy)

printf(lcd_putc,"\fFe: %7.0f",julday(5,23,1968));
//printf(lcd_putc,"\f 1-01-4713 a.C.");



 }
