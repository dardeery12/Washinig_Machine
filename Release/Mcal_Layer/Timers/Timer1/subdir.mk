################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal_Layer/Timers/Timer1/Timer1.c 

OBJS += \
./Mcal_Layer/Timers/Timer1/Timer1.o 

C_DEPS += \
./Mcal_Layer/Timers/Timer1/Timer1.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal_Layer/Timers/Timer1/%.o: ../Mcal_Layer/Timers/Timer1/%.c Mcal_Layer/Timers/Timer1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


