# PIC_fecha_juliana
Devuelve el número correspondiente del día juliano, a partir de una fecha en formato gregoriano (actual).

Esta rutina, devuelve el número de día juliano que comienza al mediodía de una fecha gregoriana especificada por: mes mm, id de día y año iyyy, todas variables enteras. Año positivo significa A.D .;negativo, B.C. (el año posterior al 1 a.C. fue el año 1 d.C.).

[Joseph Justus Scaliger (astrónomo francés 1540 - 1609)](https://es.wikipedia.org/w/index.php?title=Fecha_juliana&oldid=132214338), invento las fechas julianas o "días julianos". Como la cuenta progresiva a partir de un día incial tomado a priori (llamado el inicio de la era Juliana); se define al mediodía del primero de enero del año 4713 B.C. Con esta elección, todas las observaciones astronómicas históricas tienen números de dia Juliano positivos, así que todos los cálculos son simplemente restas y sumas.

Si se sabe el valor del día juliano para una fecha, y el valor del día juliano para otra fecha, simplemente se pueden restar para encontrar la distancia de fechas.

> Referencia:
>> Numerical Recipes In C: The Ar Of Scientific Computing - William H. Press.
>> Brian P. Flannery, Saul A. Teukolsky, William T. Vetterling. 
>> Cambridge University Press (1992). Página 11-12.

>> Fecha juliana. (2021, 7 de enero). Wikipedia, La enciclopedia libre. 
>> Fecha de consulta: 15:17, febrero 3, 2021 
>> desde https://es.wikipedia.org/w/index.php?title=Fecha_juliana&oldid=132214338.
