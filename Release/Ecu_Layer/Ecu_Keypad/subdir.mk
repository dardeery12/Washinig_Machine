################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ecu_Layer/Ecu_Keypad/keypad.c 

OBJS += \
./Ecu_Layer/Ecu_Keypad/keypad.o 

C_DEPS += \
./Ecu_Layer/Ecu_Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Ecu_Layer/Ecu_Keypad/%.o: ../Ecu_Layer/Ecu_Keypad/%.c Ecu_Layer/Ecu_Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


