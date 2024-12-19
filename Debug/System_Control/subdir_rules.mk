################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
System_Control/%.obj: ../System_Control/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/System_Setup" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/HAL/Button" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/System_Display" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/System_Diagnostics" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/System_Control" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/System_Measurements" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/MCAL/ADC" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/HAL/LEDs" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/MCAL/AUTOSAR_DIO_PORT" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/HAL/Potentiometer" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/HAL" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/FreeRTOS/Source/include" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/MCAL" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/MCAL/GPTM" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/MCAL/UART" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="C:/Users/Amr/workspace_v12/Vehicle_Seats_Heater_Control_System/Common" --include_path="C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="System_Control/$(basename $(<F)).d_raw" --obj_directory="System_Control" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


