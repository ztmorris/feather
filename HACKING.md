# Documentation for developers

Feather is developed primarily on Linux, but can also be built and debugged on macOS. Development on Windows is not 
currently supported. 

## Setting up a development environment

### Dependencies

Note: Feather uses Qt 5.15.* or Qt 6.2+. Make sure your distro's package manager provides these versions. 
If not, it is recommended that you install Qt manually using the online installer, which can be found here:
https://www.qt.io/download (under open-source).

#### Arch Linux

```bash
pacman -S git cmake base-devel ccache unbound boost qrencode zbar qt6-base qt6-svg qt6-websockets qt6-multimedia libzip hidapi protobuf
```

#### Ubuntu 22.04

```bash
apt update
apt install git cmake build-essential ccache libssl-dev libunbound-dev libboost-all-dev libqrencode-dev libzbar-dev \
    qt6-base-dev libgl1-mesa-dev libqt6svg6-dev libqt6websockets6-dev libzip-dev libsodium-dev libgcrypt-dev \
    libx11-xcb-dev libprotobuf-dev libhidapi-dev
```

#### macOS

For macOS it's easiest to leverage [brew](https://brew.sh) to install the required dependencies.

```bash
brew install qt libsodium libzip qrencode unbound cmake boost hidapi openssl expat libunwind-headers protobuf pkgconfig zbar
```

### Tor daemon

A Tor daemon is required to connect to .onion nodes and the websocket server. Development builds do not include 
the Tor binary by default, this can be enabled with `-DTOR_DIR=/path/to/tor`. We recommend running a local Tor daemon 
as this prevents Feather from spawning a child process and saves time.

#### Arch Linux

```bash
pacman -S tor
systemctl enable --now tor
```

#### Ubuntu Debian

```bash
apt update && apt install tor
systemctl enable --now tor
```

#### macOS

```bash
brew install tor
brew services restart tor
```

### Clone Feather

```bash
git clone http://github.com/feather-wallet/feather.git
cd feather
git submodule update --init --recursive
```

### Jetbrains Clion (IDE)

We recommend using Jetbrains Clion for Feather development. It integrates nicely with CMake and comes with a built-in
debugger. 

To pass CMake flags to CLion, go to `File->Settings->Build->CMake`, set Build Type to `Debug` and set your
preferred CMake options. If you installed Qt using the online installer you may have to add 
`-DCMAKE_PREFIX_PATH=/path/to/qt/installation` in the CMake options. More CMake options are documented below.

Run CMake (`View -> Tool Windows -> CMake`). Click on the 🔃 (`Reload CMake Project`) button.

Go to `Run -> Edit configurations` and make sure the `feather` target is selected. 
You can add any environment variables and program arguments here:

- For more verbose logging add `MONERO_LOG_LEVEL=1` to environment variables.
- To start Feather in stagenet mode, add `--stagenet` to program arguments. 

After the target is configured, `Run -> Run 'feather'` or press Shift + F10 to build Feather.

### Building without IDE

To build Feather without an IDE:

```bash
mkdir build && \
cd build && \
cmake .. && \
cmake --build . -j $(nproc)
```

### CMake

There are some CMake options that you may pass to control how Feather is built:

- `-DLOCALMONERO=OFF` - disable LocalMonero feature
- `-DXMRIG=OFF` - disable XMRig feature
- `-DCHECK_UPDATES=ON` - enable checking for updates, only for standalone binaries
- `-DDONATE_BEG=OFF` - disable the dreaded donate requests
- `-DUSE_DEVICE_TREZOR=OFF` - disable Trezor hardware wallet support
- `-DWITH_SCANNER=ON` - enable the webcam QR code scanner
- `-DTOR_DIR=/path/to/tor/` - embed a Tor binary in Feather, argument should be a directory containing the binary
