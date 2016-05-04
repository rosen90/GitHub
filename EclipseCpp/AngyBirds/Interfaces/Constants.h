/*
 * Constants.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

const float XPIX_RATIO = 100;
const float YPIX_RATIO = 100;
const double DEG_TO_RAD = 0.0174532925;
const double RAD_TO_DEG = 57.2957795;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const float GRAVITY_CONST = 9.8f;

const float TIME_STEP = 1 / 60.0; //the length of time passed to simulate (seconds)
const int VEL_ITERATIONS = 8;   //how strongly to correct velocity
const int POS_ITERATIONS = 3;   //how strongly to correct position


#endif /* CONSTANTS_H_ */
