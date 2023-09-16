################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App_Main/Machine_Lcd/Machine_Lcd.c 

OBJS += \
./App_Main/Machine_Lcd/Machine_Lcd.o 

C_DEPS += \
./App_Main/Machine_Lcd/Machine_Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
App_Main/Machine_Lcd/%.o: ../App_Main/Machine_Lcd/%.c App_Main/Machine_Lcd/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


