import kconfiglib
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent.parent

KCONFIG_FILE = ROOT_DIR / "Kconfig"
CONFIG_FILE = ROOT_DIR / ".config"
OUTPUT_FILE = ROOT_DIR / "build" / "config.cmake"


def main():
    kconf = kconfiglib.Kconfig(str(KCONFIG_FILE))
    kconf.load_config(str(CONFIG_FILE))

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)

    with open(OUTPUT_FILE, "w") as f:
        for symbol in kconf.unique_defined_syms:
            if symbol.type == kconfiglib.BOOL:
                value = "ON" if symbol.tri_value == 2 else "OFF"
                f.write(f"set(CONFIG_{symbol.name} {value})\n")


if __name__ == "__main__":
    main()
