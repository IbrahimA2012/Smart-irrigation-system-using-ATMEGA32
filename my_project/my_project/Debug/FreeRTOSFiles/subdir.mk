################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOSFiles/croutine.c \
../FreeRTOSFiles/heap_1.c \
../FreeRTOSFiles/list.c \
../FreeRTOSFiles/port.c \
../FreeRTOSFiles/queue.c \
../FreeRTOSFiles/tasks.c \
../FreeRTOSFiles/timers.c 

OBJS += \
./FreeRTOSFiles/croutine.o \
./FreeRTOSFiles/heap_1.o \
./FreeRTOSFiles/list.o \
./FreeRTOSFiles/port.o \
./FreeRTOSFiles/queue.o \
./FreeRTOSFiles/tasks.o \
./FreeRTOSFiles/timers.o 

C_DEPS += \
./FreeRTOSFiles/croutine.d \
./FreeRTOSFiles/heap_1.d \
./FreeRTOSFiles/list.d \
./FreeRTOSFiles/port.d \
./FreeRTOSFiles/queue.d \
./FreeRTOSFiles/tasks.d \
./FreeRTOSFiles/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOSFiles/%.o: ../FreeRTOSFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


