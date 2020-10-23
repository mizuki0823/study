#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char moji = 'A', m_data, *m_pt;

    m_pt    = &moji;
    m_data  = *m_pt;

    printf("変数mojiのアドレスは%p,内容は%cです\n", m_pt, m_data);
    return 0;
}