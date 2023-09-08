################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal_Layer/Timers/Timer2/Timer2_Program.c 

OBJS += \
./Mcal_Layer/Timers/Timer2/Timer2_Program.o 

C_DEPS += \
./Mcal_Layer/Timers/Timer2/Timer2_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal_Layer/Timers/Timer2/%.o: ../Mcal_Layer/Timers/Timer2/%.c Mcal_Layer/Timers/Timer2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


