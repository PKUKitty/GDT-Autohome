################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gdt_configure.cpp \
../src/gdt_file_util.cpp \
../src/gdt_main.cpp \
../src/gdt_memorypool.cpp 

OBJS += \
./src/gdt_configure.o \
./src/gdt_file_util.o \
./src/gdt_main.o \
./src/gdt_memorypool.o 

CPP_DEPS += \
./src/gdt_configure.d \
./src/gdt_file_util.d \
./src/gdt_main.d \
./src/gdt_memorypool.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/local/include/yaml-cpp -I/usr/local/include/boost -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


