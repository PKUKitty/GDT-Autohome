################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/transfer/gdt_asynsender.cpp \
../src/transfer/gdt_filereceiver.cpp \
../src/transfer/gdt_receiver.cpp \
../src/transfer/gdt_sender.cpp \
../src/transfer/gdt_synsender.cpp 

OBJS += \
./src/transfer/gdt_asynsender.o \
./src/transfer/gdt_filereceiver.o \
./src/transfer/gdt_receiver.o \
./src/transfer/gdt_sender.o \
./src/transfer/gdt_synsender.o 

CPP_DEPS += \
./src/transfer/gdt_asynsender.d \
./src/transfer/gdt_filereceiver.d \
./src/transfer/gdt_receiver.d \
./src/transfer/gdt_sender.d \
./src/transfer/gdt_synsender.d 


# Each subdirectory must supply rules for building sources it contributes
src/transfer/%.o: ../src/transfer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/local/include/yaml-cpp -I/usr/local/include/boost -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


