int firstUniqChar(char* s) {
    int ascii[256]={0};
    int i=0,len;
    while(s[i]!='\0')
    {
        i++;
    }
    len=i;
    for(i=0;i<len;i++)
    {
       ascii[s[i]]++;
    }
    i=0;
    while(ascii[s[i]]!=1&&i<len) i++;
    if(i==len)
       return -1;
    return i;
}
