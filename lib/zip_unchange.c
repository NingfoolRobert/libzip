#include <stdlib.h>
#include "zip.h"
#include "zipint.h"



int
zip_unchange(struct zip *zf, int idx)
{
    int ret;
    
    if (idx < 0 || idx >= zf->nentry) {
	zip_err = ZERR_INVAL;
	return -1;
    }

    if (zf->entry[idx].fn_old) {
	free(zf->entry[idx].fn);
	zf->entry[idx].fn = zf->entry[idx].fn_old;
	zf->entry[idx].fn_old = NULL;
    }

    zip_free_meta(zf->entry[idx].ch_meta);
    ret = _zip_unchange_data(zf->entry+idx);
        
    return ret;
}