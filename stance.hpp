/* 
 * File:   stance.hpp
 * Author: garys
 *
 * Created on February 19, 2016, 2:23 PM
 */

#ifndef STANCE_HPP
#define	STANCE_HPP

enum stance {
	STANCE_IDLE = 0,
	STANCE_LEFT_UPPER_PUNCH,
	STANCE_LEFT_FLAT_PUNCH,
	STANCE_LEFT_LOWER_PUNCH,
	STANCE_RIGHT_UPPER_PUNCH,
	STANCE_RIGHT_FLAT_PUNCH,
	STANCE_RIGHT_LOWER_PUNCH,
	STANCE_KICK,
        STANCE_GRAB,
        STANCE_THROW,
        STANCE_REVERSAL,
	STANCE_BLOCK,

	STANCE_OFF_IDLE,
	STANCE_OFF_LEFT_UPPER_PUNCH,
	STANCE_OFF_LEFT_FLAT_PUNCH,
	STANCE_OFF_LEFT_LOWER_PUNCH,
	STANCE_OFF_RIGHT_UPPER_PUNCH,
	STANCE_OFF_RIGHT_FLAT_PUNCH,
	STANCE_OFF_RIGHT_LOWER_PUNCH,
	STANCE_OFF_KICK,
        STANCE_OFF_GRAB,
        STANCE_OFF_THROW,
        STANCE_OFF_REVERSAL,
	STANCE_OFF_BLOCK
};

#endif	/* STANCE_HPP */

