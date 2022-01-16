void multi(char* num, int t, int len, char* temp) {
    if (t == 0) {
        temp[0] = 0;
        return;
    }
    int i = 0, flag = 0, tmp = 0, j = 0;
    for (i = len - 1; i >= 0; i--) {
        tmp = (num[i] - '0') * t + flag;
        if (tmp >= 10) {
            flag = tmp / 10;
            temp[j++] = '0' + (tmp % 10);
        }
        else {
            flag = 0;
            temp[j++] = '0' + tmp;
        }
    }
    temp[j] = flag ? (flag + '0') : 0;
    return;
}
void reverse(char* s, int len) {
    int i = 0;
    char t = 0;
    for (i = 0; i < len / 2; i++) {
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}
char* multiply(char* num1, char* num2) {
    char* result = (char*)calloc(220, sizeof(char));
    char* temp = (char*)calloc(220, sizeof(char));
    char* temp2 = (char*)calloc(220, sizeof(char));
    result[0] = '0';
    if (num1 == NULL || num2 == NULL || num1[0] == '0' || num2[0] == '0')
        return result;
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int i = 0, t = 0, j = 0, l = 0, k = 0, flag = 0;
    for (i = l2 - 1; i >= 0; i--) {
        for (j = 0; j < l2 - 1 - i; j++)
            temp[j] = '0';
        multi(num1, num2[i] - '0', l1, temp + j);
        j = 0;
        k = 0;
        l = 0;
        while (temp[j] || result[k] || flag) {
            t = flag;
            if (result[k])
                t += (result[k++] - '0');
            if (temp[j])
                t += (temp[j++] - '0');
            if (t >= 10)
                flag = t / 10;
            else
                flag = 0;
            temp2[l++] = ('0' + t % 10);
        }
        temp2[l] = 0;
        memcpy(result, temp2, (l + 1) * sizeof(char));
    }
    reverse(result, l);
    free(temp);
    free(temp2);
    return result;
}
