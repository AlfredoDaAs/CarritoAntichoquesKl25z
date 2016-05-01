################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/hal/ADC.c" \
"../Sources/hal/GPIO.c" \
"../Sources/hal/PORTCfgs.c" \
"../Sources/hal/TIMER.c" \
"../Sources/hal/lptmr.c" \
"../Sources/hal/mcg.c" \
"../Sources/hal/nvic.c" \
"../Sources/hal/sysinit.c" \
"../Sources/hal/tpm.c" \
"../Sources/hal/tpm_hc-sr04.c" \

C_SRCS += \
../Sources/hal/ADC.c \
../Sources/hal/GPIO.c \
../Sources/hal/PORTCfgs.c \
../Sources/hal/TIMER.c \
../Sources/hal/lptmr.c \
../Sources/hal/mcg.c \
../Sources/hal/nvic.c \
../Sources/hal/sysinit.c \
../Sources/hal/tpm.c \
../Sources/hal/tpm_hc-sr04.c \

OBJS += \
./Sources/hal/ADC.o \
./Sources/hal/GPIO.o \
./Sources/hal/PORTCfgs.o \
./Sources/hal/TIMER.o \
./Sources/hal/lptmr.o \
./Sources/hal/mcg.o \
./Sources/hal/nvic.o \
./Sources/hal/sysinit.o \
./Sources/hal/tpm.o \
./Sources/hal/tpm_hc-sr04.o \

C_DEPS += \
./Sources/hal/ADC.d \
./Sources/hal/GPIO.d \
./Sources/hal/PORTCfgs.d \
./Sources/hal/TIMER.d \
./Sources/hal/lptmr.d \
./Sources/hal/mcg.d \
./Sources/hal/nvic.d \
./Sources/hal/sysinit.d \
./Sources/hal/tpm.d \
./Sources/hal/tpm_hc-sr04.d \

OBJS_QUOTED += \
"./Sources/hal/ADC.o" \
"./Sources/hal/GPIO.o" \
"./Sources/hal/PORTCfgs.o" \
"./Sources/hal/TIMER.o" \
"./Sources/hal/lptmr.o" \
"./Sources/hal/mcg.o" \
"./Sources/hal/nvic.o" \
"./Sources/hal/sysinit.o" \
"./Sources/hal/tpm.o" \
"./Sources/hal/tpm_hc-sr04.o" \

C_DEPS_QUOTED += \
"./Sources/hal/ADC.d" \
"./Sources/hal/GPIO.d" \
"./Sources/hal/PORTCfgs.d" \
"./Sources/hal/TIMER.d" \
"./Sources/hal/lptmr.d" \
"./Sources/hal/mcg.d" \
"./Sources/hal/nvic.d" \
"./Sources/hal/sysinit.d" \
"./Sources/hal/tpm.d" \
"./Sources/hal/tpm_hc-sr04.d" \

OBJS_OS_FORMAT += \
./Sources/hal/ADC.o \
./Sources/hal/GPIO.o \
./Sources/hal/PORTCfgs.o \
./Sources/hal/TIMER.o \
./Sources/hal/lptmr.o \
./Sources/hal/mcg.o \
./Sources/hal/nvic.o \
./Sources/hal/sysinit.o \
./Sources/hal/tpm.o \
./Sources/hal/tpm_hc-sr04.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/hal/ADC.o: ../Sources/hal/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/GPIO.o: ../Sources/hal/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/GPIO.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/PORTCfgs.o: ../Sources/hal/PORTCfgs.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/PORTCfgs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/PORTCfgs.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/TIMER.o: ../Sources/hal/TIMER.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/TIMER.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/TIMER.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/lptmr.o: ../Sources/hal/lptmr.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/lptmr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/lptmr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/mcg.o: ../Sources/hal/mcg.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/mcg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/mcg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/nvic.o: ../Sources/hal/nvic.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/nvic.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/nvic.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/sysinit.o: ../Sources/hal/sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/sysinit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/sysinit.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/tpm.o: ../Sources/hal/tpm.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/tpm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/tpm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/hal/tpm_hc-sr04.o: ../Sources/hal/tpm_hc-sr04.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/hal/tpm_hc-sr04.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/hal/tpm_hc-sr04.o"
	@echo 'Finished building: $<'
	@echo ' '


