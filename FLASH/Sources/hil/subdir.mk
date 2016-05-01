################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/hil/HC-SR04.c" \
"../Sources/hil/LEDDvr.c" \
"../Sources/hil/MotorDvr.c" \
"../Sources/hil/PWM.c" \
"../Sources/hil/PantallaDvr.c" \
"../Sources/hil/TemperaturaDvr.c" \
"../Sources/hil/UltrasonicoDvr.c" \

C_SRCS += \
../Sources/hil/HC-SR04.c \
../Sources/hil/LEDDvr.c \
../Sources/hil/MotorDvr.c \
../Sources/hil/PWM.c \
../Sources/hil/PantallaDvr.c \
../Sources/hil/TemperaturaDvr.c \
../Sources/hil/UltrasonicoDvr.c \

OBJS += \
./Sources/hil/HC-SR04.o \
./Sources/hil/LEDDvr.o \
./Sources/hil/MotorDvr.o \
./Sources/hil/PWM.o \
./Sources/hil/PantallaDvr.o \
./Sources/hil/TemperaturaDvr.o \
./Sources/hil/UltrasonicoDvr.o \

C_DEPS += \
./Sources/hil/HC-SR04.d \
./Sources/hil/LEDDvr.d \
./Sources/hil/MotorDvr.d \
./Sources/hil/PWM.d \
./Sources/hil/PantallaDvr.d \
./Sources/hil/TemperaturaDvr.d \
./Sources/hil/UltrasonicoDvr.d \

OBJS_QUOTED += \
"./Sources/hil/HC-SR04.o" \
"./Sources/hil/LEDDvr.o" \
"./Sources/hil/MotorDvr.o" \
"./Sources/hil/PWM.o" \
"./Sources/hil/PantallaDvr.o" \
"./Sources/hil/TemperaturaDvr.o" \
"./Sources/hil/UltrasonicoDvr.o" \

C_DEPS_QUOTED += \
"./Sources/hil/HC-SR04.d" \
"./Sources/hil/LEDDvr.d" \
"./Sources/hil/MotorDvr.d" \
"./Sources/hil/PWM.d" \
"./Sources/hil/PantallaDvr.d" \
"./Sources/hil/TemperaturaDvr.d" \
"./Sources/hil/UltrasonicoDvr.d" \

OBJS_OS_FORMAT += \
./Sources/hil/HC-SR04.o \
./Sources/hil/LEDDvr.o \
./Sources/hil/MotorDvr.o \
./Sources/hil/PWM.o \
./Sources/hil/PantallaDvr.o \
./Sources/hil/TemperaturaDvr.o \
./Sources/hil/UltrasonicoDvr.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/hil/HC-SR04.o: ../Sources/hil/HC-SR04.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/HC-SR04.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/HC-SR04.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/LEDDvr.o: ../Sources/hil/LEDDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/LEDDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/LEDDvr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/MotorDvr.o: ../Sources/hil/MotorDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/MotorDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/MotorDvr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/PWM.o: ../Sources/hil/PWM.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/PWM.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/PWM.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/PantallaDvr.o: ../Sources/hil/PantallaDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/PantallaDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/PantallaDvr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/TemperaturaDvr.o: ../Sources/hil/TemperaturaDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/TemperaturaDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/TemperaturaDvr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hil/UltrasonicoDvr.o: ../Sources/hil/UltrasonicoDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hil/UltrasonicoDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hil/UltrasonicoDvr.o"
	@echo 'Finished building: $<'
	@echo ' '


