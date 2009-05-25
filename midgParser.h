/*
 *  midgParser.h
 *  
 *
 *  Created by HyukChoong Kang on 09. 05. 23.
 *  Copyright 2009 University of California, Santa Cruz. All rights reserved.
 *
 */
#ifndef _MIDGPARSER_H_
#define _MIDGPARSER_H_

/************
 *defines	*
 ***********/

#define PARSEBUFSIZE 5		//MAX payload (77) + 6 frame bytes = 83 bytes, 100 bytes to be safe.
#define MESSAGEBUFSIZE 47	//Message buffer size for specifically for Message ID: 10.
#define FRAMEBYTES 6		//frame bytes which includes syncs, id, count and checksums.

void midgSort(void);
void midgChecksum(unsigned char checksum0, unsigned char checksum1);
void midgDetect(unsigned char* sync0, unsigned char* sync1, unsigned char* id, unsigned char* count);


#endif /* -MIDGPARSER_H_*/