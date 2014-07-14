################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/filemonitor/gdt_changedobserver.cpp \
../src/filemonitor/gdt_filemonitor.cpp \
../src/filemonitor/gdt_transferaction.cpp \
../src/filemonitor/gdt_writefileaction.cpp 

OBJS += \
./src/filemonitor/gdt_changedobserver.o \
./src/filemonitor/gdt_filemonitor.o \
./src/filemonitor/gdt_transferaction.o \
./src/filemonitor/gdt_writefileaction.o 

CPP_DEPS += \
./src/filemonitor/gdt_changedobserver.d \
./src/filemonitor/gdt_filemonitor.d \
./src/filemonitor/gdt_transferaction.d \
./src/filemonitor/gdt_writefileaction.d 


# Each subdirectory must supply rules for building sources it contributes
src/filemonitor/%.o: ../src/filemonitor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/boost -I/usr/local/include/yaml-cpp -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


