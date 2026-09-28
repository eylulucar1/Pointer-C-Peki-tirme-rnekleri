#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
int main() {
#pragma region ÖR1
	/*İki tam sayı değişkeninin değerlerini, sadece pointer kullanarak (fonksiyon içine referans göndererek) birbirleriyle değiştiren bir program yaz.*/
	void Swap(int* x, int* y) {
		int gecici = *x;
		*x = *y;
		*y = gecici;
	}
	int main() {
		int x, y;
		int* a, * b;
		a = &x; b = &y;
		printf("First Values: x = %d | y= %d", x, y);
		Swap(a, b);
		printf("Last Values: x = %d | y= %d", x, y);
	}
#pragma endregion
#pragma region ÖR2
	/*Elemanları önceden belirlenmiş 5 elemanlı bir tam sayı dizisinin elemanlarının toplamını, dizi indeksleri (dizi[i]) yerine pointer aritmetiği (*(ptr + i)) kullanarak hesapla.*/
	int main() {
		int sayilar[5] = { 1,2,3,4,5 };
		int toplam = 0;
		int i = 0;
		int* psayilar = sayilar;
		while (i < 5) {
			toplam += (*(psayilar + i));
			i++;
		}
		printf("Dizi elemanlarinin toplami: %d", toplam);
	}
#pragma endregion
#pragma region ÖR3
	/*Bir metin (string) içindeki karakter sayısını strlen() kütüphane fonksiyonunu kullanmadan, sadece pointer ile metnin sonundaki \0 karakterine kadar ilerleyerek bulan bir fonksiyon yaz.*/
	void stringLength(char c[]) {
		int length = 0;
		int i;
		for (i = 0; c[i] != NULL; i++) {
			length++;
		}
		printf("String Length = %d", length);
	}
	int main() {
		char text[] = "Hello World!";
		stringLength(text);
	}
#pragma endregion
#pragma region ÖR4
	/* Bir dizinin elemanlarını aynı dizi içinde tersine çeviren bir fonksiyon yaz. Fonksiyon, dizinin başlangıç ve bitiş adreslerini iki farklı pointer */
	/* olarak alıp değerleri karşılıklı olarak değiştirmeli. */
	void reverseArray(int* head, int* last, int length) {
		int i;
		int temp;
		for (i = 0; i < length / 2; i++) {
			temp = *(head + i);
			*(head + i) = *(*last - i);
			*(last - i) = temp;
		}

	}
	int main() {
		int numbersArray[7] = { 1,2,3,4,5,6,7 };
		int* plast = &numbersArray[6], * phead = numbersArray;
		reverseArray(phead, plast, 7);
		for (int i = 0; i < 7; i++) {
			printf("%d ", numbersArray[i]);
		}
	}

#pragma endregion
#pragma region ÖR5
	/*Bir karakter dizisini (string) başka bir karakter dizisine kopyalayan kendi fonksiyonunu yaz. Kopyalama işlemini dizi indeksleri kullanmadan, sadece pointer aritmetiği ile gerçekleştir.*/
	void copyString(char* gercek, char* kopya) {
		int i;
		for (i = 0; gercek[i] != NULL; i++) {
			kopya[i] = gercek[i];
			if (gercek[i + 1] == NULL) {
				kopya[i + 1] = NULL;
			}
		}

	}
	int main() {
		//#include <stdlib.h> gerekir:)
		char txt[] = "merhaba";
		char* ptxt = txt;
		char* pkopy = (char*)malloc(20 * sizeof(char));
		copyString(ptxt, pkopy);
		free(pkopy);
	}
#pragma endregion
#pragma region ÖR6
	/*Kullanıcıdan alınan bir cümledeki sesli ve sessiz harflerin sayısını bulan bir fonksiyon yaz. Fonksiyon, bulduğu bu iki farklı sayısal sonucu pointer kullanarak main fonksiyonuna iletmeli.*/

//#include <string.h> #include <ctype.h> isalpha fonksiyonu için gerekli

	int sesliMi(char harf) {
		// Karakter "aeiouAEIOU" içinde varsa 1 (doğru), yoksa 0 (yanlış) döndürür
		return strchr("aeiouAEIOU", harf) != NULL;
	}

	int sessizMi(char harf) {
		// Hem alfabede bir harf olmalı (isalpha), hem de sesli OLMAMALI (!sesliMi)
		return isalpha(harf) && !sesliMi(harf);
	}
	int* sesliSessiz(char* txt) {
		int sesli = 0, sessiz = 0;
		for (int i = 0; txt[i] != NULL; i++) {
			if (sesliMi(txt[i])) {
				sesli++;
			}
			else if (sessizMi(txt[i])) {
				sessiz++;
			}
		}
		int* sonuclar = (int*)malloc(2 * sizeof(int));
		sonuclar[0] = sesli;
		sonuclar[1] = sessiz;
		return sonuclar;
	}
	int main() {
		char txt[] = "C de ne kolay ders dimi yaaa!!";
		char* ptxt = txt;
		printf("Metin : %s\n", ptxt);
		int* s = sesliSessiz(txt);
		printf("Sesli Harf : %d\n", s[0]);
		printf("Sesli Harf : %d", s[0]);
		free(s);
		return 0;
	}
#pragma endregion
#pragma region ÖR7
	// Verilen bir kelimenin palindrom (tersten okunuşu kendisine eşit) olup olmadığını kontrol eden bir program yaz. 
	// Kontrol işlemini kelimenin başından ve sonundan birbirine doğru ilerleyen iki farklı pointer kullanarak yap.
	int isPalindrome(char* str) {
		char* head = str;
		char* last = str;

		while (*last != '\0') {
			last++;
		}
		last--;

		while (head < last) {
			char h = *head;
			char l = *last;

			if (h >= 'A' && h <= 'Z') h += 32;
			if (l >= 'A' && l <= 'Z') l += 32;

			if (h != l) {
				return 0;
			}

			head++;
			last--;
		}

		return 1;
	}


	int main() {
		char kelime1[] = "Kayak";
		char kelime2[] = "radar";
		char kelime3[] = "yazilim";

		if (isPalindrome(kelime1)) {
			printf("'%s' bir palindromdur.\n", kelime1);
		}
		else {
			printf("'%s' bir palindrom degildir.\n", kelime1);
		}

		if (isPalindrome(kelime2)) {
			printf("'%s' bir palindromdur.\n", kelime2);
		}
		else {
			printf("'%s' bir palindrom degildir.\n", kelime2);
		}

		if (isPalindrome(kelime3)) {
			printf("'%s' bir palindromdur.\n", kelime3);
		}
		else {
			printf("'%s' bir palindrom degildir.\n", kelime3);
		}

		return 0;
	}
#pragma endregion
#pragma region ÖR8
#pragma endregion
#pragma region ÖR9
#pragma endregion
#pragma region ÖR10
#pragma endregion

}