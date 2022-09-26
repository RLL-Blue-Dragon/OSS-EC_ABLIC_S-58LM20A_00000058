// License       : License.txt
// Specifications: Spec-S-58LM20A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S58LM20A.h
// Reason for change: 01.00.00 : 12/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __S58LM20A_H__
#define __S58LM20A_H__

#include "user_define.h"

// Components number
#define iS58LM20A               103U                    // ABLIC S58LM20A

// MS58LM20A System Parts definitions
#define iS58LM20A_xoff         ( 0.561111F*iADC_vdd )   // X offset [V]
#define iS58LM20A_yoff         30.0F                    // Y offset [degree celsius]
#define iS58LM20A_gain         ( -0.00436F*iADC_vdd )   // Gain [V/degree celsius]
#define iS58LM20A_max          130.0F                   // Temperature Max [degree celsius]
#define iS58LM20A_min          -30.0F                   // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_S58LM20A;

#endif /*__S58LM20A_H__*/
