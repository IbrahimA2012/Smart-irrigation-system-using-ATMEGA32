/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2023
 *      Author: hamad
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG, BIT_POSN)     (REG |= (1 << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(1 << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (1 << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & 1)




#endif /* LIB_BIT_MATH_H_ */
