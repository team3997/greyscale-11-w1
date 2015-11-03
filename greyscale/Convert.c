/*
 * Convert.c
 *
 *  Created on: Nov 3, 2015
 *      Author: mikec
 */

#include <stdio.h>

struct BitMap {
	short Signature;
	long Size;
	short Reserved1;
	short Reserved2;
	long Offset;
	long HeaderSize;
	long Width;
	long Height;
	short Planes;
	short BitsPerPixel;
	long CompressionType;
	long DataOfImage;
	long xPixelsPerMeter;
	long yPixelsPerMeter;
	long Colors;
	long Important;
} Header;

int main() {
	FILE *image = fopen("images/bunny.bmp", "rb");

	if (image == NULL) {
		printf("\nInvalid Image\n");
		return 0;
	}
	memset(&Header, 0, sizeof(Header));

	fread(&Header.Signature, 2, 1, image);
	fread(&Header.Size, 4, 1, image);
	fread(&Header.Reserved1, 2, 1, image);
	fread(&Header.Reserved2, 2, 1, image);
	fread(&Header.Offset, 4, 1, image);
	fread(&Header.HeaderSize, 4, 1, image);
	fread(&Header.Width, 4, 1, image);
	fread(&Header.Height, 4, 1, image);
	fread(&Header.Planes, 2, 1, image);
	fread(&Header.BitsPerPixel, 2, 1, image);
	fread(&Header.CompressionType, 4, 1, image);
	fread(&Header.DataOfImage, 4, 1, image);
	fread(&Header.xPixelsPerMeter, 4, 1, image);
	fread(&Header.yPixelsPerMeter, 4, 1, image);
	fread(&Header.Colors, 4, 1, image);
	fread(&Header.Important, 4, 1, image);

	printf("Signature: %d\n", Header.Signature);
	printf("Size: %d\n", Header.Size);
	printf("Reserved1: %d\n", Header.Reserved1);
	printf("Reserved2: %d\n", Header.Reserved2);
	printf("Offset: %d\n", Header.Offset);
	printf("HeaderSize: %d\n", Header.HeaderSize);
	printf("Width: %d\n", Header.Width);
	printf("Height: %d\n", Header.Height);
	printf("Planes: %d\n", Header.Planes);
	printf("BitsPerPixel: %d\n", Header.BitsPerPixel);
	printf("CompressionType: %d\n", Header.CompressionType);
	printf("DataOfImage: %d\n", Header.DataOfImage);
	printf("xPixelsPerMeter: %d\n", Header.xPixelsPerMeter);
	printf("yPixelsPerMeter: %d\n", Header.yPixelsPerMeter);
	printf("Colors: %d\n", Header.Colors);
	printf("Important: %d\n", Header.Important);

	fclose(image);
	return 0;
}

