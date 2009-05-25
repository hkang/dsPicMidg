/********************************************************************************/
/*  midgParser.c																*/
/* This program is a parser code for MIDG II (New Version).						*/
/* Since 05-23-2009																*/
/* Programmer: HyukChoong Kang													*/
/*  Copyright 2009 University of California, Santa Cruz. All rights reserved.	*/
/********************************************************************************/


/*********************************************/
/* 				includes					 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "midgParser.h"
#include "midg.h"


void midgSort(void) {
	
	printf("Starting.....\n");
	unsigned char midgMessage[MESSAGEBUFSIZE];
	unsigned char parserBuffer[PARSEBUFSIZE];
	unsigned int i=0, j=0, k=0, l=0, byteCount=0;
	//Few counters that would be used in this program.

	//Initializing arrays - both a parser buffer and a midg Message
	for (i=0; i<MESSAGEBUFSIZE; i++) {
		midgMessage[i]=0xFF;
	}
	for (j=0; j<PARSEBUFSIZE; j++) {			
		temp[j]=0xFF;
	}
	midgRead(unsigned char* midgChunk);
	//Read midg data from midgChunk.
	//The first data indicates # of bytes read,
	//and the last data indicates # of bytes in the buffer.
	
	if (temLen<=MESSAGEBUFSIZE) {
		for (k=0; k<MESSAGEBUFSIZE;k++) {
			midgMessage[k]=midgChunk[k+1];
		}
	}

	
}

void midgDetect(unsigned char* sync0, unsigned char* sync1, unsigned char* id, unsigned char* count) {
	for (i=1, msg_check==0; (i<MESSAGEBUFSIZE) || (msg_check==1); i++) {
		if (midgChunk[i] == sync0) {
			if (midgChunk[i+1] == sync1) {
				if (midgChunk[i+2] == id) {
					if (midgChunk[i+3] == count) {
						for (j=0; j<=midgChunk[0]; j++) {
							midgMessage[j]=midgChunk[i];
						}
						msg_check=1;
					}
				}
			}
		}
	}
}
// This midgDetect detects only for infinite data string and needs to check the checksums.
// A function before has to return a perfect data string that I want to work with.

void midgChecksum(unsigned char checksum0, unsigned char checksum1) {
	for (checksum0=0, checksum1=0, l=2; l<MESSAGEBUFSIZE-2; l++) {
		checksum0=checksum0+midgMessage[l];
		checksum1=checksum1+checksum0;
		//Checksum Algorithm...
	}
}
//Function flow: midgRead -> midgDetect -> midgChecksum -> midgValidating -> midgOut
//I've got to write midgValidating and midgOut tomorrow.

