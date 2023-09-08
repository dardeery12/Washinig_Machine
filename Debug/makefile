################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal_Layer/Timers/Timer1/subdir.mk
-include Mcal_Layer/Timers/Timer0/subdir.mk
-include Mcal_Layer/Mcal_Interrupt/subdir.mk
-include Mcal_Layer/Mcal_Gpio/subdir.mk
-include Ecu_Layer/Ecu_led/subdir.mk
-include Ecu_Layer/Ecu_SSD/subdir.mk
-include Ecu_Layer/Ecu_Relay/subdir.mk
-include Ecu_Layer/Ecu_Keypad/subdir.mk
-include Ecu_Layer/Ecu_Initialization/subdir.mk
-include Ecu_Layer/Ecu_Dc_Motor/subdir.mk
-include Ecu_Layer/Ecu_Char_Lcd/subdir.mk
-include Ecu_Layer/Ecu_Btn/subdir.mk
-include App_Main/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := washing_machine2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
washing_machine2.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: washing_machine2.elf secondary-outputs

# Tool invocations
washing_machine2.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,washing_machine2.map -mmcu=atmega16 -o "washing_machine2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

washing_machine2.lss: washing_machine2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S washing_machine2.elf  >"washing_machine2.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: washing_machine2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 washing_machine2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) washing_machine2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
