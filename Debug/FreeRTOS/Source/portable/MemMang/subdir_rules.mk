################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.obj: ../FreeRTOS/Source/portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP/System_Control" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP/System_Diagnostics" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP/System_Display" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP/System_Measurements" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/APP/System_Setup" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/Common" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/HAL" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/FreeRTOS/Source/include" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/HAL" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/HAL/Buttons" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/HAL/LEDs" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/HAL/Potentiometers" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL/ADC" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL/DIO" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL/GPTM" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL/PORT" --include_path="C:/Users/Amr/workspace_v12/SEAT_HEATER_CONTROL_SYSTEM/MCAL/UART" --include_path="C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/Source/portable/MemMang/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/Source/portable/MemMang" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


