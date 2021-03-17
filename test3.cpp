#include <iostream>
#include <fstream>
#include <vector>
#include "Cell.h"

using namespace std;

/* WARNING!!!!!
The file must be a bmp of 3 values by pixels, not 4.
*/

// g++ test3.cpp Cell.h   to compile


/*
Let's decide :
DANGER : RED and BLACK
BACKGROUND : BLUE and WHITE
GROUND : everything else
let's define the color this way: (this is arbitrary decision, to accept some little variations)
RED : R > 200, G < 50, B < 50
BLACK : R < 20, G < 20, B < 20 
BLUE : B > 200, G < 30, R < 30
WHITE : R > 240, G > 240, B > 240

*/
Cell pixelToCell(unsigned char B, unsigned char G, unsigned char R){
    
    //cout << (int)R << "/" << (int)G << "/" << (int)B << " ";
    // red
    if(R > 200 &&  G < 50 && B < 50)
        return Cell::DANGER;
    // black
    if(R < 20 && G < 20 && B < 20)
        return Cell::DANGER;
    // blue
    if(R < 30 && G < 30 && B > 200 )
        return Cell::BACKGROUND;
    // white
    if(R > 240 && G > 240 && B > 240)
        return Cell::BACKGROUND;

    return Cell::GROUND;
}


vector<vector<Cell>> readBMP(const char* filename, int& width, int& height)
{
    vector<vector<Cell>> res;

    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 

    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];

    cout << "width: " << width << endl;
    cout << "height: " << height << endl;

    // allocate 3 bytes per pixel
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size];

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f); 
    fclose(f);

    /* in fact this gives (B, G, R) and nor (RGB)
        a pixel is stored in:
        data[3 * (i * width + j)], 
        data[3 * (i * width + j) + 1]
        data[3 * (i * width + j) + 2].*/
    /*
    for(int i = 0; i < height; i ++){
        vector<Cell> tempVect;
        for (int j = 0; j < width; j ++){
            tempVect.push_back(pixelToCell( data[3 * (i * width + j)],
                                            data[3 * (i * width + j) + 1],
                                            data[3 * (i * width + j) + 2]));
        }
        res.push_back(tempVect);
    }*/

    for(int i = height -1; i >= 0; i--){
        vector<Cell> tempVect;
        for (int j = width - 1; j >= 0; j--){
            tempVect.push_back(pixelToCell( data[3 * (i * width + j)],
                                            data[3 * (i * width + j) + 1],
                                            data[3 * (i * width + j) + 2]));
        }
        res.push_back(tempVect);
    }


    /*
    for(i = 0; i < size; i += 3)
    {
            // flip the order of every 3 bytes
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }

    return data;*/
    return res;
}





/* **********************************************************************************************
********         TRYING TO REVERSE, WRITE INTO A FILE TO SEE THE DIFFERENCE       ****************
********                                 USED FOR DEBUG                           ****************
************************************************************************************************ */

struct BmpHeader {
    char bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t sizeOfBitmapFile = 54; // modified after : we add width * height * 3
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;
} bmpHeader;

struct BmpInfoHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 512; // in pixels
    int32_t height = 512; // in pixels
    uint16_t numberOfColorPlanes = 1; // must be 1
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0; // generally ignored
    int32_t horizontalResolution = 96;//3780; // in pixel per meter
    int32_t verticalResolution = 96; //3780; // in pixel per meter
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;
} bmpInfoHeader;

struct Pixel {
    uint8_t blue = 255;
    uint8_t green = 255;
    uint8_t red = 0;
} pixel;


Pixel CellToPixel(Cell cell){
    Pixel pxl;
    if(cell == Cell::GROUND){
        // let's do it GREEN
        pxl.blue = 0;
        pxl.green = 255;
        pxl.red = 0;
        return pxl;
    }
    if(cell == Cell::BACKGROUND){
        // let's have it BLUE
        pxl.blue = 255;
        pxl.green = 0;
        pxl.red = 0;
        return pxl;
    }
    // Here we have a danger. 
    // let's do it RED
    pxl.blue = 0;
    pxl.green = 0;
    pxl.red = 255;
    return pxl;

    
}


int save(string outfile, int width, int height, vector<vector<Cell>> data ) {
    ofstream fout(outfile.c_str(), ios::binary);

    bmpHeader.sizeOfBitmapFile += width * height * 3;
    bmpInfoHeader.width = width;
    bmpInfoHeader.height = height;

    fout.write((char *) &bmpHeader, 14);
    fout.write((char *) &bmpInfoHeader, 40);
    // writing pixel data
    size_t numberOfPixels = bmpInfoHeader.width * bmpInfoHeader.height;
    /*for (int i = 0; i < numberOfPixels; i++) {
        fout.write((char *) &pixel, 3);
    }*/
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++){
            Pixel pxl = CellToPixel(data[i][j]);
            fout.write((char *) &pxl, 3);
        }

    fout.close();

    return 0;
}









/**********************************************************************************************
 *                                   MAIN FUNCTION                                            *
 * ******************************************************************************************* */








int main(){
    int width, height;
    string filename = "images/test3.bmp";
    vector<vector<Cell>> data = readBMP(filename.c_str(), width, height);

    //save("outputImage.bmp", width, height, data);

    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width; j++)
            cout << data[i][j] << " ";
            //printf("%d ", data[i*width + j]);
        cout << endl;   
    }


    return 0;

}