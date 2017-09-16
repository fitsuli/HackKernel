#############################################################################
#			INTERPEAK MAKEFILE
#
#     Document no: @(#) $Name: VXWORKS_ITER18A_FRZ10 $ $RCSfile: ipcom_arm.mk,v $ $Revision: 1.2 $
#     $Source: /home/interpeak/CVSRoot/ipcom/arch/arm/gmake/ipcom_arm.mk,v $
#     $Author: kenneth $
#     $State: Exp $ $Locker:  $
#
#     INTERPEAK_COPYRIGHT_STRING
#
#############################################################################
IPCOM_ARCH := yes

#############################################################################
# DESCRIPTION
#############################################################################
# IPCOM ARM arch GNU makefile template.


#############################################################################
# IPDEFINE
#############################################################################

IPDEFINE	+= -DIPCOM_USE_ASM


#############################################################################
# FILE
#############################################################################

IPLIBOBJECTS	+= ipcom_arm.o


#############################################################################
# DEPENDENCIES
#############################################################################

IPASDIRS += $(IPCOM_ROOT)/arch/arm/src


#############################################################################
# END OF ipcom_arm.mk
#############################################################################

