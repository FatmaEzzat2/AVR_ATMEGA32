#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define REGISTER_SIZE     8
// Set bit BIT in REG
#define SET_BIT(REG,BIT)     REG |=(1<<BIT)
// Clear bit BIT in REG
#define CLR_BIT(REG,BIT)     REG &=~(1<<BIT)
// Toggle bit BIT in REG
#define TGL_BIT(REG,BIT)     REG ^=(1<<BIT)  
// Get bit BIT in REG
#define GET_BIT(REG,BIT)     ((REG>>BIT)&1)

// Set high nibble in REG
#define SET_HIGH_NIB(REG)    REG |= 0XF0
// Clear high nibble in REG
#define CLR_HIGH_NIB(REG)    REG &= 0X0F 
// Get high nibble in REG
#define GET_HIGH_NIB(REG)    (REG>>4)
// Toggle high nibble in REG
#define TGL_HIGH_NIB(REG)   REG ^= 0X0F 
// Set low nibble in REG
#define SET_LOW_NIB(REG)    REG |= 0X0F 
// Clear low nibble in REG
#define CLR_LOW_NIB(REG)    REG &= 0XF0
// Get low nibble in REG
#define GET_LOW_NIB(REG)   (REG<<4)>>4
// Toggle low nibble in REG
#define TGL_LOW_NIB(REG)    REG ^= 0X0F

// Assign VALUE to REG
#define ASSIGN_REG(REG,VALUE)       REG = VALUE
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG,VALUE)  REG =((VALUE<<4) | REG) 
// Assign VALUE to low nibble REG
#define ASSIGN_LOW_NIB(REG,VALUE)   REG =(VALUE | REG) 
// Right shift by NO in REG
#define RSHFT_REG(REG, NO)          REG >>= NO
// Left shift by NO in REG
#define LSHFT_REG(REG, NO)          REG <<= NO 
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO)         REG = ( REG >> NO)| (REG <<(REGISTER_SIZE-NO))
// Circular left shift by NO in REG
#define CLSHFT_REG(REG,NO)           REG = ( REG << NO)| (REG >>(REGISTER_SIZE-NO))


#endif