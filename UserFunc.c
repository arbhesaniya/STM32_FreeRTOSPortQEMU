#define NULL ((void*)0)

void* memset(void *dst, int val, unsigned int size ){
    unsigned char *ptr =(unsigned char *)dst;
    unsigned char val_bytes = (unsigned char)val;

    //fill a block of memory byte by byte

    while(size > 0)
    {
        *ptr++=val_bytes;
        size--;
    }
    return dst;
}

void* __memset_chk(void *dst, int val, unsigned int size, unsigned int dst_size) {
    // Check for buffer overflow
    if (size > dst_size) {
        // Buffer overflow detected - in production code, this should abort
        // For now, we'll just return NULL to indicate an error
        return NULL;
    }
    
    // If the check passes, call the regular memset implementation
    return memset(dst, val, size);
}

void memcpy(void *dst, const void *src , unsigned int n )
{
    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;

    while(n != 0){
        *d++ = *s++;
        n--;
    }
    
    // return dst;
}