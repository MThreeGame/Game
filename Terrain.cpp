#include "Terrain.h"


/* READ THE IMAGE FROM THE FILE TO CREATE THE EQUIVALENT MATRIX */

Cell Terrain::pixelToCell(unsigned char B, unsigned char G, unsigned char R){
    
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


vector<vector<Cell>> Terrain::readBMP(const char* filename, int& width, int& height)
{
    vector<vector<Cell>> res;

    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 

    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];

    //cout << "width: " << width << endl;
    //cout << "height: " << height << endl;

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
    // apparently the image seems reverse.
    for(int i = height -1; i >= 0; i--){
        vector<Cell> tempVect;
        for (int j = width - 1; j >= 0; j--){
            tempVect.push_back(pixelToCell( data[3 * (i * width + j)],
                                            data[3 * (i * width + j) + 1],
                                            data[3 * (i * width + j) + 2]));
        }
        res.push_back(tempVect);
    }
    return res;
}





// constructor
Terrain::Terrain(){
    int width;
    int height;
    ground = readBMP(pathToImage.c_str(), width, height);
}

// getters
vector<vector<Cell>> Terrain::getGround(){
    return ground;
}


string Terrain::getPathToImage(){
    return pathToImage;
}
