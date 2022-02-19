#include <headfile.h>
#include <config.h>
#include <dat.h>

void Interrupt_setPriority(uint32 interruptNumber, uint8 priority)
{
		NVIC->IP[interruptNumber] = (NVIC->IP[interruptNumber] & 0x00ff)|priority;
}