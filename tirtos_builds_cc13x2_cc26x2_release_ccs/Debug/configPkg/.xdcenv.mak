#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /Volumes/Storage/shared/ymakohon/ti/projects/simplelink_cc13x2_26x2_sdk_4_30_00_54/source;/Volumes/Storage/shared/ymakohon/ti/projects/simplelink_cc13x2_26x2_sdk_4_30_00_54/kernel/tirtos/packages
override XDCROOT = /Volumes/Storage/shared/ymakohon/ti/xdctools_3_61_02_27_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /Volumes/Storage/shared/ymakohon/ti/projects/simplelink_cc13x2_26x2_sdk_4_30_00_54/source;/Volumes/Storage/shared/ymakohon/ti/projects/simplelink_cc13x2_26x2_sdk_4_30_00_54/kernel/tirtos/packages;/Volumes/Storage/shared/ymakohon/ti/xdctools_3_61_02_27_core/packages;..
HOSTOS = MacOS
endif
