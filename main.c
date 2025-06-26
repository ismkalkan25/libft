/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:25:37 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/25 14:31:14 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdint.h>  // uintptr_t için

int main(void)
{
    int arr[] = {10, 258, 20, 30};
    size_t arr_size = sizeof(arr); // 16 byte
    void *found = memchr(arr, 2, arr_size); // 258 % 256 = 2 (0x02 aranıyor)

    if (found)
    {
        printf("Byte bulundu.\n");

        // Pointer farkını hesapla (bulunan byte'ın dizideki offseti)
        size_t offset = (uintptr_t)found - (uintptr_t)arr;

        // Kalan byte miktarı
        size_t remaining = arr_size - offset;

        // Geriye kalan kısmı byte byte yazdıralım
        unsigned char *p = (unsigned char *)found;
        printf("Bulunan yerden itibaren kalan bellek (byte olarak):\n");
        for (size_t i = 0; i < remaining; i++)
            printf("%02X ", p[i]);
        printf("\n");

        // Eğer kalan kısmı int olarak yazmak istiyorsan:
        int *int_ptr = (int *)found;
        size_t remaining_int = remaining / sizeof(int);
        printf("Bulunan yerden itibaren kalan int'ler:\n");
        for (size_t i = 0; i < remaining_int; i++)
            printf("%d ", int_ptr[i]);
        printf("\n");
    }
    else
    {
        printf("Byte bulunamadı.\n");
    }

    return 0;
}

