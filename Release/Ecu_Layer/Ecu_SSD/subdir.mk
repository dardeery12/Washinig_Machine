################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ecu_Layer/Ecu_SSD/BCD_SSD.c \
../Ecu_Layer/Ecu_SSD/SSD.c 

OBJS += \
./Ecu_Layer/Ecu_SSD/BCD_SSD.o \
./Ecu_Layer/Ecu_SSD/SSD.o 

C_DEPS += \
./Ecu_Layer/Ecu_SSD/BCD_SSD.d \
./Ecu_Layer/Ecu_SSD/SSD.d 


# Each subdirectory must supply rules for building sources it contributes
Ecu_Layer/Ecu_SSD/%.o: ../Ecu_Layer/Ecu_SSD/%.c Ecu_Layer/Ecu_SSD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


