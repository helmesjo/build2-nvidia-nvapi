# libnvapi - The C headers for NVAPI, NVIDIA's API for GPU and driver features

This is a `build2` package for the [`nvapi`](https://github.com/NVIDIA/nvapi)
C library. It provides the public headers of the NVAPI SDK, NVIDIA's API for
accessing GPU and driver features on systems with NVIDIA hardware. The actual
NVAPI implementation is provided by the NVIDIA GPU driver installed on the
system.


## Usage

To start using `libnvapi` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvapi >= 615.0.0
```

Then import the library in your `buildfile`:

```
import libs = libnvapi%lib{nvapi}
```


## Importable targets

This package provides the following importable targets:

```
lib{nvapi}
```

The NVAPI SDK headers, included without a subdirectory prefix
(`#include <nvapi.h>`, `#include <nvapi_interface.h>`, and so on). The
package version is the NVIDIA driver release of the SDK (`615.0.0` is R615).

This package is headers only. It does not provide the prebuilt static
libraries from the SDK (`nvapi.lib`, `nvapi64.lib`, and the ARM64 variants),
so the `NvAPI_*` functions declared in `nvapi.h` cannot be linked against.
The interface table in `nvapi_interface.h` maps each function name to the ID
that the driver's `nvapi_QueryInterface()` entry point resolves at runtime.
The driver settings value tables from upstream's `NvApiDriverSettings.c` are
not included either.

As in upstream, `nvapi.h` and `NvApiDriverSettings.h` target Windows, and
`nvHLSLExtns.h` (with the headers it includes) is for HLSL shader code. On
MinGW, which has no Microsoft SAL annotations, the package defines upstream's
`__NVAPI_EMPTY_SAL` for consumers.


## Configuration variables

This package provides no configuration variables.
