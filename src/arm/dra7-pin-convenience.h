#pragma once

#define PINCONF( index, config ) \
	DRA7XX_CORE_IOPAD( 0x3400 + 4 * (index), config )

#define PIN_PRU_GPI (PIN_INPUT_PULLDOWN | MODE_SELECT | MUX_MODE12)
#define PIN_PRU_GPO (PIN_OUTPUT         | MODE_SELECT | MUX_MODE13)

#define IODELAY_IN( index, a_delay, g_delay ) \
	( 12 * (index) + 0x30 )   A_DELAY_PS( a_delay )   G_DELAY_PS( g_delay )
#define IODELAY_OUT( index, a_delay, g_delay ) \
	( 12 * (index) + 0x34 )   A_DELAY_PS( a_delay )   G_DELAY_PS( g_delay ) \
	( 12 * (index) + 0x38 )   A_DELAY_PS( a_delay )   G_DELAY_PS( g_delay )
#define IODELAY( index, in_a_delay, in_g_delay, out_a_delay, out_g_delay ) \
	IODELAY_IN( index, in_a_delay, in_g_delay ) \
	IODELAY_OUT( index, out_a_delay, out_g_delay )
