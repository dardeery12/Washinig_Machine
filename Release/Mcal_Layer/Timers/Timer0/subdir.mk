################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal_Layer/Timers/Timer0/Timer0.c 

OBJS += \
./Mcal_Layer/Timers/Timer0/Timer0.o 

C_DEPS += \
./Mcal_Layer/Timers/Timer0/Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal_Layer/Timers/Timer0/%.o: ../Mcal_Layer/Timers/Timer0/%.c Mcal_Layer/Timers/Timer0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


