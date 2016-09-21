/*
 * tape.h
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#ifndef TAPE_H_
#define TAPE_H_
#include "publication.h"

class Tape : public Publication
{
public:
	Tape();
	void getData();
	void showData();
	virtual ~Tape();
private:
	float playingTime;
};

#endif /* TAPE_H_ */
