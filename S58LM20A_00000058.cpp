// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S58LM20A_00000058.cpp
// BSL              : 00000058
// Model number     : ABLIC S-58LM20A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 26/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "S58LM20A.h"

AnalogIn S58LM20A_adc( iS58LM20A_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t S58LM20A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( S58LM20A_adc , tbl_S58LM20A );
        return( res );
}
