import kconfiglib
import menuconfig

kconf = kconfiglib.Kconfig("kconfig")

menuconfig.menuconfig(kconf)
