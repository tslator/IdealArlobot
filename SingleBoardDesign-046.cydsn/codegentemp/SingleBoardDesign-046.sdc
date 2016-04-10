# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Documents\PSoC Creator\IdealArlobot\SingleBoardDesign-046.cydsn\SingleBoardDesign-046.cyprj
# Date: Sun, 10 Apr 2016 15:31:29 GMT
#set_units -time ns
create_clock -name {Infrared_ADC_intClock(FFB)} -period 62.5 -waveform {0 31.25} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {EZI2C_1_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {HCSR04_Clock(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {PWM_1MHz(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_12}] [get_pins {ClockBlock/ff_div_13}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Infrared_ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 7} [list]
create_generated_clock -name {Quadrature_Decode_Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list [get_pins {ClockBlock/udb_div_1}]]
create_generated_clock -name {EZI2C_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 31 61} [list]
create_generated_clock -name {HCSR04_Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 49 97} [list]
create_generated_clock -name {PWM_1MHz} -source [get_pins {ClockBlock/hfclk}] -edges {1 49 97} [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list [get_pins {ClockBlock/udb_div_3}]]


# Component constraints for D:\Documents\PSoC Creator\IdealArlobot\SingleBoardDesign-046.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Documents\PSoC Creator\IdealArlobot\SingleBoardDesign-046.cydsn\SingleBoardDesign-046.cyprj
# Date: Sun, 10 Apr 2016 15:31:16 GMT
