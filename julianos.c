//////////////////////////////
//   Fecha en julianos      //
//  rommeljose@gmail.com    //
//   Cumana - Enero  2011   //
//////////////////////////////
/*(Los astr�nomos numeran cada per�odo de 24 horas, 
 * comenzando y terminando al mediod�a, con un n�mero entero �nico, 
 * el N�mero de d�a juliano [7]. El d�a cero juliano fue hace mucho tiempo; 
 * un punto de referencia conveniente es que el d�a juliano 2440000 
 * comenz� al mediod�a del 23 de mayo de 1968. Si conoce el N�mero 
 * de d�a juliano que comienza al mediod�a de una fecha determinada del 
 * calendario, entonces el d�a de la semana de esa fecha se obtiene 
 * sumando 1 y tomando el resultado m�dulo base 7; una respuesta cero 
 * corresponde a Domingo, 1 al lunes,:::, 6 al s�bado.).
 */

#include <18F25k20.h>

#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 4000000)


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <flex_lcd.c>

 float julday(float mm,int id, long int iyyy);
 
/*En esta rutina, julday devuelve el n�mero de d�a juliano que comienza 
 * al mediod�a de la fecha del calendario especificada por mes mm, 
 * id de d�a y a�o iyyy, todas variables enteras. A�o positivo significa A.D .;
 *  negativo, B.C. Recuerde que el a�o posterior al 1 a. C. fue el a�o 1 d.C.
 * Numerical Recipes In C: The Ar Of Scientific Computing - William H. Press, 
 * 
 * Tomada de: Brian P. Flannery, Saul A. Teukolsky, William T. Vetterling. 
 * Cambridge University Press�(1992). P�gina 11-12.
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
