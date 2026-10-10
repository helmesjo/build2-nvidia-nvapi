#include <string.h>

#include <nvapi_interface.h>
#include <nvShaderExtnEnums.h>

/* The NVAPI declarations only target Windows (see nvapi.h).
 */
#ifdef _WIN32
#  include <nvapi.h>
#  include <NvApiDriverSettings.h>
#endif

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* The interface table maps function names to the IDs that
   * nvapi_QueryInterface() resolves at runtime.
   */
  {
    unsigned int id = 0;
    size_t n = sizeof (nvapi_interface_table) /
               sizeof (nvapi_interface_table[0]);
    size_t i;

    assert (n != 0);

    for (i = 0; i != n; ++i)
    {
      if (strcmp (nvapi_interface_table[i].func, "NvAPI_Initialize") == 0)
      {
        id = nvapi_interface_table[i].id;
        break;
      }
    }

    assert (id == 0x0150e828);
  }

  assert (NV_EXTN_OP_SHFL == 1);

#ifdef _WIN32
  {
    NvAPI_Status s = NVAPI_OK;
    NvAPI_ShortString str;
    NV_DISPLAY_DRIVER_MEMORY_INFO_V1 mi;

    assert (s == 0);
    assert (sizeof (str) == NVAPI_SHORT_STRING_MAX);

    memset (&mi, 0, sizeof (mi));
    mi.version = NV_DISPLAY_DRIVER_MEMORY_INFO_VER_1;
    assert ((mi.version & 0xffff) == sizeof (mi) && (mi.version >> 16) == 1);

    assert (VSYNCMODE_ID == 0x00A879CF);
  }
#endif

  return 0;
}
