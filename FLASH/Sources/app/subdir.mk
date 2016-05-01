################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/main.c" \
"../Sources/app/sa_mtb.c" \

C_SRCS += \
../Sources/app/main.c \
../Sources/app/sa_mtb.c \

OBJS += \
./Sources/app/main.o \
./Sources/app/sa_mtb.o \

C_DEPS += \
./Sources/app/main.d \
./Sources/app/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/app/main.o" \
"./Sources/app/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/app/main.d" \
"./Sources/app/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/app/main.o \
./Sources/app/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/main.o: ../Sources/app/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/sa_mtb.o: ../Sources/app/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


