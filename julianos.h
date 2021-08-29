//////////////////////////////
//   FECHA JULIANA          //
//  rommeljose@gmail.com    //
//   Cumana - Enero  2011   //
//////////////////////////////


 float julday(float mm, int id,  long int iyyy)
{
//	const float IGREG=15+31*(10+12*1582);
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