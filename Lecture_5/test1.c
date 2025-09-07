#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hàm đảo ngược chuỗi
void reverseString(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Hàm cộng hai số lớn (dưới dạng chuỗi)
char* addStrings(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char *result = (char*)malloc(max_len + 2); // +1 cho carry, +1 cho null
    int carry = 0, k = 0;

    // Đảo ngược chuỗi để xử lý từ chữ số thấp đến cao
    reverseString(a, len_a);
    reverseString(b, len_b);

    for (int i = 0; i < max_len; i++) {
        int sum = carry;
        if (i < len_a) sum += a[i] - '0';
        if (i < len_b) sum += b[i] - '0';
        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) result[k++] = carry + '0';
    result[k] = '\0';

    // Đảo ngược lại kết quả
    reverseString(result, k);
    reverseString(a, len_a); // Khôi phục chuỗi gốc
    reverseString(b, len_b);
    return result;
}

// Hàm trừ hai số lớn (a >= b)
char* subtractStrings(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char *result = (char*)malloc(len_a + 1);
    int borrow = 0, k = 0;

    reverseString(a, len_a);
    reverseString(b, len_b);

    for (int i = 0; i < len_a; i++) {
        int diff = (a[i] - '0') - borrow;
        if (i < len_b) diff -= (b[i] - '0');
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k++] = diff + '0';
    }

    // Xóa các số 0 thừa ở đầu
    while (k > 1 && result[k - 1] == '0') k--;
    result[k] = '\0';

    reverseString(result, k);
    reverseString(a, len_a);
    reverseString(b, len_b);
    return result;
}

// Hàm nhân một chữ số
char* multiplySingleDigit(char *num, int digit) {
    int len = strlen(num);
    char *result = (char*)malloc(len + 2);
    int carry = 0, k = 0;

    reverseString(num, len);
    for (int i = 0; i < len; i++) {
        int prod = (num[i] - '0') * digit + carry;
        result[k++] = (prod % 10) + '0';
        carry = prod / 10;
    }
    if (carry) result[k++] = carry + '0';
    result[k] = '\0';

    reverseString(result, k);
    reverseString(num, len);
    return result;
}

// Hàm thêm số 0 vào cuối chuỗi (tương đương nhân 10^k)
char* shiftLeft(char *num, int k) {
    int len = strlen(num);
    char *result = (char*)malloc(len + k + 1);
    strcpy(result, num);
    for (int i = 0; i < k; i++) {
        result[len + i] = '0';
    }
    result[len + k] = '\0';
    return result;
}

// Hàm Karatsuba
char* karatsuba(char *x, char *y) {
    int len_x = strlen(x);
    int len_y = strlen(y);
    int n = len_x > len_y ? len_x : len_y;

    // Thêm số 0 để đảm bảo độ dài bằng nhau
    char *a = (char*)malloc(n + 1);
    char *b = (char*)malloc(n + 1);
    memset(a, '0', n); a[n] = '\0';
    memset(b, '0', n); b[n] = '\0';
    strncpy(a + (n - len_x), x, len_x);
    strncpy(b + (n - len_y), y, len_y);

    // Trường hợp cơ sở: nếu số có 1 chữ số
    if (n == 1) {
        char *result = multiplySingleDigit(a, b[0] - '0');
        free(a);
        free(b);
        return result;
    }

    // Chia đôi
    int half = (n + 1) / 2;
    char *a1 = (char*)malloc(half + 1);
    char *a2 = (char*)malloc(n - half + 1);
    char *b1 = (char*)malloc(half + 1);
    char *b2 = (char*)malloc(n - half + 1);

    strncpy(a1, a, half); a1[half] = '\0';
    strncpy(a2, a + half, n - half); a2[n - half] = '\0';
    strncpy(b1, b, half); b1[half] = '\0';
    strncpy(b2, b + half, n - half); b2[n - half] = '\0';

    // Tính p1 = a1 * b1, p2 = a2 * b2, p3 = (a1 + a2) * (b1 + b2)
    char *sum_a = addStrings(a1, a2);
    char *sum_b = addStrings(b1, b2);
    char *p1 = karatsuba(a1, b1);
    char *p2 = karatsuba(a2, b2);
    char *p3 = karatsuba(sum_a, sum_b);

    // Tính a1*b2 + a2*b1 = p3 - p1 - p2
    char *temp = subtractStrings(p3, p1);
    char *ad_bc = subtractStrings(temp, p2);

    // Kết hợp: p1 * 10^(2*half) + (p3 - p1 - p2) * 10^half + p2
    char *term1 = shiftLeft(p1, 2 * half);
    char *term2 = shiftLeft(ad_bc, half);
    char *temp_result = addStrings(term1, term2);
    char *result = addStrings(temp_result, p2);

    // Giải phóng bộ nhớ
    free(a); free(b); free(a1); free(a2); free(b1); free(b2);
    free(sum_a); free(sum_b); free(p1); free(p2); free(p3);
    free(temp); free(ad_bc); free(term1); free(term2); free(temp_result);

    // Xóa số 0 thừa ở đầu
    int len_result = strlen(result);
    int start = 0;
    while (start < len_result - 1 && result[start] == '0') start++;
    char *final_result = (char*)malloc(len_result - start + 1);
    strcpy(final_result, result + start);
    free(result);
    return final_result;
}

// Hàm main để kiểm tra
int main() {
    // Hai số 100 chữ số (ví dụ)
    char x[] = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789087943265945894";
    char y[] = "987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321049835798349834";

    char *result = karatsuba(x, y);
    printf("Tich: %s\n", result);
    free(result);
    return 0;
}