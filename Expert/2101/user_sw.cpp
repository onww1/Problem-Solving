void test(unsigned char* FREQ, const unsigned char* BITMAP) {
    unsigned char bit_to_val[256]{};
    for (int shift = 0; shift < 8; shift++) 
        bit_to_val[0x80 >> shift] = shift;

    for (int i = 0; i < 1000000; i++)
        FREQ[i] = 'J';

    for (int y = 0; y < 6000; y++) {
        for (int x = 0; x < 750; x++) {
            unsigned char val = BITMAP[y * 750 + x];
            unsigned char prv = val;
            while (val) {
                prv = val;
                val &= (val - 1);
                unsigned char bit = prv - val;
                int xval = 999 - ((x << 3) | bit_to_val[bit]) / 6;
                int yval = 999 - y / 6;
                FREQ[yval * 1000 + xval]++;
            }
        }
    }
}

void comp(unsigned char* COMP, const unsigned char* FREQ) {
    
}

void decomp(unsigned char* FREQ, const unsigned char* COMP) {

}