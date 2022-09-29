// License       : License.txt
// Specifications: Spec-S-58LM20A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S58LM20A.h
// Reason for change: 01.00.00 : 12/09/'22 : New Release
//                    01.01.00 : 29/09/'22 : Data correction
//                                           Comment correction
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __S58LM20A_H__
#define __S58LM20A_H__

#include "user_define.h"

// Components number
#define iS58LM20A               103U                    // ABLIC S-58LM20A

// S-58LM20A System Parts definitions
#define iS58LM20A_xoff         1.515F                   // X offset [V]
#define iS58LM20A_yoff         30.0F                    // Y offset [degree celsius]
#define iS58LM20A_gain         -0.01177F                // Gain [V/degree celsius]
#define iS58LM20A_max          130.0F                   // Temperature Max [degree celsius]
#define iS58LM20A_min          -30.0F                   // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_S58LM20A;

#endif /*__S58LM20A_H__*/
