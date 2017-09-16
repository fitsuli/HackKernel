
#ifndef __HISI_SOC_IRQS_H__
#define __HISI_SOC_IRQS_H__ 



#define IRQ_LOCALTIMER 29
#define IRQ_LOCALWDOG 30

#define IRQ_GIC_START 32

#define IRQ_IPF0 (IRQ_GIC_START + 0)
#define IRQ_IPF1 (IRQ_GIC_START + 1)
#define IRQ_SOCP0 (IRQ_GIC_START + 2)
#define IRQ_SOCP1 (IRQ_GIC_START + 3)
#define IRQ_SC_VOTE (IRQ_GIC_START + 4)
#define IRQ_PD_VOTE (IRQ_GIC_START + 5)
#define IRQ_PMCTRL (IRQ_GIC_START + 6)
#define IRQ_TSENSOR0 (IRQ_GIC_START + 7)
#define IRQ_RTC1 (IRQ_GIC_START + 8)
#define IRQ_IPC0 (IRQ_GIC_START + 9)
#define IRQ_IPC1 (IRQ_GIC_START + 10)
#define IRQ_IPC2 (IRQ_GIC_START + 11)
#define IRQ_RTC (IRQ_GIC_START + 12)
#define IRQ_WD0 (IRQ_GIC_START + 13)
#define IRQ_TIMER0 (IRQ_GIC_START + 14)
#define IRQ_TIMER1 (IRQ_GIC_START + 15)
#define IRQ_TIMER2 (IRQ_GIC_START + 16)
#define IRQ_TIMER3 (IRQ_GIC_START + 17)
#define IRQ_TIMER4 (IRQ_GIC_START + 18)
#define IRQ_TIMER5 (IRQ_GIC_START + 19)
#define IRQ_TIMER6 (IRQ_GIC_START + 20)
#define IRQ_TIMER7 (IRQ_GIC_START + 21)
#define IRQ_TIMER8 (IRQ_GIC_START + 22)
#define IRQ_TIMER9 (IRQ_GIC_START + 23)
#define IRQ_TIMER10 (IRQ_GIC_START + 24)
#define IRQ_TIMER11 (IRQ_GIC_START + 25)
#define IRQ_TIMER12 (IRQ_GIC_START + 26)
#define IRQ_TIMER13 (IRQ_GIC_START + 27)
#define IRQ_TIMER14 (IRQ_GIC_START + 28)
#define IRQ_TIMER15 (IRQ_GIC_START + 29)
#define IRQ_TIMER16 (IRQ_GIC_START + 30)
#define IRQ_TIMER17 (IRQ_GIC_START + 31)
#define IRQ_CM3TIMER0 (IRQ_GIC_START + 32)
#define IRQ_CM3TIMER1 (IRQ_GIC_START + 33)
#define IRQ_CM3TIMER2 (IRQ_GIC_START + 34)
#define IRQ_CM3TIMER3 (IRQ_GIC_START + 35)
#define IRQ_UART0 (IRQ_GIC_START + 36)
#define IRQ_UART1 (IRQ_GIC_START + 37)
#define IRQ_UART2 (IRQ_GIC_START + 38)
#define IRQ_UART3 (IRQ_GIC_START + 39)
#define IRQ_UART4 (IRQ_GIC_START + 40)
#define IRQ_CCI_EVNTCNTOVERFLOW (IRQ_GIC_START + 41)
#define IRQ_SYS_NOC_ERROR (IRQ_GIC_START + 42)
#define IRQ_MEDIA_NOC_ERROR (IRQ_GIC_START + 43)
#define IRQ_I2C0 (IRQ_GIC_START + 44)
#define IRQ_I2C1 (IRQ_GIC_START + 45)
#define IRQ_I2C2 (IRQ_GIC_START + 46)
#define IRQ_I2C3 (IRQ_GIC_START + 47)
#define IRQ_DDRT (IRQ_GIC_START + 48)
#define IRQ_MEDIA_NOC_ALARM (IRQ_GIC_START + 49)
#define IRQ_SSP0 (IRQ_GIC_START + 50)
#define IRQ_SYS_NOC_ALARM (IRQ_GIC_START + 51)
#define IRQ_GPIO0 (IRQ_GIC_START + 52)
#define IRQ_GPIO1 (IRQ_GIC_START + 53)
#define IRQ_GPIO2 (IRQ_GIC_START + 54)
#define IRQ_GPIO3 (IRQ_GIC_START + 55)
#define IRQ_GPIO4 (IRQ_GIC_START + 56)
#define IRQ_GPIO5 (IRQ_GIC_START + 57)
#define IRQ_GPIO6 (IRQ_GIC_START + 58)
#define IRQ_GPIO7 (IRQ_GIC_START + 59)
#define IRQ_GPIO8 (IRQ_GIC_START + 60)
#define IRQ_GPIO9 (IRQ_GIC_START + 61)
#define IRQ_GPIO10 (IRQ_GIC_START + 62)
#define IRQ_GPIO11 (IRQ_GIC_START + 63)
#define IRQ_GPIO12 (IRQ_GIC_START + 64)
#define IRQ_GPIO13 (IRQ_GIC_START + 65)
#define IRQ_GPIO14 (IRQ_GIC_START + 66)
#define IRQ_GPIO15 (IRQ_GIC_START + 67)
#define IRQ_GPIO16 (IRQ_GIC_START + 68)
#define IRQ_GPIO17 (IRQ_GIC_START + 69)
#define IRQ_GPIO18 (IRQ_GIC_START + 70)
#define IRQ_GPIO19 (IRQ_GIC_START + 71)
#define IRQ_EMMC (IRQ_GIC_START + 72)
#define IRQ_SDMMC (IRQ_GIC_START + 73)
#define IRQ_SDIOMMC (IRQ_GIC_START + 74)
#define IRQ_SCI0 (IRQ_GIC_START + 75)
#define IRQ_SCI1 (IRQ_GIC_START + 76)
#define IRQ_USB2OTG (IRQ_GIC_START + 77)
#define IRQ_USB2OTG_BC (IRQ_GIC_START + 78)
#define IRQ_ADE_SEC (IRQ_GIC_START + 79)
#define IRQ_DDRC (IRQ_GIC_START + 80)
#define IRQ_AEDMAC_SEC (IRQ_GIC_START + 81)
#define IRQ_SECENG (IRQ_GIC_START + 82)

#define IRQ_CLK_MONITOR (IRQ_GIC_START + 83)
#define IRQ_AEDMAC0 (IRQ_GIC_START + 84)
#define IRQ_BBE16_BPIO0 (IRQ_GIC_START + 85)
#define IRQ_WD1 (IRQ_GIC_START + 86)
#define IRQ_WD2 (IRQ_GIC_START + 87)
#define IRQ_WD3 (IRQ_GIC_START + 88)
#define IRQ_CM3WD0 (IRQ_GIC_START + 89)
#define IRQ_CM3WD1 (IRQ_GIC_START + 90)
#define IRQ_CS_ETR (IRQ_GIC_START + 91)

#define IRQ_CCI_ERR (IRQ_GIC_START + 92)
#define IRQ_DDRC_INT (IRQ_GIC_START + 93)
#define IRQ_IPC0_S (IRQ_GIC_START + 94)
#define IRQ_IPC1_S (IRQ_GIC_START + 95)

#define IRQ_NANDC (IRQ_GIC_START + 96)
#define IRQ_LTE_ARM_PUB_INT (IRQ_GIC_START + 97)
#define IRQ_LTE_APP_ARM_PUB_INT (IRQ_GIC_START + 98)
#define IRQ_PMU (IRQ_GIC_START + 99)
#define IRQ_CLUSTER0_AXI_ERR (IRQ_GIC_START + 100)
#define IRQ_CLUSTER1_AXI_ERR (IRQ_GIC_START + 101)
#define IRQ_RESERVED102 (IRQ_GIC_START + 102)
#define IRQ_CTI (IRQ_GIC_START + 103)
#define IRQ_RESERVED104 (IRQ_GIC_START + 104)
#define IRQ_RESERVED105 (IRQ_GIC_START + 105)
#define IRQ_RESERVED106 (IRQ_GIC_START + 106)
#define IRQ_RESERVED107 (IRQ_GIC_START + 107)
#define IRQ_COMM_RXTX (IRQ_GIC_START + 108)
#define IRQ_ACPU_SOFT_FIQ (IRQ_GIC_START + 109)
#define IRQ_G3D (IRQ_GIC_START + 110)
#define IRQ_VDEC (IRQ_GIC_START + 111)
#define IRQ_JPEG (IRQ_GIC_START + 112)
#define IRQ_MMU (IRQ_GIC_START + 113)
#define IRQ_ADE (IRQ_GIC_START + 114)
#define IRQ_ADE_LDI (IRQ_GIC_START + 115)
#define IRQ_MIPI_DSI (IRQ_GIC_START + 116)
#define IRQ_PWM0 (IRQ_GIC_START + 117)
#define IRQ_PMM1 (IRQ_GIC_START + 118)
#define IRQ_PWMIN (IRQ_GIC_START + 119)
#define IRQ_ISP (IRQ_GIC_START + 120)
#define IRQ_MIPI_CSI0 (IRQ_GIC_START + 121)
#define IRQ_MIPI_CSI1 (IRQ_GIC_START + 122)
#define IRQ_DIGACODEC (IRQ_GIC_START + 123)
#define IRQ_CLUSTER0_IRQFIQOUT_CORE0 (IRQ_GIC_START + 124)
#define IRQ_CLUSTER1_IRQFIQOUT_CORE0 (IRQ_GIC_START + 125)
#define IRQ_RESERVED126 (IRQ_GIC_START + 126)
#define IRQ_RESERVED127 (IRQ_GIC_START + 127)
#define NR_SOC_IRQS (IRQ_GIC_START + 128)
#endif
