################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal_Layer/Mcal_Gpio/Mcal_Gpio.c 

OBJS += \
./Mcal_Layer/Mcal_Gpio/Mcal_Gpio.o 

C_DEPS += \
./Mcal_Layer/Mcal_Gpio/Mcal_Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal_Layer/Mcal_Gpio/%.o: ../Mcal_Layer/Mcal_Gpio/%.c Mcal_Layer/Mcal_Gpio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


