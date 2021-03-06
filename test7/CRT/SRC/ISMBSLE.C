/***
*ismbslead.c - True _ismbslead function
*
*       Copyright (c) 1985-1997, Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       Contains the function _ismbslead, which is a true context-sensitive
*       MBCS lead-byte function.  While much less efficient than _ismbblead,
*       it is also much more sophisticated, in that it determines whether a
*       given sub-string pointer points to a lead byte or not, taking into
*       account the context in the string.
*
*******************************************************************************/

#ifdef _MBCS

#include <mtdll.h>
#include <cruntime.h>
#include <stddef.h>
#include <mbdata.h>
#include <mbctype.h>
#include <mbstring.h>


/***
* int _ismbslead(const unsigned char *string, const unsigned char *current);
*
*Purpose:
*
*       _ismbslead - Check, in context, for MBCS lead byte
*
*Entry:
*       unsigned char *string   - ptr to start of string or previous known lead byte
*       unsigned char *current  - ptr to position in string to be tested
*
*Exit:
*       TRUE    : -1
*       FALSE   : 0
*
*Exceptions:
*
*******************************************************************************/

int __cdecl _ismbslead(
        const unsigned char *string,
        const unsigned char *current
        )
{
        if ( _ISNOTMBCP )
            return 0;

        _mlock(_MB_CP_LOCK);

        while (string <= current && *string) {
                if (_ISLEADBYTE((*string))) {
                        if (string++ == current)        /* check lead byte */
                {
                    _munlock(_MB_CP_LOCK);
                                return -1;
                }
                        if (!(*string))
                {
                    _munlock(_MB_CP_LOCK);
                                return 0;
                }
                }
                ++string;
        }

        _munlock(_MB_CP_LOCK);
        return 0;
}

#endif  /* _MBCS */
