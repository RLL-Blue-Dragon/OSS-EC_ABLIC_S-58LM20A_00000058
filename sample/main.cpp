// License       : License.txt
// Specifications: Spec-00000058.pdf

// Include the header
#include "S58LM20A.h"                           // Using S58LM20A library

// Thread definitions ( Main Application )
Thread sen_apl;

// Immediate defines
#define iPCMP_Cyc   1000U                       // Sensor Read Cycle [ ms/bit ]

// Define Task for Sensor aplication
void ap( void );
pp2ap_adc_t S58LM20A_00000058( void );

int main( void )
{
        // Start application
        sen_apl.start( ap );
}

// Sensor Application Task
void ap( void )
{
        pp2ap_adc_t   sensor;
        float         temperature;              // Temperature [degree celsius]
        unsigned long diagnosis;                // Diagnosis result : Normal=iNormal,Max NG=iMax_NG,Min NG=iMin_NG
        
        // S58LM20A sensor read
        do{
                // Read of Temperature Sensor
                sensor = S58LM20A_00000058();
                
                temperature = sensor.phy;
                diagnosis   = sensor.sts;
                
                // Sensor Application
                
                // Application cycle wait
                thread_sleep_for( iPCMP_Cyc );
        }while(true);
}
