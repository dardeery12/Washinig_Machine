################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ecu_Layer/Ecu_Dc_Motor/dc_motor.c 

OBJS += \
./Ecu_Layer/Ecu_Dc_Motor/dc_motor.o 

C_DEPS += \
./Ecu_Layer/Ecu_Dc_Motor/dc_motor.d 


# Each subdirectory must supply rules for building sources it contributes
Ecu_Layer/Ecu_Dc_Motor/%.o: ../Ecu_Layer/Ecu_Dc_Motor/%.c Ecu_Layer/Ecu_Dc_Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


