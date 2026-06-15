# Internetové bankovnictví

### Zpracovali: Petr Tran, Pavel Tomšík

### Požadavky
  - Meson - build systém
  - kompilační nástroje z MINGW2

### Kroky před spuštěním aplikace
  - Instalace build systému Meson z odkazů na konci README
    - lze nainstalovat za pomocí `.msi`, pip3 nebo sestavením git repa přes Python
  - Instalace dev toolsetů MinGW2 také z odkazů

### Build a spuštění aplikace

- buď přes příkazy:

```bash
# v projektové složce
meson setup build
meson compile -C build
cd build && internet-banking.exe
```

- nebo přes 

```bash
./build-run.sh
```

### Využité dependencies
- <h5>sqlitecpp</h5>
- <h5>openssl</h5>

### Odkazy

- [Meson](https://mesonbuild.com/SimpleStart.html#windows1)
- [MinGW2](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain)
