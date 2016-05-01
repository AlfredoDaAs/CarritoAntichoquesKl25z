################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/cTemplate.c" \

C_SRCS += \
../Sources/cTemplate.c \

OBJS += \
./Sources/cTemplate.o \

C_DEPS += \
./Sources/cTemplate.d \

OBJS_QUOTED += \
"./Sources/cTemplate.o" \

C_DEPS_QUOTED += \
"./Sources/cTemplate.d" \

OBJS_OS_FORMAT += \
./Sources/cTemplate.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/cTemplate.o: ../Sources/cTemplate.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/cTemplate.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/cTemplate.o"
	@echo 'Finished building: $<'
	@echo ' '


