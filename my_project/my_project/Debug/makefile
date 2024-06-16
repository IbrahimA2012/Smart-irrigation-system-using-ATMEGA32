################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer1/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/External\ interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/stepper/subdir.mk
-include HAL/keypad/subdir.mk
-include HAL/Servo/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/7\ segment/subdir.mk
-include FreeRTOSFiles/subdir.mk
-include APP/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
my_project.lss \

FLASH_IMAGE += \
my_project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: my_project.elf secondary-outputs

# Tool invocations
my_project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,my_project.map -mmcu=atmega32 -o "my_project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

my_project.lss: my_project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S my_project.elf  >"my_project.lss"
	@echo 'Finished building: $@'
	@echo ' '

my_project.hex: my_project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex my_project.elf  "my_project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: my_project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 my_project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) my_project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
