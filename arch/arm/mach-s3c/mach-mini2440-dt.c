/**
 * Friendlyarm MINI2440 flattened device tree enabled machine
**/

#include <linux/clocksource.h>
#include <linux/irqchip.h>
#include <linux/serial_s3c.h>

#include <asm/mach/arch.h>
#include "map.h"

#include "cpu.h"
#include "pm.h"

#include "s3c24xx.h"

static void __init mini2440_dt_map_io(void)
{
	s3c24xx_init_io(NULL, 0);
}

static void __init mini2440_dt_machine_init(void)
{
	s3c_pm_init();
}

static const char *const mini2440_dt_compat[] __initconst = {
	"samsung,mini2440",
	"samsung,s3c2440",
	NULL
};

DT_MACHINE_START(MINI2440_DT, "Friendlyarm MINI2440 (Flattened Device Tree)")
	.dt_compat	= mini2440_dt_compat,
	.map_io		= mini2440_dt_map_io,
	.init_irq	= irqchip_init,
	.init_machine	= mini2440_dt_machine_init,
MACHINE_END
