// License       : License.txt
// Specifications: Spec-S-58LM20A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S58LM20A.cpp
// Reason for change: 01.00.00 : 12/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "S58LM20A.h"

#if     iS58LM20A_ma == iSMA                            // Simple moving average filter
static float32 S58LM20A_sma_buf[iS58LM20A_SMA_num];
static sma_f32_t S58LM20A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iS58LM20A_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &S58LM20A_sma_buf[0]                            // buffer
};

#elif   iS58LM20A_ma == iEMA                            // Exponential moving average filter
static ema_f32_t S58LM20A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iS58LM20A_EMA_K                                 // Exponential smoothing factor 
};

#elif   iS58LM20A_ma == iWMA                            // Weighted moving average filter
static float32 S58LM20A_wma_buf[iS58LM20A_WMA_num];
static wma_f32_t S58LM20A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iS58LM20A_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iS58LM20A_WMA_num * (iS58LM20A_WMA_num + 1)/2 , // kn sum
        &S58LM20A_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_S58LM20A =
{
        iS58LM20A               ,
        iS58LM20A_pin           ,
        iS58LM20A_xoff          ,
        iS58LM20A_yoff          ,
        iS58LM20A_gain          ,
        iS58LM20A_max           ,
        iS58LM20A_min           ,
        iS58LM20A_ma            ,
        
#if     iS58LM20A_ma == iSMA                            // Simple moving average filter
        &S58LM20A_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iS58LM20A_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &S58LM20A_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iS58LM20A_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &S58LM20A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
