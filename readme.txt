command:
arm-none-eabi-gdb OpImage_BC.axf -ex "set target-charset ASCII" -ex "target remote | CrashDebug --elf OpImage_BC.axf --dump BC_MainCrashDump.txt"
arm-none-eabi-gdb OpImage_IM.axf -ex "set target-charset ASCII" -ex "target remote | CrashDebug --elf OpImage_IM.axf --dump IM_MainCrashDump.txt"